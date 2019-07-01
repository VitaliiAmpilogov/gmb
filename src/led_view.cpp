#include "led_view.h"
#include <iostream>

namespace {
	std::string LedStateToName(const LedState& state) {
		switch (state) {
		case LedState::GREEN :
			return "GREEN";
			break;
		case LedState::YELLOW :
			return "YELLOW";
			break;
		case LedState::RED :
			return "RED";
			break;
		default:
			return "UNKNOWN";
			break;
		}
	}
}

void LedView::Notify(const LedStates& led_states) {
  states = led_states;
  PrintStates();
}

void LedView::PrintStates() const {
  for(auto i = 0u; i < states.size(); ++i) {
    std::cout << "L" << i << ": " << LedStateToName(states[i]) << "\n";
  }
  std::cout << "\n";
}