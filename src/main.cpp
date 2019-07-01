#include <iostream>
#include "led_state.h"
#include "led_view.h"
#include "button_view.h"
#include "controller.h"

int main() try {
  LedView led_view;
  ButtonView button_view;
  Model model;
  Controller controller(model,button_view);
  controller.Register(led_view);
  controller.Run();
  return 0;
}
catch (...) {
	std::cout << "UNKNOWN EXCEPTION!" << std::endl;
	return 1;
}