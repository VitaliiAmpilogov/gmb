#ifndef LED_STATE_H_
#define LED_STATE_H_

#include <array>

enum class LedState {
  GREEN,
  YELLOW,
  RED
};

using LedStates = std::array<LedState,3>;

#endif  // LED_STATE_H_
