#ifndef LED_VIEW_H
#define LED_VIEW_H

#include "iobserver.h"
#include "led_state.h"

class LedView final : public IObserver<LedStates> {
  public:
    LedView(){}
    virtual void Notify(const LedStates& led_states) override;
  private:
    void PrintStates() const;
    LedStates states;
};

#endif  // LED_VIEW_H