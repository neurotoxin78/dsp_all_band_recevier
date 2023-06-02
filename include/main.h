#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/semphr.h>
#define LED GPIO_NUM_21

extern SemaphoreHandle_t lv_update_mutex;