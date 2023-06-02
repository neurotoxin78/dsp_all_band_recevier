#include <WiFi.h>
#include <Arduino.h>
#include <SI4735.h>
#define RCV_RESET_PIN GPIO_NUM_15
#define AM_FUNCTION 1
#define FM_FUNCTION 0

extern SI4735 rx;

void runTasks();
void heartbeat_Task(void *parameter);
void conInfo_Task(void *parameter);
int getStrength();
void freeMem_Task(void *parameter);
void clock_Task(void *parameter);
void encoder_Task(void *parameter);
void receiver_ctrl_Task(void *parameter);
void receiver_info_Task(void *parameter);
static void prvAutoResetEncoderModeTimerCallback( TimerHandle_t xTimer );
void startAutoResetEncoderModeTimer();
void stopAutoResetEncoderModeTimer();
