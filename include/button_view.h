#ifndef BUTTON_VIEW_H
#define BUTTON_VIEW_H

#include "button_id.h"

class ButtonView {
  public:
	  ButtonId GetPressedButton() const;
};

#endif  // BUTTON_VIEW_H