#ifndef LIB_ENCODER_ROTARY_ENCODER_HPP_
#define LIB_ENCODER_ROTARY_ENCODER_HPP_

#include <Encoder.h>
#include "setting.hpp"

class RotaryEncoder {
 public:
  RotaryEncoder();
  virtual ~RotaryEncoder() = default;

  /**
   * @brief Get the rotational difference 
   * between the current and last request 
   * in increments.
   * 
   * @return 0 if no difference was detected
   *         difference in any other case 
   */
  auto GetDifference() noexcept -> long;

 private:
  static constexpr long BASE_POSITION = 0;
  Encoder encoder_;
};

#endif