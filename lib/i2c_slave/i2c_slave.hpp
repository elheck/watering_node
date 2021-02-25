#ifndef LIB_I2C_SLAVE_I2C_SLAVE_HPP_
#define LIB_I2C_SLAVE_I2C_SLAVE_HPP_

#include <stdint.h>
#include "globals.hpp"

class I2cSlave {
 public:
  I2cSlave() = default;
  virtual ~I2cSlave() = default;
  auto Begin() noexcept -> void;
  static volatile I2CSlaveCommand current_option;

 private:
  static auto OnRequestedEvent() noexcept -> void;
  static auto OnReceivedEvent(const int how_many) noexcept -> void;
};

#endif