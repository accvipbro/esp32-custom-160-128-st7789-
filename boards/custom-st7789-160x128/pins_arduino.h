#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include "soc/soc_caps.h"
#include <stdint.h>

// Basic SPI pin mapping (ESP32 DevKit style, chỉnh lại theo phần cứng của bạn)
#define SPI_SCK_PIN 18
#define SPI_MOSI_PIN 23
#define SPI_MISO_PIN 19
#define SPI_SS_PIN 5

static const uint8_t SS = SPI_SS_PIN;
static const uint8_t MOSI = SPI_MOSI_PIN;
static const uint8_t MISO = SPI_MISO_PIN;
static const uint8_t SCK = SPI_SCK_PIN;

#define GROVE_SDA 21
#define GROVE_SCL 22
static const uint8_t SDA = GROVE_SDA;
static const uint8_t SCL = GROVE_SCL;

#define HAS_SCREEN 1
#define HAS_TOUCH 1

#define USER_SETUP_LOADED 1
#define ST7789_DRIVER 1
#define TFT_RGB_ORDER TFT_BGR
#define TFT_INVERSION_ON
#define TFT_WIDTH 160
#define TFT_HEIGHT 128
#define TFT_BL 32
#define TFT_DC 2
#define TFT_RST 4
#define TFT_CS 15
#define TFT_MOSI SPI_MOSI_PIN
#define TFT_SCLK SPI_SCK_PIN
#define TFT_MISO SPI_MISO_PIN
#define SMOOTH_FONT 1
#define SPI_FREQUENCY 40000000
#define SPI_READ_FREQUENCY 20000000

// XPT2046 touch (nếu dùng touch điện dung khác, điều chỉnh lại)
#define TOUCH_CS 22

#define FP 1
#define FM 2
#define FG 3

#define ROTATION 0
#define MINBRIGHT (uint8_t)1

#endif /* Pins_Arduino_h */
