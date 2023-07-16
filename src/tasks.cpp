#include "main.h"
#include "tasks.h"
#include "lvgl.h"
#include "ui/ui.h"
#include "display.h"
#include <WiFiUdp.h>
#include <NTPClient.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <SI4735.h>
#include "receiver_tools.h"
#include "GyverButton.h"


GButton button_white(BTN_WHITE);
GButton button_blue(BTN_BLUE);
GButton button_yellow(BTN_YELLOW);
GButton button_red(BTN_RED);

// #include <freertos/timers.h>
#define AUTO_RESET_ENCODER_MODE_PERIOD pdMS_TO_TICKS(5000)
#define RDS_PERIOD pdMS_TO_TICKS(10000)
#define INDEV_TICK_PERIOD pdMS_TO_TICKS(10)

TimerHandle_t xAutoResetEncoderModeTimer;
BaseType_t xAutoResetEncoderModeTimerStarted;
TimerHandle_t xRDSTimer;
BaseType_t xRDSTimerStarted;


SI4735 rx;

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);

TaskHandle_t heartbeat_TaskHandler;
TaskHandle_t con_info_TaskHandler;
TaskHandle_t freeMem_TaskHandler;
TaskHandle_t clock_TaskHandler;
TaskHandle_t encoder_TaskHandler;
TaskHandle_t receiver_ctrl_TaskHandler;
TaskHandle_t receiver_info_TaskHandler;

char buffer[100];
uint16_t currentFrequency;
uint16_t previousFrequency;
uint8_t bandwidthIdx = 0;

void runTasks()
{
  xTaskCreatePinnedToCore(heartbeat_Task, "SysHeartbeat", 8192, NULL, 1, &heartbeat_TaskHandler, 0);
  xTaskCreatePinnedToCore(conInfo_Task, "ConnectionInfo", 8192, NULL, 1, &con_info_TaskHandler, 0);
  xTaskCreatePinnedToCore(freeMem_Task, "FreeMem", 8192, NULL, 1, &freeMem_TaskHandler, 0);
  xTaskCreatePinnedToCore(clock_Task, "Clock", 8192, NULL, 1, &clock_TaskHandler, 0);
  xTaskCreatePinnedToCore(encoder_Task, "Encoder", 8192, NULL, 1, &encoder_TaskHandler, 0);
  xTaskCreatePinnedToCore(receiver_ctrl_Task, "Receiver_Control", 4096, NULL, 1, &receiver_ctrl_TaskHandler, 1);
  xTaskCreatePinnedToCore(receiver_info_Task, "Receiver_Info", 8192, NULL, 1, &receiver_info_TaskHandler, 1);
}

int getStrength()
{
  long rssi = WiFi.RSSI();
  long averageRSSI = 0;

  averageRSSI = 2 * (rssi + 100);
  return averageRSSI;
}

void heartbeat_Task(void *parameter)
{
  pinMode(LED, OUTPUT);
  for (;;)
  {
    digitalWrite(LED, LOW);
    vTaskDelay(100 / portTICK_PERIOD_MS);
    digitalWrite(LED, HIGH);
    vTaskDelay(100 / portTICK_PERIOD_MS);
    digitalWrite(LED, LOW);
    vTaskDelay(100 / portTICK_PERIOD_MS);
    digitalWrite(LED, HIGH);
    vTaskDelay(1800 / portTICK_PERIOD_MS);
  }
  vTaskDelete(NULL);
}

void encoder_Task(void *parameter)
{
  setupButtons();
  xAutoResetEncoderModeTimer = xTimerCreate(
      /* Text name for the software timer - not used by FreeRTOS. */
      "AutoReload",
      /* The software timer's period in ticks. */
      AUTO_RESET_ENCODER_MODE_PERIOD,
      /* Setting uxAutoRealod to pdTRUE creates an auto-reload timer. */
      pdTRUE,
      /* This example does not use the timer id. */
      0,
      /* The callback function to be used by the software timer being created. */
      prvAutoResetEncoderModeTimerCallback);

  for (;;)
  {
    if (button_red.isClick())
    {
      changeBand();
    }
    if (button_yellow.isClick())
    {
      changeStep();
    }
    if (button_blue.isClick())
    {
      if (current_band == 0)
      {
        scanUp();
      }
      if (current_band == 3)
      {
        ssbBandwidth();
        updateBandwidth();
      }
      
    }
    if (button_blue.isHold())
    {
      if (current_band == 0)
      {
        scanDown();
      }
      
    }    
    if (button_white.isClick())
    {
      if (current_band == 3)
      {
        changeSSBsubband();
        Serial.println("Subband changed");
      }
      
    }

    if (enc1.isLeft())
    {
      encoderRight();
    }
    if (enc1.isRight())
    {
      encoderLeft();
    }
    if (enc1.isLeftH())
    {
      
    }
    if (enc1.isRightH())
    {
      
    }
    if (enc1.isTurn())
    {
      // Serial.println(encoder_counter);
    }
    if (enc1.isClick())
    {
        //Serial.print("EncoderClick");
        changeEncoderMode();
    }
    if (enc1.isDouble())
    {
        switchBand();
    }
    if (enc1.isHolded())
    {
      
    }
    vTaskDelay(pdMS_TO_TICKS(1));
  }
  vTaskDelete(NULL);
}

void conInfo_Task(void *parameter)
{
  char buffer[100];
  for (;;)
  {
    if (WiFi.status() == WL_CONNECTED)
    {
      sprintf(buffer, "%s %d dBm", WiFi.localIP().toString().c_str(), WiFi.RSSI());
      xSemaphoreTake(lv_update_mutex, portMAX_DELAY);
      lv_label_set_text(ui_StatusBarLeft, buffer);
      xSemaphoreGive(lv_update_mutex);
    }
    else
    {
      xSemaphoreTake(lv_update_mutex, portMAX_DELAY);
      lv_label_set_text(ui_StatusBarLeft, "Disconnected");
      xSemaphoreGive(lv_update_mutex);
    }

    vTaskDelay(1000);
  }
  vTaskDelete(NULL);
}

void freeMem_Task(void *parameter)
{
  char buffer[100];
  uint32_t freeHeap = 0;
  uint32_t freePSRAM = 0;
  for (;;)
  {
    // freeHeap = ESP.getFreeHeap() / 1024;int n = WiFi.scanNetworks();
    freePSRAM = ESP.getFreeHeap() / 1024;
    sprintf(buffer, "RAM %d kB free", freePSRAM);
    xSemaphoreTake(lv_update_mutex, portMAX_DELAY);
    lv_label_set_text(ui_StatusBarRight, buffer);
    xSemaphoreGive(lv_update_mutex);
    vTaskDelay(1000);
  }
  vTaskDelete(NULL);
}

void clock_Task(void *parameter)
{
  timeClient.begin();
  timeClient.setTimeOffset(3600 * 3); // Set time zone (in seconds)
  timeClient.update();                // Get initial time from NTP server
  for (;;)
  {

    timeClient.update(); // Update time from NTP server

    char buf[9];
    sprintf(buf, "%02d:%02d:%02d", timeClient.getHours(), timeClient.getMinutes(), timeClient.getSeconds());
    xSemaphoreTake(lv_update_mutex, portMAX_DELAY);
    lv_label_set_text(ui_clockLabel, buf); // Update label text with current time
    xSemaphoreGive(lv_update_mutex);
    vTaskDelay(250 / portTICK_PERIOD_MS);
  }
  vTaskDelete(NULL);
}

void receiver_ctrl_Task(void *parameter)
{
  xRDSTimer = xTimerCreate(
      /* Text name for the software timer - not used by FreeRTOS. */
      "AutoReload",
      /* The software timer's period in ticks. */
      RDS_PERIOD,
      /* Setting uxAutoRealod to pdTRUE creates an auto-reload timer. */
      pdTRUE,
      /* This example does not use the timer id. */
      0,
      /* The callback function to be used by the software timer being created. */
      prvRDSTimerCallback);
  //xRDSTimerStarted = xTimerStart(xRDSTimer, 0);
  hideRDSPanels();
  startRDSTimer();
  receiver_setup();
  for (;;)
  {
    updateFrequency();
    fm_mono_stereo();
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
  vTaskDelete(NULL);
}

void receiver_info_Task(void *parameter)
{
  char buffer[100];
  for (;;)
  {
    rx.getCurrentReceivedSignalQuality();
    sprintf(buffer, "SQ:%lu dBuV", rx.getCurrentRSSI());
    xSemaphoreTake(lv_update_mutex, portMAX_DELAY);
    lv_label_set_text(ui_rssiLabel, buffer);
    lv_bar_set_value(ui_rssiBar, rx.getCurrentRSSI(), LV_ANIM_OFF);
    xSemaphoreGive(lv_update_mutex);
    sprintf(buffer, "SNR:%lu dB", rx.getCurrentSNR());
    xSemaphoreTake(lv_update_mutex, portMAX_DELAY);
    lv_label_set_text(ui_snrLabel, buffer);
    xSemaphoreGive(lv_update_mutex);
    updateAGC();
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
  vTaskDelete(NULL);
}

void startAutoResetEncoderModeTimer()
{
  xAutoResetEncoderModeTimerStarted = xTimerStart(xAutoResetEncoderModeTimer, 0);
}

void stopAutoResetEncoderModeTimer()
{
  xAutoResetEncoderModeTimerStarted = xTimerStop(xAutoResetEncoderModeTimer, 0);
}

void startRDSTimer()
{
  xRDSTimerStarted = xTimerStart(xRDSTimer, 0);
  showRDSPanels();
}

void stopRDSTimer()
{
  xRDSTimerStarted = xTimerStop(xRDSTimer, 0);
  hideRDSPanels();
}

static void prvRDSTimerCallback(TimerHandle_t xTimer)
{
  
  checkRDS();
}

static void prvAutoResetEncoderModeTimerCallback(TimerHandle_t xTimer)
{
  TickType_t xTimeNow;
  /* Obtain the current tick count. */
  xTimeNow = xTaskGetTickCount();
  /* Output a string to show the time at which the callback was executed. */
  // Serial.print("Auto-reload timer callback executing ");
  // Serial.println(xTimeNow / 31);
  if (current_band == 0)
  {
    if (current_encoder_mode != 0)
    {
      current_encoder_mode = 0;
      updateEncoderMode();
      stopAutoResetEncoderModeTimer();
    }
  }
}


void setupButtons()
{
  button_white.setType(LOW_PULL);
  button_blue.setType(LOW_PULL);
  button_yellow.setType(LOW_PULL);
  button_red.setType(LOW_PULL);
  button_white.setDirection(NORM_OPEN);
  button_blue.setDirection(NORM_OPEN);
  button_yellow.setDirection(NORM_OPEN);
  button_red.setDirection(NORM_OPEN);
  button_white.setTickMode(AUTO);
  button_blue.setTickMode(AUTO);
  button_yellow.setTickMode(AUTO);
  button_red.setTickMode(AUTO);
  button_white.setDebounce(BUTTON_DEBOUNCE_TIME);        // настройка антидребезга (по умолчанию 80 мс)
  button_blue.setDebounce(BUTTON_DEBOUNCE_TIME);
  button_yellow.setDebounce(BUTTON_DEBOUNCE_TIME);
  button_red.setDebounce(BUTTON_DEBOUNCE_TIME);
  button_white.setTimeout(BUTTON_TIMEOUT);
  button_blue.setTimeout(BUTTON_TIMEOUT);
  button_yellow.setTimeout(BUTTON_TIMEOUT);
  button_red.setTimeout(BUTTON_TIMEOUT);  
}
