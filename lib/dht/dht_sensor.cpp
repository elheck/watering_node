#include "dht_sensor.hpp"

DHTSensor::DHTSensor(uint8_t dht_pin) : dht11_{dht_pin, DHT11} {
}

auto DHTSensor::Begin() noexcept -> void {
  dht11_.begin();
}

auto DHTSensor::GetTemperature() noexcept -> const float {
  return dht11_.readTemperature();
}

auto DHTSensor::GetHumidity() noexcept -> const float {
  return dht11_.readHumidity();
}

auto DHTSensor::GetHeatIndex() noexcept -> const float {
  return dht11_.computeHeatIndex(false);
}