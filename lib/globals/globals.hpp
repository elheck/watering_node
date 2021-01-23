#ifndef SRC_GLOBALS_HPP_
#define SRC_GLOBALS_HPP_

#include <stdint.h>
#include "Arduino.h"
#include "dht_sensor.hpp"
#include "soil_moisture.hpp"

namespace binary_states {
static constexpr char ON[] = "on";
static constexpr char OFF[] = "off";
}  // namespace binary_states

enum class PumpState {
  ON,
  OFF
};

using SensorValues = struct SensorValues_ {
  int soil_humidity;
  int max_soil_humidity = 0;
  int min_soil_huminity = 100;
  float air_humidity;
  float max_air_humidity = 0.0;
  float min_air_humidity = 100.0;
  float air_temperature;
  float max_air_temperature = 0.0;
  float min_air_temperature = 100.0;
  long heat_index;
  long max_heat_index = 0;
  long min_heat_index = 100;
  String pump_state = binary_states::OFF;

  auto ReadSensorValues(DHTSensor *dht, SoilMoistureSensor *soil_moisture_sensor) noexcept -> void {
    air_humidity = dht->GetHumidity();
    air_temperature = dht->GetTemperature();
    heat_index = dht->GetHeatIndex();
    soil_humidity = soil_moisture_sensor->GetSoilMoistureInPercent();
    CalculateMaxMinAirHumidity();
    CalculateMaxMinAirTemperature();
    CalculateMaxMinSoilHumidity();
    CalculateMaxMinSoilHumidity();
  }

 private:
  auto CalculateMaxMinSoilHumidity() noexcept -> void {
    if (soil_humidity > max_soil_humidity) {
      max_soil_humidity = soil_humidity;
    }
    if (soil_humidity < min_soil_huminity) {
      min_soil_huminity = soil_humidity;
    }
  }

  auto CalculateMaxMinAirHumidity() noexcept -> void {
    if (air_humidity > max_air_humidity) {
      max_air_humidity = air_humidity;
    }
    if (air_humidity < min_air_humidity) {
      min_air_humidity = air_humidity;
    }
  }

  auto CalculateMaxMinAirTemperature() noexcept -> void {
    if (air_temperature > max_air_temperature) {
      max_air_temperature = air_temperature;
    }
    if (air_temperature < min_air_temperature) {
      min_air_temperature = air_temperature;
    }
  }

  auto CalculateMaxMinHeatIndex() noexcept -> void {
    if (heat_index > max_heat_index) {
      max_heat_index = heat_index;
    }
    if (heat_index < min_heat_index) {
      min_heat_index = heat_index;
    }
  }
};

#endif