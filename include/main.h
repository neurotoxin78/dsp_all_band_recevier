#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/semphr.h>
#include "GyverEncoder.h"

#define DT GPIO_NUM_32
#define CLK GPIO_NUM_33
#define SW GPIO_NUM_25

extern Encoder enc1;
extern SemaphoreHandle_t lv_update_mutex;

void IRAM_ATTR isrCLK();
void IRAM_ATTR isrDT();
void IRAM_ATTR isrSW();