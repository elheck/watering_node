#include <Arduino.h>
#include "dht_sensor.hpp"
#include "globals.hpp"
#include "oled.hpp"
#include "perestaltic_pump.hpp"
#include "rotary_encoder.hpp"
#include "setting.hpp"
#include "soil_moisture.hpp"

auto HandleRotaryEncoderRotation(long difference) noexcept -> void;

DHTSensor dht(settings::dht::DHT_PIN);
SoilMoistureSensor hygro;
Oled display;
RotaryEncoder rotary_encoder;
PerestalticPump6V pump;

void setup(void) {
  dht.Begin();
  display.Begin();
}

void loop(void) {
  auto difference = rotary_encoder.GetDifference();
  if (difference != 0) {
    HandleRotaryEncoderRotation(difference);
  }
  SensorValues values;
  values.ReadSensorValues(&dht, &hygro);
  values.pump_state = binary_states::OFF;
  display.Update(values);
}

/**
 * @brief Handles the rotary difference and routes 
 * it through to the display.
 * 
 * @param difference Rotary difference in increments. 
 */
auto HandleRotaryEncoderRotation(long difference) noexcept -> void {
}
