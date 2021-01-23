#ifndef LIB_PUMP_PERESTALTIC_PUMP_HPP_
#define LIB_PUMP_PERESTALTIC_PUMP_HPP_

#include <stdint.h>
#include "globals.hpp"

class PerestalticPump6V {
 public:
  PerestalticPump6V();
  virtual ~PerestalticPump6V() = default;
  auto On() noexcept -> void;
  auto Off() noexcept -> void;

  /**
   * @brief Turns on pump until volume of water is pumped, then 
   * turns it off again. Is blocking.
   * 
   * @param amount_in_ml 
   */
  auto PumpingWater(uint16_t amount_in_ml) noexcept -> void;
  auto CurrentPumpState() noexcept -> PumpState;
  auto CurrentPumpStateString() noexcept -> const char*;

 private:
  PumpState current_state_;
  static constexpr uint8_t ML_PER_SECOND_ = 5;
};

#endif
