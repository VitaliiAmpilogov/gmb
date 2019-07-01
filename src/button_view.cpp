#include "button_view.h"
#include <iostream>

ButtonId ButtonView::GetPressedButton() {
  char entry = '\0';
  bool entered = false;
  ButtonId id;
  std::cout << "A,B or C? >";
  do {
	std::cin.get(entry);
	id = static_cast<ButtonId>(entry);
  } while (!(id == ButtonId::A || id == ButtonId::B || id == ButtonId::C));
  return id;
}