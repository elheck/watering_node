#include "perestaltic_pump.hpp"
#include "Arduino.h"
#include "setting.hpp"

PerestalticPump6V::PerestalticPump6V() : current_state_(PumpState::OFF) {
  pinMode(settings::pump::PUMP_PIN, OUTPUT);
  digitalWrite(settings::pump::PUMP_PIN, LOW);
}

auto PerestalticPump6V::On() noexcept -> void {
  digitalWrite(settings::pump::PUMP_PIN, HIGH);
  current_state_ = PumpState::ON;
}

auto PerestalticPump6V::Off() noexcept -> void {
  digitalWrite(settings::pump::PUMP_PIN, LOW);
  current_state_ = PumpState::OFF;
}

auto PerestalticPump6V::PumpingWater(uint16_t amount_in_ml) noexcept -> void {
  auto seconds_on = static_cast<uint16_t>(amount_in_ml / ML_PER_SECOND_);
  On();
  delay(seconds_on * 1000);
  Off();
}
auto PerestalticPump6V::CurrentPumpState() noexcept -> PumpState {
  return current_state_;
}

auto PerestalticPump6V::CurrentPumpStateString() noexcept -> const char* {
  return (current_state_ == PumpState::OFF) ? binary_states::OFF : binary_states::ON;
}