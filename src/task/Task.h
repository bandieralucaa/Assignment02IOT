#ifndef __TASK__
#define __TASK__

#include "string.h"
#include <Arduino.h>

class Task {
    public:
    virtual void init();
    virtual void tick();

    virtual bool updateAndCheckTime(int millis){
        bool res = false;
        this->millis += millis;
        if (this->millis > this->period){
            res = true;
            this->millis = 0;
            // Serial.print("PIR: my turn!\n");
        }
        return res;
    };

protected:
    unsigned long millis=0;
    unsigned long period = 200;
    // String name = "";
};

#endif