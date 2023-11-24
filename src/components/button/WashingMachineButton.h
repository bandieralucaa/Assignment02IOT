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
    // bool updateAndCheckTime(int millis);

private:
    int myPin = 0;
    bool pushed = false;
    // unsigned long millis=0;
    // unsigned long period = 200;
};


void awakeArduino();

#endif