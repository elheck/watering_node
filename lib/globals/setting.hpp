#ifndef LIB_GLOBALS_SETTING_HPP_
#define LIB_GLOBALS_SETTING_HPP_

#include <stdint.h>
#include "Adafruit_SSD1306.h"
#include "Arduino.h"

namespace settings {

namespace hygro {
static constexpr uint8_t SOIL_HUMIDITY_PIN = A0;
static constexpr uint16_t VALUE_DRY = 1020;
static constexpr uint16_t VALUE_WET = 20;
}  // namespace hygro

namespace oled {
static constexpr uint8_t SCREEN_WIDTH = 128;
static constexpr uint8_t SCREEN_HEIGHT = 64;
static constexpr int8_t RESET = -1;
static constexpr uint8_t DEVICE_ADDRESS = 0x3D;
static constexpr uint16_t TEXT_COLOR = WHITE;
}  // namespace oled

namespace dht {
static constexpr int DHT_PIN = 5;
}

}  // namespace settings
#endif