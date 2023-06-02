#include <Arduino.h>
#include <SI4735.h>

#define LSB 1
#define USB 2

extern volatile uint8_t current_encoder_mode;
extern volatile uint8_t current_band;
extern volatile uint8_t current_step;
extern volatile uint8_t current_bandwidth;

void receiver_setup();
void changeEncoderMode();
void updateFrequency();
void updateVolume();
void updateEncoderMode();
void updateBand();
void updateStep();
void changeBand();
void switchBand();
void setFMband();
void setAMband();
void setSWband();
void setSSBband();
void changeBandwidth();
void updateBandwidth();
void changeStep();
void updateUnits();
void scanUp();
void scanDown();
void showFrequency( uint16_t freq );
String disp_freq(uint16_t fq);
void showRDSMsg();
void showRDSStation();
void showRDSTime();
void checkRDS();
void fm_mono_stereo();
void loadSSB();
void updateAGC();
