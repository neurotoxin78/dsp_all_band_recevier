#include <Arduino.h>
#include <lvgl.h>
#include "ui/ui.h"
#include <WiFi.h>
#include "main.h"
#include "tasks.h"
#include "display.h"


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
  lv_update_mutex = xSemaphoreCreateMutex();
  wifiReconnectTimer = xTimerCreate("wifiTimer", pdMS_TO_TICKS(2000), pdFALSE, (void *)0, reinterpret_cast<TimerCallbackFunction_t>(connectToWifi));
  WiFi.onEvent(WiFiEvent);
  connectToWifi();
  setupDisplay();
  ui_init();
  //lv_indev_set_group(indev_encoder, encoder_group);

  runTasks();
}

void loop()
{
  xSemaphoreTake(lv_update_mutex, portMAX_DELAY);
  lv_timer_handler(); /* let the GUI do its work */
  xSemaphoreGive(lv_update_mutex);
  vTaskDelay(5 / portTICK_PERIOD_MS);
}
