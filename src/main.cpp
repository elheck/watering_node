#include <Arduino.h>
#include "dht_sensor.hpp"
#include "globals.hpp"
#include "i2c_slave.hpp"
#include "perestaltic_pump.hpp"
#include "setting.hpp"
#include "soil_moisture.hpp"

DHTSensor dht(settings::dht::DHT_PIN);
SoilMoistureSensor hygro;
PerestalticPump6V pump;
I2cSlave i2c_slave;

void setup(void) {
  Serial.begin(9600);
  Serial.println("Setup start");
  dht.Begin();
  i2c_slave.Begin();
}

void loop(void) {
  SensorValues values;
  values.ReadSensorValues(&dht, &hygro);
  values.pump_state = binary_states::OFF;
}
