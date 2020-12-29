#ifndef LIB_SOIL_MOISTURE_SOIL_MOISTURE_HPP_
#define LIB_SOIL_MOISTURE_SOIL_MOISTURE_HPP_

#include <stdint.h>

class SoilMoistureSensor {
 public:
  SoilMoistureSensor() = delete;
  ~SoilMoistureSensor() = default;
  SoilMoistureSensor(uint8_t sensor_pin);
  auto GetSoilMoistureInPercent() const noexcept -> const int;

 private:
  uint8_t sensor_pin_;
};

#endif
