#include "soil_moisture.hpp"
#include <Arduino.h>
#include "setting.hpp"

SoilMoistureSensor::SoilMoistureSensor() : sensor_pin_(settings::hygro::SOIL_HUMIDITY_PIN) {
}

auto SoilMoistureSensor::GetSoilMoistureInPercent() const noexcept -> const int {
  const int analog_value = analogRead(sensor_pin_);
  const int percentage = map(analog_value, settings::hygro::VALUE_DRY, settings::hygro::VALUE_WET, 0, 100);
  return percentage;
}