#ifndef __CPD__
#define __CPD__

#include "./task/Task.h"
#include "./components/pir/PIR.h"

class CarPresenceDetector : Pir, Task {
public:
    CarPresenceDetector(int pin);

    bool isAnyone();

    void init();
    void tick();
    bool updateAndCheckTime(int millis);

private:
    int myPin = 0;
    unsigned long millis=0;
    unsigned long period = 200;
    bool anyone = false;
};

#endif