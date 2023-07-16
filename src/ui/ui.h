// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.0
// LVGL version: 8.3.6
// Project name: 2in4tft

#ifndef _2IN4TFT_UI_H
#define _2IN4TFT_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined __has_include
#if __has_include("lvgl.h")
#include "lvgl.h"
#elif __has_include("lvgl/lvgl.h")
#include "lvgl/lvgl.h"
#else
#include "lvgl.h"
#endif
#else
#include "lvgl.h"
#endif

#include "ui_helpers.h"
#include "ui_events.h"
// SCREEN: ui_infoScreen
void ui_infoScreen_screen_init(void);
extern lv_obj_t * ui_infoScreen;
extern lv_group_t * encoder_group;
extern lv_obj_t * ui_encoder_modeLabel;
extern lv_obj_t * ui_StatusPanel;
extern lv_obj_t * ui_StatusBarLeft;
extern lv_obj_t * ui_Dashboard;
extern lv_obj_t * ui_FreqPanel;
extern lv_obj_t * ui_RDSPanel;
extern lv_obj_t * ui_StatusBarRight;
extern lv_obj_t * ui_clockLabel;
extern lv_obj_t * ui_freqLabel;
extern lv_obj_t * ui_freq_unitLabel;
extern lv_obj_t * ui_bandLabel;
extern lv_obj_t * ui_rssiLabel;
extern lv_obj_t * ui_snrLabel;
extern lv_obj_t * ui_stepLabel;
extern lv_obj_t * ui_bandwidthLabel;
extern lv_obj_t * ui_stereoLabel;
extern lv_obj_t * ui_AGCLabel;
extern lv_obj_t * ui_volumeBar;
extern lv_obj_t * ui_rssiBar;
extern lv_obj_t * ui_RDSLabel;
extern lv_obj_t * ui_RDSMessageLabel;
extern lv_obj_t * ui_RDSMessagePanel;
extern lv_obj_t * ui____initial_actions0;

extern lv_style_t style_bg;
extern lv_style_t style_bar_bg;
extern lv_style_t style_indic_rssi;
extern lv_style_t encoder_mode_style;
extern lv_style_t style_indic;


LV_IMG_DECLARE(ui_img_pixel_bg_png);    // assets\pixel.png
LV_FONT_DECLARE(ui_font_FontDSEG42);
LV_FONT_DECLARE(ui_font_FontDSEG48);
LV_FONT_DECLARE(ui_font_FontDSEG64);
LV_FONT_DECLARE(ui_font_FontDSEG20);
LV_FONT_DECLARE(ui_font_FontDSEG14);
LV_FONT_DECLARE(ui_font_FontDSEG32);
LV_FONT_DECLARE(ui_font_FontDSEG16);
LV_FONT_DECLARE(ui_font_FontDSEG18);


void ui_init(void);


#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
