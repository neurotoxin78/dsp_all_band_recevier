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

// #include <freertos/timers.h>
#define AUTO_RESET_ENCODER_MODE_PERIOD pdMS_TO_TICKS(5000)

TimerHandle_t xAutoResetEncoderModeTimer;
BaseType_t xAutoResetEncoderModeTimerStarted;

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
  xTaskCreatePinnedToCore(encoder_Task, "Encoder", 2048, NULL, 1, &encoder_TaskHandler, 0);
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

  for (;;)
  {
    vTaskDelay(100 / portTICK_PERIOD_MS);
  }
  vTaskDelete(NULL);
}

void encoder_Task(void *parameter)
{
  enc1.setType(TYPE2);
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
    enc1.tick();
    if (enc1.isRight())
    {
      switch (current_encoder_mode)
      {
      case 0:
        rx.volumeUp();
        updateVolume();
        break;
      case 1:
        stopAutoResetEncoderModeTimer();
        rx.frequencyUp();
        updateFrequency();
        startAutoResetEncoderModeTimer();
        break;
      case 2:
        stopAutoResetEncoderModeTimer();
        changeStep();
        startAutoResetEncoderModeTimer();
        break;
      default:
        break;
      }
    }
    if (enc1.isLeft())
    {
      switch (current_encoder_mode)
      {
      case 0:
        rx.volumeDown();
        updateVolume();
        break;
      case 1:
        stopAutoResetEncoderModeTimer();
        rx.frequencyDown();
        updateFrequency();
        startAutoResetEncoderModeTimer();
        break;
      case 2:
        stopAutoResetEncoderModeTimer();
        changeStep();
        startAutoResetEncoderModeTimer();
        break;
      default:
        break;
      }
    }
    if (enc1.isLeftH())
    {
      changeEncoderMode();
    }
    if (enc1.isRightH())
    {
      changeEncoderMode();
    }
    if (enc1.isTurn())
    {
      // Serial.println(encoder_counter);
    }
    if (enc1.isClick())
    {
      if (current_band == 0)
      {
        scanUp();
      }
    }
    if (enc1.isDouble())
    {
      if (current_band == 0)
      {
        rx.setFrequency(8400);
      }
    }
    if (enc1.isHolded())
    {
      changeBand();
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
  receiver_setup();

  for (;;)
  {
    updateFrequency();
    checkRDS();
    void fm_mono_stereo();
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

static void prvAutoResetEncoderModeTimerCallback(TimerHandle_t xTimer)
{
  TickType_t xTimeNow;
  /* Obtain the current tick count. */
  xTimeNow = xTaskGetTickCount();
  /* Output a string to show the time at which the callback was executed. */
  //Serial.print("Auto-reload timer callback executing ");
  //Serial.println(xTimeNow / 31);
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