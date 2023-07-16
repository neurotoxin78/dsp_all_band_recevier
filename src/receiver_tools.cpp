#include <Arduino.h>
#include <SI4735.h>
#include "main.h"
#include "tasks.h"
#include "lvgl.h"
#include "ui/ui.h"
#include "receiver_tools.h"
#include <patch_full.h>

const uint16_t size_content = sizeof ssb_patch_content;

volatile uint8_t current_volume;

char *rdsMsg;
char *stationName;
char *rdsTime;
char bufferStatioName[50];
char bufferRdsMsg[100];
char bufferRdsTime[32];

// Steps database. You can change the Steps and numbers of steps here if you need.
EncoderMode encoder_mode[] = {
    {" VOLUME ", 0},
    {" TUNING ", 1}};

const int MaxMode = (sizeof encoder_mode / sizeof(EncoderMode)) - 1; // index for max increment / decrement
volatile uint8_t current_encoder_mode = 0;

Band band[] = {
    {"FM", 0},
    {"AM", 1},
    {"SW", 2},
    {"SSB", 3}};

const int MaxBands = (sizeof band / sizeof(Band)) - 1;
volatile uint8_t current_band = 0;

Step step[] = {
    {"S:1 KHz", 1},
    {"S:5 KHz", 5},
    {"S:10 KHz", 10},
    {"S:100 KHz", 100},
    {"S:1 MHz", 1000}};

const int MaxSteps = (sizeof step / sizeof(Step)) - 1;
volatile uint8_t current_step = 3;

BandWidth bandwidth[] = {
    {"BW:6KHz", "6"},
    {"BW:4KHz", "4"},
    {"BW:3KHz", "3"},
    {"BW:2KHz", "2"},
    {"BW:1KHz", "1"},
    {"BW:1.8KHz", "1.8"},
    {"BW:2.5KHz", "2.5"}};

const int MaxBandwidths = (sizeof bandwidth / sizeof(Band)) - 1;
volatile uint8_t current_bandwidth = 0;

// SSB
uint8_t bandwidthIdx_ssb = 2;
const char *bandwidth_ssb[] = {"1.2", "2.2", "3.0", "4.0", "0.5", "1.0"};
int currentBFO = 0;
uint8_t currentBFOStep = 25;

typedef struct
{
    uint16_t minimumFreq;
    uint16_t maximumFreq;
    uint16_t currentFreq;
    uint16_t currentStep;
    uint8_t currentSSB;
} BandSSB;

BandSSB band_ssb[] = {
    {520, 2000, 810, 1, LSB},
    {3500, 4000, 3700, 1, LSB},
    {7000, 7500, 7100, 1, LSB},
    {11700, 12000, 11940, 1, USB},
    {14000, 14300, 14200, 1, USB},
    {18000, 18300, 18100, 1, USB},
    {21000, 21400, 21200, 1, USB},
    {24890, 25000, 24940, 1, USB},
    {27000, 27700, 27300, 1, USB},
    {28000, 28500, 28400, 1, USB}};

const int lastBand = (sizeof band_ssb / sizeof(BandSSB)) - 1;
// int currentFreqIdx = 9;
int currentFreqIdx = 2;

void ssbBandwidth()
{
    bandwidthIdx_ssb++;
    if (bandwidthIdx_ssb > 5)
        bandwidthIdx_ssb = 0;
    rx.setSSBAudioBandwidth(bandwidthIdx_ssb);
    // If audio bandwidth selected is about 2 kHz or below, it is recommended to set Sideband Cutoff Filter to 0.
    if (bandwidthIdx_ssb == 0 || bandwidthIdx_ssb == 4 || bandwidthIdx_ssb == 5)
        rx.setSSBSidebandCutoffFilter(0);
    else
        rx.setSSBSidebandCutoffFilter(1);
}

void encoderRight()
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
    default:
        break;
    }
}

void encoderLeft()
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
    default:
        break;
    }
}

void changeEncoderMode()
{
    uint8_t limiter = 0;
    if (current_band == 0)
    {
        limiter = 2;
    }
    if (current_encoder_mode != MaxMode - limiter)
        current_encoder_mode += 1;
    else
        current_encoder_mode = 0;
    updateEncoderMode();
}

void receiver_setup()
{
    pinMode(RCV_RESET_PIN, OUTPUT);
    digitalWrite(RCV_RESET_PIN, HIGH);
    // Look for the Si47XX I2C bus address
    int16_t si4735Addr = rx.getDeviceI2CAddress(RCV_RESET_PIN);
    if (si4735Addr == 0)
    {
        Serial.println("Si473X not found!");
        Serial.flush();
        while (1)
            ;
    }
    else
    {
        Serial.print("The SI473X / SI474X I2C address is 0x");
        Serial.println(si4735Addr, HEX);
    }
    vTaskDelay(500);
    rx.setMaxDelayPowerUp(500);
    rx.setMaxDelaySetFrequency(50);
    rx.setup(RCV_RESET_PIN, FM_FUNCTION);
    rx.setI2CFastMode();
    vTaskDelay(500);
    setFMband();
    rx.setVolume(STARTUP_VOLUME);
    updateEncoderMode();
    updateFrequency();
    updateVolume();
    updateStep();
    updateBand();
}

void updateBand()
{
    xSemaphoreTake(lv_update_mutex, portMAX_DELAY);
    lv_label_set_text(ui_bandLabel, band[current_band].name);
    if (current_band == 0)
    {
        lv_obj_add_flag(ui_bandwidthLabel, LV_OBJ_FLAG_HIDDEN);

        lv_obj_clear_flag(ui_stereoLabel, LV_OBJ_FLAG_HIDDEN);
    }
    else
    {
        lv_obj_clear_flag(ui_bandwidthLabel, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_RDSPanel, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_stereoLabel, LV_OBJ_FLAG_HIDDEN);
    }
    xSemaphoreGive(lv_update_mutex);
}

void updateEncoderMode()
{
    xSemaphoreTake(lv_update_mutex, portMAX_DELAY);
    lv_label_set_text(ui_encoder_modeLabel, encoder_mode[current_encoder_mode].name);
    xSemaphoreGive(lv_update_mutex);
}

void updateFrequency()
{
    uint16_t raw_freq = rx.getFrequency();
    String fmfreq = disp_freq(raw_freq);

    if (current_band == 0)
    {
        xSemaphoreTake(lv_update_mutex, portMAX_DELAY);
        lv_label_set_text(ui_freqLabel, fmfreq.c_str());
        xSemaphoreGive(lv_update_mutex);
    }
    else
    {
        xSemaphoreTake(lv_update_mutex, portMAX_DELAY);
        lv_label_set_text(ui_freqLabel, String((float)rx.getFrequency() / 1000, 3).c_str());
        xSemaphoreGive(lv_update_mutex);
    }
}

void updateStep()
{
    xSemaphoreTake(lv_update_mutex, portMAX_DELAY);
    lv_label_set_text(ui_stepLabel, step[current_step].name);
    xSemaphoreGive(lv_update_mutex);
}

void updateVolume()
{
    xSemaphoreTake(lv_update_mutex, portMAX_DELAY);
    lv_bar_set_value(ui_volumeBar, rx.getCurrentVolume(), LV_ANIM_ON);
    xSemaphoreGive(lv_update_mutex);
}

void changeStep()
{
    if (current_step != MaxSteps)
        current_step += 1;
    else
        current_step = 0;
    rx.setFrequencyStep(step[current_step].value);
    updateStep();
}

void changeBandwidth()
{
    if (current_bandwidth != MaxBandwidths)
        current_bandwidth += 1;
    else
        current_bandwidth = 0;

    if (current_band != 0)
    {
        rx.setBandwidth(current_bandwidth, 1);
        updateBandwidth();
    }
}

void updateBandwidth()
{
    if (current_band == 3)
    {
        xSemaphoreTake(lv_update_mutex, portMAX_DELAY);
        lv_label_set_text(ui_bandwidthLabel, bandwidth_ssb[bandwidthIdx_ssb]);
        xSemaphoreGive(lv_update_mutex);
    }
    else
    {
        xSemaphoreTake(lv_update_mutex, portMAX_DELAY);
        lv_label_set_text(ui_bandwidthLabel, bandwidth[current_bandwidth].name);
        xSemaphoreGive(lv_update_mutex);
    }
}

void updateUnits()
{
    if (current_band == 0)
    {
        xSemaphoreTake(lv_update_mutex, portMAX_DELAY);
        lv_label_set_text(ui_freq_unitLabel, "MHz");
        xSemaphoreGive(lv_update_mutex);
    }
    else
    {
        xSemaphoreTake(lv_update_mutex, portMAX_DELAY);
        lv_label_set_text(ui_freq_unitLabel, "KHz");
        xSemaphoreGive(lv_update_mutex);
    }
}

void switchBand()
{
    switch (current_band)
    {
    case 0:
        setFMband();
        break;
    case 1:
        setAMband();
        break;
    case 2:
        setSWband();
        break;
    case 3:
        setSSBband();
        break;
    default:
        break;
    }
}

void setFMband()
{
    // rx.setTuneFrequencyAntennaCapacitor(0);
    rx.setFM(8600, 10800, 9760, 10); // 100FM
    rx.setRdsConfig(1, 2, 2, 2, 2);
    rx.setFmStereoOn();
    rx.setAutomaticGainControl(1, 0);
}

void setAMband()
{
    rx.setAM(520, 1750, 520, 10);
    rx.setAvcAmMaxGain(48); // Sets the maximum gain for automatic volume control on AM mode.
    rx.setSeekAmLimits(520, 1750);
    rx.setSeekAmSpacing(10); // spacing 10kHz
}

void setSWband()
{
    rx.setAM(100, 30000, 7200, 5);
    rx.setSeekAmLimits(100, 30000);
    rx.setSeekAmSpacing(1);
}

void loadSSB()
{
    rx.reset();
    rx.queryLibraryId(); // Is it really necessary here?  Just powerDown() maigh work!
    rx.patchPowerUp();
    delay(50);
    rx.setI2CFastMode(); // Recommended
    rx.downloadPatch(ssb_patch_content, size_content);
    rx.setI2CStandardMode(); // goes back to default (100kHz)
    rx.setSSBConfig(2, 1, 0, 0, 0, 1);
    delay(25); // Set standard transfer I2C speed
}

void setSSBband()
{
    loadSSB();
    rx.setTuneFrequencyAntennaCapacitor(1); // Set antenna tuning capacitor for SW.
    rx.setSSB(band_ssb[currentFreqIdx].minimumFreq, band_ssb[currentFreqIdx].maximumFreq, band_ssb[currentFreqIdx].currentFreq, band_ssb[currentFreqIdx].currentStep, band_ssb[currentFreqIdx].currentSSB);
    delay(100);
    // rx.setAvcAmMaxGain(60);
    rx.setSSBAutomaticVolumeControl(1);
    rx.setSsbSoftMuteMaxAttenuation(0);
    rx.setSSBSidebandCutoffFilter(0);
}

void changeSSBsubband()
{
    if (currentFreqIdx != lastBand)
        currentFreqIdx += 1;
    else
        currentFreqIdx = 0;
    updateFrequency();
    rx.setSSB(band_ssb[currentFreqIdx].minimumFreq, band_ssb[currentFreqIdx].maximumFreq, band_ssb[currentFreqIdx].currentFreq, band_ssb[currentFreqIdx].currentStep, band_ssb[currentFreqIdx].currentSSB);
}

void changeBand()
{
    if (current_band != MaxBands)
        current_band += 1;
    else
        current_band = 0;

    switchBand();
    updateBand();
    updateUnits();
    updateFrequency();
}

void scanUp()
{
    rx.seekStationProgress(showFrequency, 1);
    // rx.seekStation(1,1);
    vTaskDelay(100 / portTICK_PERIOD_MS);
    updateFrequency();
}

void scanDown()
{
    rx.seekStationProgress(showFrequency, 0);
    vTaskDelay(100 / portTICK_PERIOD_MS);
    // rx.seekStation(1,1);
    updateFrequency();
}

void showFrequency(uint16_t freq)
{
    if (current_band == 0)
    {
        xSemaphoreTake(lv_update_mutex, portMAX_DELAY);
        lv_label_set_text(ui_freqLabel, String(freq / 100.0, 2).c_str());
        xSemaphoreGive(lv_update_mutex);
    }
    else
    {
        xSemaphoreTake(lv_update_mutex, portMAX_DELAY);
        lv_label_set_text(ui_freqLabel, String(freq).c_str());
        xSemaphoreGive(lv_update_mutex);
    }

    // Serial.print(String(freq / 100.0, 2));
    // Serial.println("MHz ");
}

String disp_freq(uint16_t fq)
{
    String s1 = String(fq);
    String s2 = s1.substring(0, s1.length() - 2) + "." + s1.substring(s1.length() - 2);
    return s2;
}

void showRDSMsg()
{
    rdsMsg[35] = bufferRdsMsg[35] = '\0';
    if (strcmp(bufferRdsMsg, rdsMsg) == 0)
        return;
    Serial.println(rdsMsg);
    xSemaphoreTake(lv_update_mutex, portMAX_DELAY);
    lv_label_set_text(ui_RDSLabel, rdsMsg);
    xSemaphoreGive(lv_update_mutex);
    vTaskDelay(250);
}

void showRDSStation()
{
    xSemaphoreTake(lv_update_mutex, portMAX_DELAY);
    lv_label_set_text(ui_RDSLabel, stationName);
    xSemaphoreGive(lv_update_mutex);
    Serial.println(stationName);
    vTaskDelay(250);
}

void showRDSTime()
{

    if (strcmp(bufferRdsTime, rdsTime) == 0)
        return;
    // printValue(80, 110, bufferRdsTime, rdsTime, COLOR_GREEN, 6);
    xSemaphoreTake(lv_update_mutex, portMAX_DELAY);
    lv_label_set_text(ui_RDSLabel, rdsTime);
    xSemaphoreGive(lv_update_mutex);
    Serial.println(rdsTime);
    vTaskDelay(250);
}

long stationNameElapsed = millis();

void checkRDS()
{
    rx.getRdsStatus();
    if (rx.getRdsReceived())
    {
        Serial.println("RDS received");
        showRDSPanels();
        rdsMsg = "";
        stationName = "";
        rdsMsg = "";
        if (rx.getRdsSync() && rx.getRdsSyncFound())
        {
            rdsMsg = rx.getRdsText2A();
            stationName = rx.getRdsText0A();
            rdsTime = rx.getRdsTime();
            if (rdsMsg != NULL)
            {
                showRDSMsg();
            }
            if (stationName != NULL)
            {
                showRDSStation();
            }

            // if ( rdsTime != NULL ) showRDSTime();
        }
    }
    else
    {
        hideRDSPanels();
    }
}

void showRDSPanels(void)
{
    xSemaphoreTake(lv_update_mutex, portMAX_DELAY);
    lv_obj_clear_flag(ui_RDSPanel, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(ui_RDSMessagePanel, LV_OBJ_FLAG_HIDDEN);
    lv_obj_set_height(ui_FreqPanel, 80);
    xSemaphoreGive(lv_update_mutex);
}

void hideRDSPanels(void)
{
    xSemaphoreTake(lv_update_mutex, portMAX_DELAY);
    lv_obj_add_flag(ui_RDSPanel, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_RDSMessagePanel, LV_OBJ_FLAG_HIDDEN);
    lv_obj_set_height(ui_FreqPanel, 56);
    xSemaphoreGive(lv_update_mutex);
}

void fm_mono_stereo()
{
    xSemaphoreTake(lv_update_mutex, portMAX_DELAY);
    lv_label_set_text(ui_stereoLabel, (rx.getCurrentPilot()) ? "STEREO" : "MONO");
    xSemaphoreGive(lv_update_mutex);
}

void updateAGC()
{
    rx.getAutomaticGainControl();
    if (rx.isAgcEnabled())
    {
        xSemaphoreTake(lv_update_mutex, portMAX_DELAY);
        lv_obj_clear_flag(ui_AGCLabel, LV_OBJ_FLAG_HIDDEN);
        xSemaphoreGive(lv_update_mutex);
    }
    else
    {
        xSemaphoreTake(lv_update_mutex, portMAX_DELAY);
        lv_obj_add_flag(ui_AGCLabel, LV_OBJ_FLAG_HIDDEN);
        xSemaphoreGive(lv_update_mutex);
    }
}