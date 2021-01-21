#include "oled.hpp"
#include "Arduino.h"
#include "Wire.h"
#include "setting.hpp"

Oled::Oled()
    : last_values_{},
      oled_(settings::oled::SCREEN_WIDTH, settings::oled::SCREEN_HEIGHT, &Wire, settings::oled::RESET) {
}

auto Oled::Begin() noexcept -> void {
  if (!oled_.begin(SSD1306_SWITCHCAPVCC, settings::oled::DEVICE_ADDRESS, true, true)) {
    exit(-1);
  }
  delay(2000);
  oled_.clearDisplay();
  oled_.setTextSize(1);
  oled_.setTextColor(WHITE);
}

auto Oled::Update(SensorValues values) noexcept -> void {
  if (SensorValuesDeviateEnough(values)) {
    oled_.setCursor(0, 0);

    oled_.print("Temperatur: ");
    oled_.print(values.air_temperature);
    oled_.println("°C");

    oled_.print("Humidity: ");
    oled_.print(values.air_humidity);
    oled_.println(" %");

    oled_.print("Heat Index: ");
    oled_.print(values.heat_index);
    oled_.println(" °C");

    oled_.print("Soil Moisture: ");
    oled_.print(values.soil_humidity);
    oled_.println(" %");

    oled_.print("Pump State: ");
    oled_.print(values.pump_state);
  }
}

auto Oled::SensorValuesDeviateEnough(SensorValues current_values) noexcept -> bool {
  auto temperature_deviation = CalculateDeviation(current_values.air_temperature, last_values_.air_temperature);
  auto humidity_deviation = CalculateDeviation(current_values.air_humidity, last_values_.air_humidity);
  auto heat_index_deviation = CalculateDeviation(current_values.air_humidity, last_values_.air_humidity);
  auto soil_moisture_deviation = CalculateDeviation(current_values.soil_humidity, last_values_.soil_humidity);
  auto deviation = temperature_deviation + humidity_deviation + heat_index_deviation + soil_moisture_deviation;
  bool pump_state_changed = current_values.pump_state != last_values_.pump_state;
  last_values_ = current_values;
  if (pump_state_changed || deviation > 0.0) {
    return true;
  } else {
    return false;
  }
}

template <typename T>
auto Oled::CalculateDeviation(T new_value, T old_value) noexcept -> float {
  auto casted_new_value = static_cast<float>(new_value);
  auto casted_old_value = static_cast<float>(old_value);
  auto difference = casted_new_value - casted_old_value;
  auto max_deviation = static_cast<float>(fabs(DEVIATION_FACTOR * casted_old_value));
  if (difference > max_deviation) {
    return fabs(difference);
  } else {
    return 0.0;
  }
}
