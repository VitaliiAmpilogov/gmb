#include "controller.h"
#include <iostream>

const std::size_t max_index = 2;

void Controller::ShowGameOver() const
{
  std::cout << "Game Over!";
  std::cout << "\n------------------------\n";
  std::cout << "Letters: ";
  for (auto& id : model.GetButtons()) {
    std::cout << static_cast<char>(id);
  }
  std::cout << "\n------------------------\n\n\n";
}

void Controller::ShowNewGame() const
{
  std::cout << "Guess 3 letters game started" << std::endl;
}

void Controller::Run() {
	while (true) {
		ShowNewGame();
		model.GenerateNewSequence();
		led_state_subject.SetData(LedStates{ LedState::GREEN, LedState::GREEN, LedState::GREEN });
		led_state_subject.NotifyAll();
		current_index = 0;
		while (current_index <= max_index) {
			auto id = button_view.GetPressedButton();
			auto led_state = Compare(id);
			if (LedState::GREEN == led_state) {
				++current_index;
			}
			auto states = led_state_subject.GetData();
			ShiftLedStates(states, led_state);
			led_state_subject.SetData(states);
			led_state_subject.NotifyAll();
		}
		ShowGameOver();
	}
}

LedState Controller::Compare(const ButtonId& id) const {
  if (model.GetButton(current_index) == id)
    return LedState::GREEN;

  if (model.InSequence(id))
    return LedState::YELLOW;
   
  return LedState::RED;
}

void Controller::ShiftLedStates(LedStates& states, LedState new_state) const
{
	for (auto i = states.size() - 1; i > 0; --i) {
		std::swap(states[i], states[i - 1]);
	}
	std::swap(states[0], new_state);
}
