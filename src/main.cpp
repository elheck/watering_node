#include <Arduino.h>
#include "dht_sensor.hpp"
#include "globals.hpp"
#include "i2c_slave.hpp"
#include "perestaltic_pump.hpp"
#include "rotary_encoder.hpp"
#include "setting.hpp"
#include "soil_moisture.hpp"

auto HandleRotaryEncoderRotation(long difference) noexcept -> void;

DHTSensor dht(settings::dht::DHT_PIN);
SoilMoistureSensor hygro;
RotaryEncoder rotary_encoder;
PerestalticPump6V pump;

void setup(void) {
  Serial.begin(9600);
  Serial.println("Setup start");
  dht.Begin();
}

void loop(void) {
  auto difference = rotary_encoder.GetDifference();
  if (difference != 0) {
    HandleRotaryEncoderRotation(difference);
  }
  SensorValues values;
  values.ReadSensorValues(&dht, &hygro);
  values.pump_state = binary_states::OFF;
}

/**
 * @brief Handles the rotary difference and routes 
 * it through to the display.
 * 
 * @param difference Rotary difference in increments. 
 */
auto HandleRotaryEncoderRotation(long difference) noexcept -> void {
}
