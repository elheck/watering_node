#include "oled.hpp"
#include "Arduino.h"
#include "Wire.h"
#include "setting.hpp"

Oled::Oled()
    : oled_(settings::oled::SCREEN_WIDTH, settings::oled::SCREEN_HEIGHT, &Wire, settings::oled::RESET) {
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