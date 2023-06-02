// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.0
// LVGL version: 8.3.6
// Project name: 2in4tft

#include "ui.h"
#include "ui_helpers.h"


///////////////////// VARIABLES ////////////////////

// SCREEN: ui_infoScreen
void ui_infoScreen_screen_init(void);
lv_obj_t * ui_infoScreen;
lv_group_t * encoder_group;
lv_obj_t * ui_encoder_modeLabel;
lv_obj_t * ui_StatusPanel;
lv_obj_t * ui_StatusBarLeft;
lv_obj_t * ui_MainPanel;
lv_obj_t * ui_RDSPanel;
lv_obj_t * ui_StatusBarRight;
lv_obj_t * ui_clockLabel;
lv_obj_t * ui_freqLabel;
lv_obj_t * ui_freq_unitLabel;
lv_obj_t * ui_bandLabel;
lv_obj_t * ui_stereoLabel;
lv_obj_t * ui_rssiLabel;
lv_obj_t * ui_snrLabel;
lv_obj_t * ui_AGCLabel;
lv_obj_t * ui_stepLabel;
lv_obj_t * ui_bandwidthLabel;
lv_obj_t * ui_volumeBar;
lv_obj_t * ui_RDSLabel;
lv_obj_t * ui____initial_actions0;
lv_style_t style_bg;
lv_style_t style_indic;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////

///////////////////// SCREENS ////////////////////

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_infoScreen_screen_init();
    ui____initial_actions0 = lv_obj_create(NULL);
    lv_disp_load_scr(ui_infoScreen);
    
}
