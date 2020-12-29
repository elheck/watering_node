#ifndef LIB_GLOBALS_SETTING_HPP_
#define LIB_GLOBALS_SETTING_HPP_

#include "Arduino.h"

namespace settings {

namespace hygro {
static constexpr int SOIL_HUMIDITY_PIN = A0;
static constexpr int VALUE_DRY = 1020;
static constexpr int VALUE_WET = 20;
}  // namespace hygro

namespace oled {
static constexpr int SCL_PIN = 13;
static constexpr int SDA_PIN = 11;
static constexpr int CS_PIN = 10;
static constexpr int DC_PIN = 9;
static constexpr int RESET_PIN = 8;
}  // namespace oled

namespace dht {
static constexpr int DHT_PIN = 5;
}
}  // namespace settings
#endif