#include "lvgl.h"
#include <TFT_eSPI.h> // Hardware-specific library
#include "GyverEncoder.h"

extern TFT_eSPI tft;
extern Encoder enc1;
extern lv_indev_t *indev_encoder;
extern int32_t encoder_counter;
extern int32_t last_encoder_count;


static void set_value(void * indic, int32_t v);


void setupDisplay();
void IRAM_ATTR onTick();
void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p);
void my_print(const char *buf);
void encoder_read(lv_indev_drv_t *drv, lv_indev_data_t *data);

