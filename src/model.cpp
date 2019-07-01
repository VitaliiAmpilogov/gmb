#include "model.h"
#include <random>
#include <algorithm>

ButtonId Model::GetButton(std::size_t index) const {
  if(index > buttons.size()-1) {
    throw std::out_of_range("Index is out of range");
  }      
  return buttons[index];
}

bool Model::InSequence(ButtonId id) const
{
	return std::find(buttons.cbegin(), buttons.cend(), id) != buttons.cend();
}

void Model::GenerateNewSequence() {
  std::random_device device;
  std::mt19937 engine(device());
  std::uniform_int_distribution<> distribution(static_cast<int>(ButtonId::A), static_cast<int>(ButtonId::C));
  for(auto& button : buttons) {
    button = static_cast<ButtonId>(distribution(engine));
  }
}
