#include "rotary_encoder.hpp"

RotaryEncoder::RotaryEncoder() : encoder_(settings::encoder::CLK, settings::encoder::DT) {
  encoder_.write(BASE_POSITION);
}

auto RotaryEncoder::GetDifference() noexcept -> long {
  auto current_increment = encoder_.read();
  auto difference = 0;
  if (current_increment != BASE_POSITION) {
    difference = current_increment;
    encoder_.write(BASE_POSITION);
  }
  return difference;
}