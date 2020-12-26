#include <Arduino.h>
#include "dht_sensor.hpp"

static constexpr int DHT_PIN = 5;

DHTSensor dht(DHT_PIN);

void setup(void) {
  dht.Begin();
}

void loop(void) {
  auto humidity = dht.GetHumidity();
  auto temperature = dht.GetTemperature();
  auto heat_index = dht.GetHeatIndex();
}
