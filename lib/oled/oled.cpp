#include "oled.hpp"

Oled::Oled(uint8_t scl, uint8_t sda, uint8_t cs, uint8_t dc, uint8_t reset)
    : oled_(scl, sda, cs, dc, reset), base_strings_{}, current_values_{}, redraw_{true} {
  base_strings_[static_cast<uint8_t>(BaseLineNames::SOIL_HUMIDITY)] = "Soil Hum: ";
  base_strings_[static_cast<uint8_t>(BaseLineNames::AIR_HUMIDITY)] = "Air Hum: ";
  base_strings_[static_cast<uint8_t>(BaseLineNames::AIR_TEMPERATURE)] = "Temp: ";
  base_strings_[static_cast<uint8_t>(BaseLineNames::HEAT_INDEX)] = "Heat Ind: ";
  base_strings_[static_cast<uint8_t>(BaseLineNames::PUMP_STATE)] = "Pump: ";
}

auto Oled::Begin() noexcept -> void {
  oled_.begin();
  oled_.setFont(u8x8_font_pressstart2p_r);
  oled_.println("Initializing");
}

auto Oled::UpdateScreen(SensorValues& values) noexcept -> void {
  if (redraw_) {
    RedrawBaseScreen();
    redraw_ = false;
  }
  UpdateValues(values);
}

auto Oled::UpdateValues(SensorValues& values) noexcept -> void {
  auto first_line_length = base_strings_[static_cast<uint8_t>(BaseLineNames::SOIL_HUMIDITY)].length();
  auto second_line_length = base_strings_[static_cast<uint8_t>(BaseLineNames::AIR_HUMIDITY)].length();
  auto third_line_length = base_strings_[static_cast<uint8_t>(BaseLineNames::AIR_TEMPERATURE)].length();
  auto fourth_line_length = base_strings_[static_cast<uint8_t>(BaseLineNames::HEAT_INDEX)].length();
  auto fifth_line_length = base_strings_[static_cast<uint8_t>(BaseLineNames::PUMP_STATE)].length();

  ClearRestOfLine(first_line_length, 0);
  oled_.setCursor(first_line_length, 0);
  oled_.print(values.soil_humidity);
  oled_.print("%");

  ClearRestOfLine(second_line_length, 1);
  oled_.setCursor(second_line_length, 1);
  oled_.print(static_cast<uint8_t>(values.air_humidity));
  oled_.print("%");

  ClearRestOfLine(third_line_length, 2);
  oled_.setCursor(third_line_length, 2);
  oled_.print(values.air_temperature);
  oled_.print("C");

  ClearRestOfLine(fourth_line_length, 3);
  oled_.setCursor(fourth_line_length, 3);
  oled_.print(values.heat_index);
  oled_.print("C");

  ClearRestOfLine(fifth_line_length, 4);
  oled_.setCursor(fifth_line_length, 4);
}

auto Oled::ClearRestOfLine(uint8_t x, uint8_t y) noexcept -> void {
  oled_.setCursor(x, y);
  String placeholder = "";
  for (uint8_t i = x; i < LINE_LENGTH_; i++) {
    placeholder += " ";
  }
  oled_.print(placeholder);
}

auto Oled::RedrawBaseScreen() noexcept -> void {
  oled_.clear();
  for (const auto& element : base_strings_) {
    oled_.print(element);
    oled_.setCursor(0, oled_.ty + 1);
  }
}
