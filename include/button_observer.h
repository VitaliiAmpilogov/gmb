#ifndef BUTTON_OBSERVER_H
#define BUTTON_OBSERVER_H

#include "iobserver.h"
#include "button_id.h"

class ButtonObserver : public IObserver<ButtonId> {
public:
	virtual void Notify(const ButtonId& button) override;
};

#endif  // BUTTON_OBSERVER_H
