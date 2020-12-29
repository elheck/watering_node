#ifndef LIB_OLED_OLED_HPP_
#define LIB_OLED_OLED_HPP_

#include <stdint.h>
#include "Arduino.h"
#include "U8x8lib.h"
#include "globals.hpp"

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

enum class BaseLineNames : uint8_t {
  SOIL_HUMIDITY,
  AIR_HUMIDITY,
  AIR_TEMPERATURE,
  HEAT_INDEX,
  PUMP_STATE
};

class Oled {
 public:
  Oled() = delete;
  ~Oled() = default;
  Oled(uint8_t scl, uint8_t sda, uint8_t cs, uint8_t dc, uint8_t reset);
  auto Begin() noexcept -> void;
  auto UpdateScreen(SensorValues& values) noexcept -> void;

 private:
  U8X8_SSD1306_128X64_NONAME_4W_SW_SPI oled_;
  static constexpr uint8_t MAX_LINES_ = 8;
  static constexpr uint8_t LINE_LENGTH_ = 16;
  String base_strings_[MAX_LINES_];
  SensorValues current_values_;
  bool redraw_;

  auto UpdateValues(SensorValues& values) noexcept -> void;
  auto ClearRestOfLine(uint8_t x, uint8_t y) noexcept -> void;
  auto RedrawBaseScreen() noexcept -> void;
};

#endif