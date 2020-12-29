#ifndef SRC_GLOBALS_HPP_
#define SRC_GLOBALS_HPP_

#include <stdint.h>
#include "Arduino.h"

using SensorValues = struct SensorValues_ {
  int soil_humidity;
  float air_humidity;
  float air_temperature;
  long heat_index;
  String pump_state;
};

#endif