#ifndef LIB_GLOBALS_SETTING_HPP_
#define LIB_GLOBALS_SETTING_HPP_

#include <stdint.h>
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
}  // namespace oled

namespace dht {
static constexpr int DHT_PIN = 5;
}

namespace encoder {
static constexpr uint8_t CLK = 2;
static constexpr uint8_t DT = 3;
}  // namespace encoder

namespace pump {
static constexpr uint8_t PUMP_PIN = 6;
}
}  // namespace settings
#endif