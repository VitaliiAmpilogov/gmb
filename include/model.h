#ifndef MODEL_H_
#define MODEL_H_

#include "button_id.h"
#include <array>

class Model {
  public:
	  using Buttons = std::array<ButtonId, 3>;
    ButtonId GetButton(std::size_t index) const;
	  bool InSequence(ButtonId id) const;
    void GenerateNewSequence();
	  const Buttons& GetButtons() const {
		  return buttons;
	  }
  private:
    Buttons buttons;
};

#endif  // MODEL_H_
