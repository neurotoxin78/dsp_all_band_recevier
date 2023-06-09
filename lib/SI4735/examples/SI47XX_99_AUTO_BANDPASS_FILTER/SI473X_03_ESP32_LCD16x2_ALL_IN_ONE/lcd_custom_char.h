
#define LCD_RSSI 0
#define LCD_FILTER_SYMBOL 10
#define LCD_BANDWIDTH 11
#define LCD_AGC 19


// Custom LCD character to show the signal rssi level.
byte lcdSignal[8][8] = {{B00000, B00000, B00000, B00000, B00000, B11111, B01110, B00100},
                        {B00000, B00000, B00000, B00000, B11111, B01110, B00100, B00100},
                        {B00000, B00000, B00000, B11111, B01110, B00100, B00100, B00100},
                        {B00000, B00000, B11111, B01110, B00100, B00100, B00100, B00100},
                        {B00000, B11111, B01110, B00100, B00100, B00100, B00100, B00100},
                        {B11111, B01110, B00100, B00100, B00100, B00100, B00100, B00100},
                        {B11111, B11111, B01110, B00100, B00100, B00100, B00100, B00100},
                        {B11111, B01110, B00100, B00100, B00100, B00100, B00100, B00000}};

// Filter Symbol
byte lcdFilterSymbol[] = {B11111, B11111, B00000, B00000, B10001, B11011, B11011, B11011};


// Filter bandwidth                                                                         // AM       - SSB
byte lcdBandwidth[7][8] = {{B00000, B00000, B00000, B11111, B00000, B00000, B00000, B00000}, // 1kHz     - 0.5
                          {B00000, B00000, B00000, B11111, B11111, B00000, B00000, B00000}, // 1.8kHz   - 1.0
                          {B00000, B00000, B11111, B11111, B11111, B00000, B00000, B00000}, // 2kHz     - 1.2
                          {B00000, B00000, B11111, B11111, B11111, B11111, B00000, B00000}, // 2.5kHz   - 2.2
                          {B00000, B00000, B11111, B11111, B11111, B11111, B11111, B00000}, // 3kHz     - 3.0
                          {B00000, B11111, B11111, B11111, B11111, B11111, B11111, B00000}, // 4kHz     - 4.0
                          {B11111, B11111, B11111, B11111, B11111, B11111, B11111, B11111 } // 6kHz
                          };

byte lcdAgc [] = {B11100, B10100, B11100, B10100, B10111, B00100, B00101, B00111};    // AG
byte lcdStereo[] = {B11100, B10000, B11100, B00100, B11100, B00111, B00010, B00010};  // ST
