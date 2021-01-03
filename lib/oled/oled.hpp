#ifndef LIB_OLED_OLED_HPP_
#define LIB_OLED_OLED_HPP_

#include "Adafruit_SSD1306.h"
#include "globals.hpp"

class Oled {
 public:
  Oled();
  ~Oled() = default;

  auto Begin() noexcept -> void;
  auto Update(SensorValues values) noexcept -> void;

 private:
  Adafruit_SSD1306 oled_;
};
#endif
