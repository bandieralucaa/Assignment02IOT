#ifndef __WM_BUTT__
#define __WM_BUTT__

#include "configs.h"

#include "./task/Task.h"
#include "./components/button/Button.h"

#include "Arduino.h"

class WashingMachineButton : public Button, public Task {
public:
    WashingMachineButton(int pin);

    bool isPressed();

    void init();
    void tick();

    bool updateAndCheckTime(int millis){
        bool res = false;
        this->millis += millis;
        if (this->millis >= this->period){
            res = true;
            this->millis = 0;
        }
        return res;
    };

private:
    int myPin = 0;
    bool pushed = false;
};

#endif