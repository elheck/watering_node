#include "i2c_slave.hpp"
#include "Wire.h"
#include "setting.hpp"

auto I2cSlave::Begin() noexcept -> void {
  Wire.begin(settings::i2c_slave::OWN_I2C_ADDRESS);
  Wire.onReceive(I2cSlave::OnReceivedEvent);
  Wire.onRequest(I2cSlave::OnRequestedEvent);
}

volatile I2CSlaveCommand I2cSlave::current_option = I2CSlaveCommand::NONE;

auto I2cSlave::OnReceivedEvent(const int how_many) noexcept -> void {
  if (how_many == sizeof(uint8_t)) {
    I2cSlave::current_option = static_cast<I2CSlaveCommand>(Wire.read());
  }
}

auto I2cSlave::OnRequestedEvent() noexcept -> void {
  //sending values goes here
}