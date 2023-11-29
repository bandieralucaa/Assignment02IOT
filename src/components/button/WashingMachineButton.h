#ifndef __WM_BUTT__
#define __WM_BUTT__

#include "./task/Task.h"
#include "./components/button/Button.h"

#include "configs.h"

class WashingMachineButton : public Button, public Task {
public:
    WashingMachineButton(int pin);

    bool isPressed();

    void init();
    void tick();

private:
    int myPin = 0;
    bool pushed = false;
};


void awakeArduino();

#endif