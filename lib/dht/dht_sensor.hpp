#ifndef LIB_DHT_SENSOR_HPP_
#define LIB_DHT_SENSOR_HPP_

#include <stdint.h>
#include "DHT.h"

class DHTSensor {
 public:
  DHTSensor() = delete;
  ~DHTSensor() = default;
  explicit DHTSensor(uint8_t dht_pin);
  auto Begin() noexcept -> void;
  auto GetTemperature() noexcept -> const float;
  auto GetHumidity() noexcept -> const float;
  auto GetHeatIndex() noexcept -> const float;

 private:
  DHT dht11_;
};

#endif