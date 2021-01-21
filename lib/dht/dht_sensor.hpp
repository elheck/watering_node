#ifndef LIB_DHT_SENSOR_HPP_
#define LIB_DHT_SENSOR_HPP_

#include <stdint.h>
#include "DHT.h"

class DHTSensor {
 public:
  DHTSensor() = delete;
  ~DHTSensor() = default;
  explicit DHTSensor(uint8_t dht_pin);

  /**
   * @brief Start the dht11 sensor reading
   * 
   */
  auto Begin() noexcept -> void;

  /**
   * @brief Get the temperature value in Celcius from the sensor
   * 
   * @return current sensor value 
   */
  auto GetTemperature() noexcept -> const float;

  /**
   * @brief Get the relative humidity of the air in percent 
   * 
   * @return current humidy value 
   */
  auto GetHumidity() noexcept -> const float;

  /**
   * @brief Calculate and get the relativ heatindex 
   * calculated after the formula at https://en.wikipedia.org/wiki/Heat_index
   * 
   * @return current heat index 
   */
  auto GetHeatIndex() noexcept -> const float;

 private:
  DHT dht11_;
};

#endif