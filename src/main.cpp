#include <Arduino.h>
#include "dht_sensor.hpp"
#include "globals.hpp"
#include "oled.hpp"
#include "setting.hpp"
#include "soil_moisture.hpp"

DHTSensor dht(settings::dht::DHT_PIN);
SoilMoistureSensor hygro(settings::hygro::SOIL_HUMIDITY_PIN);
Oled display;

void setup(void) {
  dht.Begin();
  display.Begin();
}

void loop(void) {
  SensorValues values;
  values.ReadSensorValues(&dht, &hygro);
  values.pump_state = pump_state::OFF;
}
