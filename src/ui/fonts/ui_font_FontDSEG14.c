/*******************************************************************************
 * Size: 14 px
 * Bpp: 1
 * Opts: --bpp 1 --size 14 --font C:\users\neuro\Documents\SquareLine\assets\DSEG14ClassicMini-Bold.ttf -o C:\users\neuro\Documents\SquareLine\assets\ui_font_FontDSEG14.c --format lvgl -r 0x20-0x7f --no-compress --no-prefilter
 ******************************************************************************/

#include "../ui.h"

#ifndef UI_FONT_FONTDSEG14
#define UI_FONT_FONTDSEG14 1
#endif

#if UI_FONT_FONTDSEG14

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0x0,

    /* U+0022 "\"" */
    0x86, 0xf7, 0xbd, 0xc0,

    /* U+0024 "$" */
    0x7e, 0xc0, 0xd8, 0xd8, 0xd8, 0xd0, 0x3c, 0x13,
    0x1b, 0x1b, 0x1b, 0x3, 0x1, 0x7e,

    /* U+0025 "%" */
    0xc0, 0x71, 0x38, 0x9c, 0x4c, 0x1, 0xb0, 0x6,
    0x47, 0x23, 0x91, 0xc0, 0x60,

    /* U+0026 "&" */
    0xfc, 0x0, 0x48, 0x48, 0x48, 0x0, 0x0, 0x1,
    0x3, 0x4b, 0x4b, 0x4b, 0x3, 0xfc,

    /* U+0027 "'" */
    0xfc,

    /* U+0028 "(" */
    0xe3, 0x80,

    /* U+0029 ")" */
    0xe3, 0x80,

    /* U+002A "*" */
    0x79, 0xe7, 0x88, 0xfc, 0x87, 0x9e, 0x78,

    /* U+002B "+" */
    0x30, 0xc3, 0x8, 0xfc, 0x83, 0xc, 0x30,

    /* U+002C "," */
    0xe0,

    /* U+002D "-" */
    0xdc,

    /* U+002E "." */
    0xc0,

    /* U+002F "/" */
    0x11, 0x10, 0x0, 0x88, 0x80,

    /* U+0030 "0" */
    0x7f, 0xe0, 0xf0, 0xf8, 0x7c, 0x3e, 0xe, 0x3,
    0x1, 0xc1, 0xf0, 0xf8, 0x7c, 0x3c, 0x1b, 0xf8,

    /* U+0031 "1" */
    0x7f, 0xd7, 0xfd,

    /* U+0032 "2" */
    0x3f, 0x80, 0xc0, 0x60, 0x30, 0x18, 0xc, 0xd9,
    0x80, 0xc0, 0x60, 0x30, 0x18, 0xc, 0x3, 0xf0,

    /* U+0033 "3" */
    0xff, 0x3, 0x3, 0x3, 0x3, 0x3, 0xec, 0x3,
    0x3, 0x3, 0x3, 0x3, 0x3, 0xfc,

    /* U+0034 "4" */
    0x80, 0xe0, 0xf0, 0x78, 0x3c, 0x19, 0xb0, 0x6,
    0x3, 0x1, 0x80, 0xc0, 0x20,

    /* U+0035 "5" */
    0x3f, 0x60, 0x30, 0x18, 0xc, 0x6, 0x0, 0xd8,
    0x3, 0x1, 0x80, 0xc0, 0x60, 0x30, 0x1b, 0xf0,

    /* U+0036 "6" */
    0x3f, 0x60, 0x30, 0x18, 0xc, 0x6, 0x0, 0xd9,
    0x83, 0xc1, 0xe0, 0xf0, 0x78, 0x3c, 0x1b, 0xf0,

    /* U+0037 "7" */
    0x3f, 0xe0, 0xf0, 0x78, 0x3c, 0x1c, 0x4, 0x2,
    0x3, 0x1, 0x80, 0xc0, 0x60, 0x10,

    /* U+0038 "8" */
    0x3f, 0xe0, 0xf0, 0x78, 0x3c, 0x1e, 0xc, 0xd9,
    0x83, 0xc1, 0xe0, 0xf0, 0x78, 0x3c, 0x1b, 0xf0,

    /* U+0039 "9" */
    0x3f, 0xe0, 0xf0, 0x78, 0x3c, 0x1e, 0xc, 0xd8,
    0x3, 0x1, 0x80, 0xc0, 0x60, 0x30, 0x1b, 0xf0,

    /* U+003A ":" */
    0x82,

    /* U+003C "<" */
    0x8, 0x20, 0x80, 0x0, 0x0, 0x10, 0x41, 0x0,
    0x3f,

    /* U+003D "=" */
    0x6e, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3f,

    /* U+003E ">" */
    0x41, 0x4, 0x0, 0x0, 0x0, 0x2, 0x8, 0x20,
    0x3f,

    /* U+003F "?" */
    0x7f, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc, 0x10,
    0x18, 0x18, 0x18,

    /* U+0040 "@" */
    0x7f, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc, 0xd3,
    0xdb, 0xdb, 0xdb, 0xdb, 0xc3, 0x7e,

    /* U+0041 "A" */
    0x3f, 0xe0, 0xf0, 0x78, 0x3c, 0x1e, 0xc, 0xd9,
    0x83, 0xc1, 0xe0, 0xf0, 0x70, 0x10,

    /* U+0042 "B" */
    0x7f, 0x3, 0x1b, 0x1b, 0x1b, 0x13, 0xc, 0x13,
    0x1b, 0x1b, 0x1b, 0x3, 0x1, 0x7e,

    /* U+0043 "C" */
    0x3f, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x80,
    0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x7f,

    /* U+0044 "D" */
    0x7f, 0x3, 0x1b, 0x1b, 0x1b, 0x3, 0x0, 0x3,
    0x1b, 0x1b, 0x1b, 0x3, 0x1, 0x7e,

    /* U+0045 "E" */
    0x3f, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x37, 0xc0,
    0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x7f,

    /* U+0046 "F" */
    0x3f, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x37, 0xc0,
    0xc0, 0xc0, 0xc0, 0x80,

    /* U+0047 "G" */
    0x3f, 0x60, 0x30, 0x18, 0xc, 0x6, 0x0, 0x19,
    0x83, 0xc1, 0xe0, 0xf0, 0x78, 0x3c, 0x1b, 0xf0,

    /* U+0048 "H" */
    0x80, 0xe0, 0xf0, 0x78, 0x3c, 0x19, 0xb3, 0x7,
    0x83, 0xc1, 0xe0, 0xe0, 0x20,

    /* U+0049 "I" */
    0x7e, 0x0, 0x18, 0x18, 0x18, 0x0, 0x0, 0x0,
    0x18, 0x18, 0x18, 0x0, 0x0, 0x7e,

    /* U+004A "J" */
    0x0, 0x80, 0xc0, 0x60, 0x30, 0x18, 0x6, 0x3,
    0x83, 0xc1, 0xe0, 0xf0, 0x78, 0x37, 0xe0,

    /* U+004B "K" */
    0xc1, 0x87, 0xe, 0x1c, 0x6, 0x30, 0x61, 0xc3,
    0x87, 0x0,

    /* U+004C "L" */
    0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x80, 0xc0,
    0xc0, 0xc0, 0xc0, 0xc0, 0x7f,

    /* U+004D "M" */
    0xc1, 0xf1, 0xf8, 0xfc, 0x7c, 0x18, 0x3, 0x7,
    0xb3, 0xd9, 0xec, 0xf0, 0x60,

    /* U+004E "N" */
    0xc1, 0xf0, 0xf8, 0x7c, 0x3c, 0x18, 0x3, 0x7,
    0x87, 0xc3, 0xe1, 0xf0, 0x60,

    /* U+004F "O" */
    0x3f, 0xe0, 0xf0, 0x78, 0x3c, 0x1e, 0xe, 0x3,
    0x1, 0xc1, 0xe0, 0xf0, 0x78, 0x3c, 0x1b, 0xf0,

    /* U+0050 "P" */
    0x3f, 0xe0, 0xf0, 0x78, 0x3c, 0x1e, 0xc, 0xd9,
    0x80, 0xc0, 0x60, 0x30, 0x10, 0x0,

    /* U+0051 "Q" */
    0x3f, 0xe0, 0xf0, 0x78, 0x3c, 0x1e, 0xe, 0x2,
    0x0, 0xc1, 0xe1, 0xf0, 0xf8, 0x7c, 0x1b, 0xf8,

    /* U+0052 "R" */
    0x3f, 0xe0, 0xf0, 0x78, 0x3c, 0x1e, 0xc, 0xd9,
    0x80, 0xc2, 0x61, 0x30, 0x98, 0x0,

    /* U+0053 "S" */
    0x7f, 0x60, 0x38, 0x1c, 0xe, 0x6, 0x0, 0xd8,
    0x1, 0x1, 0x81, 0xc0, 0xe0, 0x70, 0x1b, 0xf8,

    /* U+0054 "T" */
    0x7e, 0x0, 0x18, 0x18, 0x18, 0x0, 0x0, 0x0,
    0x18, 0x18, 0x18,

    /* U+0055 "U" */
    0x80, 0xe0, 0xf0, 0x78, 0x3c, 0x1c, 0x6, 0x3,
    0x83, 0xc1, 0xe0, 0xf0, 0x78, 0x37, 0xe0,

    /* U+0056 "V" */
    0xc1, 0x87, 0xe, 0x1c, 0x0, 0x30, 0x70, 0xe1,
    0xc3, 0x0,

    /* U+0057 "W" */
    0x80, 0xec, 0xf6, 0x7b, 0x3d, 0x9c, 0x6, 0x3,
    0x83, 0xe3, 0xf1, 0xf8, 0xf8, 0x30,

    /* U+0058 "X" */
    0x99, 0x90, 0x0, 0x99, 0x90,

    /* U+0059 "Y" */
    0x99, 0x90, 0x0, 0x66, 0x60,

    /* U+005A "Z" */
    0xfc, 0x0, 0x82, 0x8, 0x0, 0x0, 0x1, 0x4,
    0x10, 0x3, 0xf0,

    /* U+005C "\\" */
    0x88, 0x80, 0x0, 0x11, 0x10,

    /* U+005E "^" */
    0xdf, 0xfc,

    /* U+005F "_" */
    0x7e,

    /* U+0060 "`" */
    0xe0,

    /* U+0061 "a" */
    0x3f, 0xe0, 0xf0, 0x78, 0x3c, 0x1e, 0xc, 0xd9,
    0x83, 0xc1, 0xe0, 0xf0, 0x70, 0x10,

    /* U+0062 "b" */
    0x7f, 0x3, 0x1b, 0x1b, 0x1b, 0x13, 0xc, 0x13,
    0x1b, 0x1b, 0x1b, 0x3, 0x1, 0x7e,

    /* U+0063 "c" */
    0x3f, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x80,
    0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x7f,

    /* U+0064 "d" */
    0x7f, 0x3, 0x1b, 0x1b, 0x1b, 0x3, 0x0, 0x3,
    0x1b, 0x1b, 0x1b, 0x3, 0x1, 0x7e,

    /* U+0065 "e" */
    0x3f, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x37, 0xc0,
    0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x7f,

    /* U+0066 "f" */
    0x3f, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x37, 0xc0,
    0xc0, 0xc0, 0xc0, 0x80,

    /* U+0067 "g" */
    0x3f, 0x60, 0x30, 0x18, 0xc, 0x6, 0x0, 0x19,
    0x83, 0xc1, 0xe0, 0xf0, 0x78, 0x3c, 0x1b, 0xf0,

    /* U+0068 "h" */
    0x80, 0xe0, 0xf0, 0x78, 0x3c, 0x19, 0xb3, 0x7,
    0x83, 0xc1, 0xe0, 0xe0, 0x20,

    /* U+0069 "i" */
    0x7e, 0x0, 0x18, 0x18, 0x18, 0x0, 0x0, 0x0,
    0x18, 0x18, 0x18, 0x0, 0x0, 0x7e,

    /* U+006A "j" */
    0x0, 0x80, 0xc0, 0x60, 0x30, 0x18, 0x6, 0x3,
    0x83, 0xc1, 0xe0, 0xf0, 0x78, 0x37, 0xe0,

    /* U+006B "k" */
    0xc1, 0x87, 0xe, 0x1c, 0x6, 0x30, 0x61, 0xc3,
    0x87, 0x0,

    /* U+006C "l" */
    0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x80, 0xc0,
    0xc0, 0xc0, 0xc0, 0xc0, 0x7f,

    /* U+006D "m" */
    0xc1, 0xf1, 0xf8, 0xfc, 0x7c, 0x18, 0x3, 0x7,
    0xb3, 0xd9, 0xec, 0xf0, 0x60,

    /* U+006E "n" */
    0xc1, 0xf0, 0xf8, 0x7c, 0x3c, 0x18, 0x3, 0x7,
    0x87, 0xc3, 0xe1, 0xf0, 0x60,

    /* U+006F "o" */
    0x3f, 0xe0, 0xf0, 0x78, 0x3c, 0x1e, 0xe, 0x3,
    0x1, 0xc1, 0xe0, 0xf0, 0x78, 0x3c, 0x1b, 0xf0,

    /* U+0070 "p" */
    0x3f, 0xe0, 0xf0, 0x78, 0x3c, 0x1e, 0xc, 0xd9,
    0x80, 0xc0, 0x60, 0x30, 0x10, 0x0,

    /* U+0071 "q" */
    0x3f, 0xe0, 0xf0, 0x78, 0x3c, 0x1e, 0xe, 0x2,
    0x0, 0xc1, 0xe1, 0xf0, 0xf8, 0x7c, 0x1b, 0xf8,

    /* U+0072 "r" */
    0x3f, 0xe0, 0xf0, 0x78, 0x3c, 0x1e, 0xc, 0xd9,
    0x80, 0xc2, 0x61, 0x30, 0x98, 0x0,

    /* U+0073 "s" */
    0x7f, 0x60, 0x38, 0x1c, 0xe, 0x6, 0x0, 0xd8,
    0x1, 0x1, 0x81, 0xc0, 0xe0, 0x70, 0x1b, 0xf8,

    /* U+0074 "t" */
    0x7e, 0x0, 0x18, 0x18, 0x18, 0x0, 0x0, 0x0,
    0x18, 0x18, 0x18,

    /* U+0075 "u" */
    0x80, 0xe0, 0xf0, 0x78, 0x3c, 0x1c, 0x6, 0x3,
    0x83, 0xc1, 0xe0, 0xf0, 0x78, 0x37, 0xe0,

    /* U+0076 "v" */
    0xc1, 0x87, 0xe, 0x1c, 0x0, 0x30, 0x70, 0xe1,
    0xc3, 0x0,

    /* U+0077 "w" */
    0x80, 0xec, 0xf6, 0x7b, 0x3d, 0x9c, 0x6, 0x3,
    0x83, 0xe3, 0xf1, 0xf8, 0xf8, 0x30,

    /* U+0078 "x" */
    0x99, 0x90, 0x0, 0x99, 0x90,

    /* U+0079 "y" */
    0x99, 0x90, 0x0, 0x66, 0x60,

    /* U+007A "z" */
    0xfc, 0x0, 0x82, 0x8, 0x0, 0x0, 0x1, 0x4,
    0x10, 0x3, 0xf0,

    /* U+007C "|" */
    0xfc, 0xf, 0xc0,

    /* U+007E "~" */
    0x7f, 0xe0, 0xfe, 0xff, 0x7f, 0xbe, 0x8c, 0xf9,
    0x1, 0xd9, 0xfd, 0xfe, 0xff, 0x7c, 0x1b, 0xf8
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 45, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 183, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2, .adv_w = 183, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = 7},
    {.bitmap_index = 6, .adv_w = 183, .box_w = 8, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 20, .adv_w = 183, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 33, .adv_w = 183, .box_w = 8, .box_h = 14, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 47, .adv_w = 183, .box_w = 2, .box_h = 4, .ofs_x = 5, .ofs_y = 8},
    {.bitmap_index = 48, .adv_w = 183, .box_w = 1, .box_h = 9, .ofs_x = 7, .ofs_y = 2},
    {.bitmap_index = 50, .adv_w = 183, .box_w = 1, .box_h = 9, .ofs_x = 4, .ofs_y = 2},
    {.bitmap_index = 52, .adv_w = 183, .box_w = 6, .box_h = 9, .ofs_x = 3, .ofs_y = 2},
    {.bitmap_index = 59, .adv_w = 183, .box_w = 6, .box_h = 9, .ofs_x = 3, .ofs_y = 2},
    {.bitmap_index = 66, .adv_w = 183, .box_w = 1, .box_h = 3, .ofs_x = 4, .ofs_y = 2},
    {.bitmap_index = 67, .adv_w = 183, .box_w = 6, .box_h = 1, .ofs_x = 3, .ofs_y = 7},
    {.bitmap_index = 68, .adv_w = 0, .box_w = 2, .box_h = 1, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 69, .adv_w = 183, .box_w = 4, .box_h = 9, .ofs_x = 4, .ofs_y = 2},
    {.bitmap_index = 74, .adv_w = 183, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 90, .adv_w = 183, .box_w = 2, .box_h = 12, .ofs_x = 8, .ofs_y = 1},
    {.bitmap_index = 93, .adv_w = 183, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 109, .adv_w = 183, .box_w = 8, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 123, .adv_w = 183, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 136, .adv_w = 183, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 152, .adv_w = 183, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 168, .adv_w = 183, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 182, .adv_w = 183, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 198, .adv_w = 183, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 214, .adv_w = 45, .box_w = 1, .box_h = 7, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 215, .adv_w = 183, .box_w = 6, .box_h = 12, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 224, .adv_w = 183, .box_w = 7, .box_h = 8, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 231, .adv_w = 183, .box_w = 6, .box_h = 12, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 240, .adv_w = 183, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 251, .adv_w = 183, .box_w = 8, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 265, .adv_w = 183, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 279, .adv_w = 183, .box_w = 8, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 293, .adv_w = 183, .box_w = 8, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 307, .adv_w = 183, .box_w = 8, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 321, .adv_w = 183, .box_w = 8, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 335, .adv_w = 183, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 347, .adv_w = 183, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 363, .adv_w = 183, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 376, .adv_w = 183, .box_w = 8, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 390, .adv_w = 183, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 405, .adv_w = 183, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 415, .adv_w = 183, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 428, .adv_w = 183, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 441, .adv_w = 183, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 454, .adv_w = 183, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 470, .adv_w = 183, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 484, .adv_w = 183, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 500, .adv_w = 183, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 514, .adv_w = 183, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 530, .adv_w = 183, .box_w = 8, .box_h = 11, .ofs_x = 2, .ofs_y = 3},
    {.bitmap_index = 541, .adv_w = 183, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 556, .adv_w = 183, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 566, .adv_w = 183, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 580, .adv_w = 183, .box_w = 4, .box_h = 9, .ofs_x = 4, .ofs_y = 2},
    {.bitmap_index = 585, .adv_w = 183, .box_w = 4, .box_h = 9, .ofs_x = 4, .ofs_y = 3},
    {.bitmap_index = 590, .adv_w = 183, .box_w = 6, .box_h = 14, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 601, .adv_w = 183, .box_w = 4, .box_h = 9, .ofs_x = 4, .ofs_y = 2},
    {.bitmap_index = 606, .adv_w = 183, .box_w = 3, .box_h = 5, .ofs_x = 1, .ofs_y = 8},
    {.bitmap_index = 608, .adv_w = 183, .box_w = 7, .box_h = 1, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 609, .adv_w = 183, .box_w = 1, .box_h = 3, .ofs_x = 4, .ofs_y = 9},
    {.bitmap_index = 610, .adv_w = 183, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 624, .adv_w = 183, .box_w = 8, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 638, .adv_w = 183, .box_w = 8, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 652, .adv_w = 183, .box_w = 8, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 666, .adv_w = 183, .box_w = 8, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 680, .adv_w = 183, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 692, .adv_w = 183, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 708, .adv_w = 183, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 721, .adv_w = 183, .box_w = 8, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 735, .adv_w = 183, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 750, .adv_w = 183, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 760, .adv_w = 183, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 773, .adv_w = 183, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 786, .adv_w = 183, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 799, .adv_w = 183, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 815, .adv_w = 183, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 829, .adv_w = 183, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 845, .adv_w = 183, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 859, .adv_w = 183, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 875, .adv_w = 183, .box_w = 8, .box_h = 11, .ofs_x = 2, .ofs_y = 3},
    {.bitmap_index = 886, .adv_w = 183, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 901, .adv_w = 183, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 911, .adv_w = 183, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 925, .adv_w = 183, .box_w = 4, .box_h = 9, .ofs_x = 4, .ofs_y = 2},
    {.bitmap_index = 930, .adv_w = 183, .box_w = 4, .box_h = 9, .ofs_x = 4, .ofs_y = 3},
    {.bitmap_index = 935, .adv_w = 183, .box_w = 6, .box_h = 14, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 946, .adv_w = 183, .box_w = 2, .box_h = 9, .ofs_x = 5, .ofs_y = 2},
    {.bitmap_index = 949, .adv_w = 183, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint8_t glyph_id_ofs_list_3[] = {
    0, 0, 1, 2, 3, 4, 5, 6,
    7, 8, 9, 10, 11, 12, 13, 14,
    15, 16, 17, 18, 19, 20, 21, 22,
    23, 24, 25, 26, 27, 28, 29, 0,
    30, 0, 31
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 3, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 36, .range_length = 23, .glyph_id_start = 4,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 60, .range_length = 31, .glyph_id_start = 27,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 92, .range_length = 35, .glyph_id_start = 58,
        .unicode_list = NULL, .glyph_id_ofs_list = glyph_id_ofs_list_3, .list_length = 35, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_FULL
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LV_VERSION_CHECK(8, 0, 0)
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 4,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LV_VERSION_CHECK(8, 0, 0)
    .cache = &cache
#endif
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LV_VERSION_CHECK(8, 0, 0)
const lv_font_t ui_font_FontDSEG14 = {
#else
lv_font_t ui_font_FontDSEG14 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 14,          /*The maximum line height required by the font*/
    .base_line = 0,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if UI_FONT_FONTDSEG14*/

