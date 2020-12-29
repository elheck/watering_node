#include <Arduino.h>
#include "dht_sensor.hpp"
#include "globals.hpp"
#include "oled.hpp"
#include "setting.hpp"
#include "soil_moisture.hpp"

DHTSensor dht(settings::dht::DHT_PIN);
SoilMoistureSensor hygro(settings::hygro::SOIL_HUMIDITY_PIN);
Oled oled(settings::oled::SCL_PIN, settings::oled::SDA_PIN, settings::oled::CS_PIN,
          settings::oled::DC_PIN, settings::oled::RESET_PIN);

void setup(void) {
  dht.Begin();
  oled.Begin();
}

void loop(void) {
  SensorValues values;
  values.air_humidity = dht.GetHumidity();
  values.air_temperature = dht.GetTemperature();
  values.heat_index = dht.GetHeatIndex();
  values.soil_humidity = hygro.GetSoilMoistureInPercent();
  values.pump_state = "off";
  oled.UpdateScreen(values);
}
