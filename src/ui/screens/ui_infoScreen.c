// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.0
// LVGL version: 8.3.6
// Project name: 2in4tft

#include "../ui.h"


void ui_infoScreen_screen_init(void)
{
    encoder_group = lv_group_create();

    ui_infoScreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_infoScreen, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_border_color(ui_infoScreen, lv_color_hex(0x79a690), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_infoScreen, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_infoScreen, &ui_img_pixel_bg_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    //lv_obj_set_style_bg_opa(ui_infoScreen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_group_add_obj(encoder_group, ui_infoScreen);

    ui_StatusPanel = lv_obj_create(ui_infoScreen);
    lv_obj_set_width(ui_StatusPanel, 240);
    lv_obj_set_height(ui_StatusPanel, 24);
    lv_obj_set_x(ui_StatusPanel, 0);
    lv_obj_set_y(ui_StatusPanel, 148);
    lv_obj_set_align(ui_StatusPanel, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_StatusPanel, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_radius(ui_StatusPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_StatusPanel, lv_color_hex(0x5c7d6d), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_StatusPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_StatusPanel, lv_color_hex(0x43594e), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_StatusPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_StatusPanel, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_StatusPanel, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_shadow_color(ui_StatusPanel, lv_color_hex(0x3E3E3E), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_shadow_opa(ui_StatusPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_shadow_width(ui_StatusPanel, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_shadow_spread(ui_StatusPanel, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_shadow_ofs_x(ui_StatusPanel, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_shadow_ofs_y(ui_StatusPanel, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_StatusPanel, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_opa(ui_StatusPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_StatusBarLeft = lv_label_create(ui_StatusPanel);
    lv_obj_set_width(ui_StatusBarLeft, 147);
    lv_obj_set_height(ui_StatusBarLeft, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_StatusBarLeft, -40);
    lv_obj_set_y(ui_StatusBarLeft, 0);
    lv_obj_set_align(ui_StatusBarLeft, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_StatusBarLeft, LV_LABEL_LONG_SCROLL);
    lv_label_set_text(ui_StatusBarLeft, "status");
    lv_label_set_recolor(ui_StatusBarLeft, "true");
    lv_obj_set_style_text_color(ui_StatusBarLeft, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_StatusBarLeft, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_StatusBarLeft, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_StatusBarLeft, lv_color_hex(0x838282), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_StatusBarLeft, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_FreqPanel = lv_obj_create(ui_infoScreen);
    lv_obj_set_width(ui_FreqPanel, 226);
    lv_obj_set_height(ui_FreqPanel, 80);
    lv_obj_set_x(ui_FreqPanel, 0);
    lv_obj_set_y(ui_FreqPanel, 32);
    lv_obj_set_align(ui_FreqPanel, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_FreqPanel, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_radius(ui_FreqPanel, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_FreqPanel, lv_color_hex(0x79a690), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_FreqPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_FreqPanel, lv_color_hex(0x557565), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_FreqPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_FreqPanel, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_FreqPanel, lv_color_hex(0x3E3E3E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_FreqPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_FreqPanel, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_FreqPanel, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui_FreqPanel, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui_FreqPanel, 3, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Dashboard = lv_obj_create(ui_infoScreen);
    lv_obj_set_width(ui_Dashboard, 226);
    lv_obj_set_height(ui_Dashboard, 80);
    lv_obj_set_x(ui_Dashboard, 0);
    lv_obj_set_y(ui_Dashboard, 185);
    lv_obj_set_align(ui_Dashboard, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_Dashboard, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_radius(ui_Dashboard, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Dashboard, lv_color_hex(0x79a690), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Dashboard, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Dashboard, lv_color_hex(0x718a7d), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Dashboard, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Dashboard, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_Dashboard, lv_color_hex(0x3E3E3E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_Dashboard, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_Dashboard, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_Dashboard, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui_Dashboard, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui_Dashboard, 3, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_StatusBarRight = lv_label_create(ui_StatusPanel);
    lv_obj_set_width(ui_StatusBarRight, 150);
    lv_obj_set_height(ui_StatusBarRight, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_StatusBarRight, 0);
    lv_obj_set_y(ui_StatusBarRight, 0);
    lv_obj_set_align(ui_StatusBarRight, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_StatusBarRight, "0 kB");
    lv_obj_set_style_text_color(ui_StatusBarRight, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_StatusBarRight, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_StatusBarRight, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_StatusBarRight, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_clockLabel = lv_label_create(ui_infoScreen);
    lv_obj_set_width(ui_clockLabel, 120);
    lv_obj_set_height(ui_clockLabel, 20);
    lv_obj_set_x(ui_clockLabel, 0);
    lv_obj_set_y(ui_clockLabel, 3);
    lv_obj_set_align(ui_clockLabel, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(ui_clockLabel, "00:00:00");
    lv_label_set_recolor(ui_clockLabel, "true");
    lv_obj_set_style_text_color(ui_clockLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_clockLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_clockLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_clockLabel, &ui_font_FontDSEG18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_freqLabel = lv_label_create(ui_FreqPanel);
    lv_obj_set_width(ui_freqLabel, 200);
    lv_obj_set_height(ui_freqLabel, 50);
    lv_obj_set_align(ui_freqLabel, LV_ALIGN_CENTER);
    lv_obj_set_x(ui_freqLabel, -30);
    lv_obj_set_y(ui_freqLabel, 6);
    lv_label_set_text(ui_freqLabel, "___._");
    lv_label_set_recolor(ui_freqLabel, "true");
    lv_obj_set_style_text_color(ui_freqLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_freqLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_freqLabel, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_freqLabel, &ui_font_FontDSEG32, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_freq_unitLabel = lv_label_create(ui_FreqPanel);
    lv_obj_set_width(ui_freq_unitLabel, 50);
    lv_obj_set_height(ui_freq_unitLabel, 20);
    lv_obj_set_x(ui_freq_unitLabel, 82);
    lv_obj_set_y(ui_freq_unitLabel, 0);
    lv_obj_set_align(ui_freq_unitLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_freq_unitLabel, "MHz");
    lv_label_set_recolor(ui_freq_unitLabel, "true");
    lv_obj_set_style_text_color(ui_freq_unitLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_freq_unitLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_freq_unitLabel, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_freq_unitLabel, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_bandLabel = lv_label_create(ui_FreqPanel);
    lv_obj_set_width(ui_bandLabel, 50);
    lv_obj_set_height(ui_bandLabel, 20);
    lv_obj_set_x(ui_bandLabel, -8);
    lv_obj_set_y(ui_bandLabel, -12);
    lv_obj_set_align(ui_bandLabel, LV_ALIGN_TOP_LEFT);
    lv_label_set_text(ui_bandLabel, "FM");
    lv_label_set_recolor(ui_bandLabel, "true");
    lv_obj_set_style_text_color(ui_bandLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_bandLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_bandLabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_bandLabel, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_stepLabel = lv_label_create(ui_Dashboard);
    lv_obj_set_width(ui_stepLabel, 150);
    lv_obj_set_height(ui_stepLabel, 20);
    lv_obj_set_x(ui_stepLabel, 5);
    lv_obj_set_y(ui_stepLabel, -12);
    lv_obj_set_align(ui_stepLabel, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(ui_stepLabel, "S___KHz");
    lv_label_set_recolor(ui_stepLabel, "true");
    lv_obj_set_style_text_color(ui_stepLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_stepLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_stepLabel, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_stepLabel, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_bandwidthLabel = lv_label_create(ui_Dashboard);
    lv_obj_set_width(ui_bandwidthLabel, 150);
    lv_obj_set_height(ui_bandwidthLabel, 20);
    lv_obj_set_x(ui_bandwidthLabel, -65);
    lv_obj_set_y(ui_bandwidthLabel, -12);
    lv_obj_set_align(ui_bandwidthLabel, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_bandwidthLabel, "BW___KHz");
    lv_label_set_recolor(ui_bandwidthLabel, "true");
    lv_obj_set_style_text_color(ui_bandwidthLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_bandwidthLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_bandwidthLabel, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_bandwidthLabel, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_stereoLabel = lv_label_create(ui_Dashboard);
    lv_obj_set_width(ui_stereoLabel, 150);
    lv_obj_set_height(ui_stereoLabel, 20);
    lv_obj_set_x(ui_stereoLabel, -65);
    lv_obj_set_y(ui_stereoLabel, -12);
    lv_obj_set_align(ui_stereoLabel, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_stereoLabel, "MONO");
    lv_label_set_recolor(ui_stereoLabel, "true");
    lv_obj_set_style_text_color(ui_stereoLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_stereoLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_stereoLabel, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_stereoLabel, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_rssiLabel = lv_label_create(ui_Dashboard);
    lv_obj_set_width(ui_rssiLabel, 100);
    lv_obj_set_height(ui_rssiLabel, 16);
    lv_obj_set_x(ui_rssiLabel, -8);
    lv_obj_set_y(ui_rssiLabel, 12);
    lv_obj_set_align(ui_rssiLabel, LV_ALIGN_BOTTOM_LEFT);
    lv_label_set_text(ui_rssiLabel, "SQ _ dBuV");
    lv_label_set_recolor(ui_rssiLabel, "true");
    lv_obj_set_style_text_color(ui_rssiLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_rssiLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_rssiLabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_rssiLabel, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_rssiBar = lv_bar_create(ui_Dashboard);
    lv_obj_remove_style_all(ui_rssiBar);
    lv_obj_add_style(ui_rssiBar, &style_bar_bg, 0);
    lv_obj_add_style(ui_rssiBar, &style_indic_rssi, LV_PART_INDICATOR);
    lv_obj_set_size(ui_rssiBar, 12, 50);
    lv_obj_set_align(ui_rssiBar, LV_ALIGN_LEFT_MID);
    lv_obj_set_x(ui_rssiBar, -8);
    lv_obj_set_y(ui_rssiBar, -10);
    lv_bar_set_range(ui_rssiBar, 0, 127);

    ui_snrLabel = lv_label_create(ui_Dashboard);
    lv_obj_set_width(ui_snrLabel, 100);
    lv_obj_set_height(ui_snrLabel, 16);
    lv_obj_set_x(ui_snrLabel, 8);
    lv_obj_set_y(ui_snrLabel, 12);
    lv_obj_set_align(ui_snrLabel, LV_ALIGN_BOTTOM_RIGHT);
    lv_label_set_text(ui_snrLabel, "SNR _ dB");
    lv_label_set_recolor(ui_snrLabel, "true");
    lv_obj_set_style_text_color(ui_snrLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_snrLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_snrLabel, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_snrLabel, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AGCLabel = lv_label_create(ui_Dashboard);
    lv_obj_set_width(ui_AGCLabel, 45);
    lv_obj_set_height(ui_AGCLabel, 20);
    lv_obj_set_x(ui_AGCLabel, 5);
    lv_obj_set_y(ui_AGCLabel, 12);
    lv_obj_set_align(ui_AGCLabel, LV_ALIGN_BOTTOM_MID);
    lv_label_set_text(ui_AGCLabel, "AGC");
    lv_label_set_recolor(ui_AGCLabel, "true");
    lv_obj_set_style_text_color(ui_AGCLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_AGCLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_AGCLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_AGCLabel, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_volumeBar = lv_bar_create(ui_infoScreen);
    lv_obj_remove_style_all(ui_volumeBar); /*To have a clean start*/
    lv_obj_add_style(ui_volumeBar, &style_bg, 0);
    lv_obj_add_style(ui_volumeBar, &style_indic, LV_PART_INDICATOR);
    lv_bar_set_range(ui_volumeBar, 0, 63);
    lv_obj_set_size(ui_volumeBar, 225, 16);
    lv_obj_set_x(ui_volumeBar, 0);
    lv_obj_set_y(ui_volumeBar, 120);
    lv_obj_set_align(ui_volumeBar, LV_ALIGN_CENTER);
    lv_bar_set_value(ui_volumeBar, 100, LV_ANIM_ON);
    lv_obj_set_style_shadow_color(ui_volumeBar, lv_color_hex(0x3E3E3E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_volumeBar, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_volumeBar, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_volumeBar, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui_volumeBar, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui_volumeBar, 2, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_encoder_modeLabel = lv_label_create(ui_infoScreen);
    lv_obj_add_style(ui_encoder_modeLabel, &encoder_mode_style, 0);
    lv_obj_set_width(ui_encoder_modeLabel, 120);
    lv_obj_set_height(ui_encoder_modeLabel, 20);
    lv_obj_set_x(ui_encoder_modeLabel, 5);
    lv_obj_set_y(ui_encoder_modeLabel, 5);
    lv_obj_set_align(ui_encoder_modeLabel, LV_ALIGN_TOP_LEFT);
    lv_label_set_text(ui_encoder_modeLabel, "ENCODER_MODE");
    lv_label_set_recolor(ui_encoder_modeLabel, "true");
    lv_obj_set_style_text_color(ui_encoder_modeLabel, lv_color_hex(0x454545), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_encoder_modeLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_encoder_modeLabel, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_set_style_text_font(ui_encoder_modeLabel, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_RDSPanel = lv_obj_create(ui_infoScreen);
    lv_obj_set_width(ui_RDSPanel, 228);
    lv_obj_set_height(ui_RDSPanel, 30);
    lv_obj_set_x(ui_RDSPanel, 0);
    lv_obj_set_y(ui_RDSPanel, 135);
    lv_obj_set_align(ui_RDSPanel, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_RDSPanel, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_radius(ui_RDSPanel, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_RDSPanel, lv_color_hex(0xa36338), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_RDSPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_RDSPanel, lv_color_hex(0x704426), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_RDSPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_RDSPanel, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_RDSPanel, lv_color_hex(0x3E3E3E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_RDSPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_RDSPanel, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_RDSPanel, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui_RDSPanel, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui_RDSPanel, 2, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_RDSLabel = lv_label_create(ui_RDSPanel);
    lv_obj_set_width(ui_RDSLabel, 220);
    lv_obj_set_height(ui_RDSLabel, 24);
    lv_obj_set_x(ui_RDSLabel, -10);
    lv_obj_set_y(ui_RDSLabel, -12);
    lv_obj_set_align(ui_RDSLabel, LV_ALIGN_TOP_LEFT);
    lv_label_set_text(ui_RDSLabel, "RDS TEXT THERE");
    lv_label_set_recolor(ui_RDSLabel, "true");
    lv_obj_set_style_text_color(ui_RDSLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_RDSLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_RDSLabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_RDSLabel, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_color(ui_RDSLabel, lv_color_hex(0x704426), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_width(ui_RDSLabel, 2, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_style_init(&style_bar_bg);
    lv_style_set_bg_color(&style_bar_bg, lv_color_hex(0x454545));
    // lv_style_set_bg_opa(&style_bar_bg, LV_OPA_COVER);
    lv_style_set_border_color(&style_bar_bg, lv_color_hex(0xFFFFFF));
    lv_style_set_border_width(&style_bar_bg, 1);
    lv_style_set_pad_all(&style_bar_bg, 0); /*To make the indicator smaller*/
    lv_style_set_radius(&style_bar_bg, 3);
    lv_style_set_anim_time(&style_bar_bg, 1000);

    lv_style_init(&style_indic_rssi);
    lv_style_set_bg_opa(&style_indic_rssi, LV_OPA_COVER);
    lv_style_set_bg_color(&style_indic_rssi, lv_color_hex(0xFFFFFF)); // 0x387BA3
    lv_style_set_radius(&style_indic_rssi, 1);

    lv_style_init(&encoder_mode_style);
    lv_style_set_radius(&encoder_mode_style, 5);
    lv_style_set_bg_opa(&encoder_mode_style, LV_OPA_COVER);
    lv_style_set_bg_color(&encoder_mode_style, lv_color_hex(0x79a690));
    lv_style_set_border_color(&encoder_mode_style, lv_color_hex(0x79a690));
    lv_style_set_border_width(&encoder_mode_style, 1);

    lv_style_init(&style_bg);
    lv_style_set_border_color(&style_bg, lv_color_hex(0x719985));
    lv_style_set_border_width(&style_bg, 2);
    lv_style_set_pad_all(&style_bg, 0); /*To make the indicator smaller*/
    lv_style_set_radius(&style_bg, 5);
    lv_style_set_anim_time(&style_bg, 1000);

    lv_style_init(&style_indic);
    lv_style_set_bg_opa(&style_indic, LV_OPA_COVER);
    lv_style_set_bg_color(&style_indic, lv_color_hex(0x719985));
    lv_style_set_radius(&style_indic, 3);
}
