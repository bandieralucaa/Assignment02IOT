#ifndef __CPD__
#define __CPD__

#include "./task/Task.h"
#include "./components/pir/PIR.h"

#include <avr/sleep.h>

#include "configs.h"

#include "Arduino.h"

class CarPresenceDetector : public Pir, public Task {
public:
    CarPresenceDetector(int pin);

    bool isAnyone();

    void init();
    void tick();

private:
    int myPin;
    bool anyone = false;
};


void awakeArduino();

#endif