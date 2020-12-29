#include <Arduino.h>
#include "dht_sensor.hpp"
#include "globals.hpp"
#include "oled.hpp"

static constexpr int DHT_PIN = 5;
static constexpr int SCL_PIN = 13;
static constexpr int SDA_PIN = 11;
static constexpr int CS_PIN = 10;
static constexpr int DC_PIN = 9;
static constexpr int RESET_PIN = 8;

DHTSensor dht(DHT_PIN);
Oled oled(SCL_PIN, SDA_PIN, CS_PIN, DC_PIN, RESET_PIN);

void setup(void) {
  dht.Begin();
  oled.Begin();
}

void loop(void) {
  SensorValues values;
  values.air_humidity = dht.GetHumidity();
  values.air_temperature = dht.GetTemperature();
  values.heat_index = dht.GetHeatIndex();
  values.soil_humidity = 0;
  values.pump_state = "off";
  oled.UpdateScreen(values);
}
