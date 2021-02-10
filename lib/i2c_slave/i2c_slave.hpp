#ifndef LIB_I2C_SLAVE_I2C_SLAVE_HPP_
#define LIB_I2C_SLAVE_I2C_SLAVE_HPP_

class I2cSlave {
 public:
  explicit I2cSlave();
  virtual ~I2cSlave() = default;
};

#endif