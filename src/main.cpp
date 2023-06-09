#include <Arduino.h>
#include <lvgl.h>
#include "ui/ui.h"
#include <WiFi.h>
#include "main.h"
#include "tasks.h"
#include "display.h"
#include "GyverEncoder.h"

Encoder enc1(CLK, DT, SW);

static const char *TAG = "esp32s2";
const char *ssid = "Neurotoxin2";
const char *password = "Mxbb2Col";

TimerHandle_t wifiReconnectTimer;
SemaphoreHandle_t lv_update_mutex;

void WiFiEvent(WiFiEvent_t event)
{
  // Serial.printf("[WiFi-event] event: %d\n", event);
  switch (event)
  {
  case SYSTEM_EVENT_STA_GOT_IP:
    Serial.println(WiFi.localIP());
    break;
  case SYSTEM_EVENT_STA_DISCONNECTED:
    Serial.println("WiFi lost connection, reconnect...");
    xTimerStart(wifiReconnectTimer, 0);
    break;
  }
}

void connectToWifi()
{
  // Serial.println("Connecting to Wi-Fi...");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
}

void setup()
{
  Serial.begin(115200); /* prepare for possible serial debug */
  pinMode(LED, OUTPUT);
  attachInterrupt(CLK, isrCLK, CHANGE);    // прерывание на 2 пине! CLK у энка
  attachInterrupt(DT, isrDT, CHANGE); 
  attachInterrupt(SW, isrSW, CHANGE); 
  enc1.setType(TYPE2);
  lv_update_mutex = xSemaphoreCreateMutex();
  wifiReconnectTimer = xTimerCreate("wifiTimer", pdMS_TO_TICKS(2000), pdFALSE, (void *)0, reinterpret_cast<TimerCallbackFunction_t>(connectToWifi));
  WiFi.onEvent(WiFiEvent);
  connectToWifi();
  setupDisplay();
  ui_init();
  runTasks();
}

void loop()
{
  xSemaphoreTake(lv_update_mutex, portMAX_DELAY);
  lv_timer_handler(); /* let the GUI do its work */
  xSemaphoreGive(lv_update_mutex);
  vTaskDelay(5 / portTICK_PERIOD_MS);
}

void IRAM_ATTR isrCLK() {
  enc1.tick();  // отработка в прерывании
}
void IRAM_ATTR isrDT() {
  enc1.tick();  // отработка в прерывании
}

void IRAM_ATTR isrSW() {
  enc1.tick();  // отработка в прерывании
}