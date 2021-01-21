#ifndef LIB_SOIL_MOISTURE_SOIL_MOISTURE_HPP_
#define LIB_SOIL_MOISTURE_SOIL_MOISTURE_HPP_

#include <stdint.h>

class SoilMoistureSensor {
 public:
  virtual ~SoilMoistureSensor() = default;
  SoilMoistureSensor();

  /**
   * @brief Get the soil moisture reading from the sensor
   * in percent.
   * The dry and wet values have to be inputted manually for now.
   * There should be a live manual calibration selectable in the menu
   * in the future.
   * 
   * @return Current value reading in percent 
   */
  auto GetSoilMoistureInPercent() const noexcept -> const int;

 private:
  uint8_t sensor_pin_;
};

#endif
