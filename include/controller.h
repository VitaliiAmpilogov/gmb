#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "led_state.h"
#include "button_view.h"
#include "subject.h"
#include "iobserver.h"
#include "model.h"

class Controller final {
  public:
    Controller(Model& _model, ButtonView& _button_view)
      : model{_model},
		  button_view{_button_view}
	  {}
	  void Register(IObserver<LedStates>& observer) {
		  led_state_subject.Register(observer);
	  }
	  void Run();
  private:
	  void ShowGameOver() const;
	  void ShowNewGame() const;
    LedState Compare(const ButtonId& id) const;
	  void ShiftLedStates(LedStates& states, LedState new_state) const;
    Model& model;
	  ButtonView& button_view;
	  Subject<LedStates> led_state_subject;
	  std::size_t current_index{ 0 };
};

#endif  // CONTROLLER_H