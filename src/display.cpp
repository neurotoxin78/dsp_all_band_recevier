#include "display.h"
#include "main.h"
#include "ui/ui.h"
#include "GyverEncoder.h"

#define CLK GPIO_NUM_33
#define DT GPIO_NUM_32
#define SW GPIO_NUM_25

Encoder enc1(CLK, DT, SW);
static lv_indev_drv_t indev_drv;
lv_indev_t *indev_encoder;
int32_t encoder_counter = 0;
int32_t last_encoder_count = 0;


/*Change to your screen resolution*/
static const uint16_t screenWidth = 240;
static const uint16_t screenHeight = 320;

static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[screenWidth * 10];

lv_obj_t *meter;
hw_timer_t *lv_tick_timer = NULL;
lv_group_t *main_group = NULL;

TFT_eSPI tft = TFT_eSPI(screenWidth, screenHeight); /* TFT instance */

void setupDisplay()
{
    lv_init();
#if LV_USE_LOG != 0
    lv_log_register_print_cb(my_print); /* register print function for debugging */
#endif
    lv_tick_timer = timerBegin(0, 80, true);
    timerAttachInterrupt(lv_tick_timer, &onTick, true);
    timerAlarmWrite(lv_tick_timer, 5000, true);
    timerAlarmEnable(lv_tick_timer);

    tft.begin();        /* TFT init */
    tft.setRotation(0); /* Landscape orientation, flipped */

    lv_disp_draw_buf_init(&draw_buf, buf, NULL, screenWidth * 10);

    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.hor_res = screenWidth;
    disp_drv.ver_res = screenHeight;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register(&disp_drv);

    //lv_indev_drv_init(&indev_drv);
    //indev_drv.type = LV_INDEV_TYPE_ENCODER;
    //indev_drv.read_cb = encoder_read;
    //indev_encoder = lv_indev_drv_register(&indev_drv);

    
    
}

void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
    uint32_t w = (area->x2 - area->x1 + 1);
    uint32_t h = (area->y2 - area->y1 + 1);

    tft.startWrite();
    tft.setAddrWindow(area->x1, area->y1, w, h);
    tft.pushColors((uint16_t *)&color_p->full, w * h, true);
    tft.endWrite();

    lv_disp_flush_ready(disp);
}

void IRAM_ATTR onTick()
{
    lv_tick_inc(5);
}

#if LV_USE_LOG != 0
/* Serial debugging */
void my_print(const char *buf)
{
    Serial.printf(buf);
    Serial.flush();
}
#endif

void encoder_read(lv_indev_drv_t *drv, lv_indev_data_t *data)
{
  //Serial.print(data->key);
  data->enc_diff = last_encoder_count - encoder_counter;
  //Serial.println(data->enc_diff);
  last_encoder_count = encoder_counter;
  //data->enc_diff = 0;
  
  if (enc1.isPress())
  {
    data->state = LV_INDEV_STATE_PRESSED;

  }
  else
  {
    data->state = LV_INDEV_STATE_RELEASED;
  }
}

