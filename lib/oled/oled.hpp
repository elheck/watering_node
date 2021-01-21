#ifndef LIB_OLED_OLED_HPP_
#define LIB_OLED_OLED_HPP_

#include "Adafruit_SSD1306.h"
#include "globals.hpp"

class Oled {
 public:
  Oled();
  ~Oled() = default;

  /**
   * @brief Start up the display
   * 
   */
  auto Begin() noexcept -> void;

  /**
   * @brief Update the screen with the current sensor values,
   * if the values deviate enough. Because updating the screen once 
   * is computationaly much more expensive than doing a bunch of 
   * floating point operations.
   * 
   * @param values The current sensor values read by the sensors 
   */
  auto Update(SensorValues values) noexcept -> void;

 private:
  static constexpr float DEVIATION_FACTOR = 0.1;
  SensorValues last_values_;
  Adafruit_SSD1306 oled_;

  auto SensorValuesDeviateEnough(SensorValues current_values) noexcept -> bool;

  /**
   * @brief Calculates the deviation of integral 
   * or floating point values only.
   * 
   * @tparam T type of the sensorvalue
   * @param new_value 
   * @param old_value 
   * @return 0.0 is deviation is over threshold and absolute of 
   * actual deviation if deviation is over threshold.
   */
  template <typename T>
  auto CalculateDeviation(T new_value, T old_value) noexcept -> float;
};
#endif
