// #include "PIR.h"
// #include "./task/Task.h"
#include <Arduino.h>
#include "CarPresenceDetector.h"

class CarPresenceDetector : Pir, Task {
public:

    int myPin = 0;
    unsigned long millis;

    unsigned long period = 200;

    bool isAnyone = false;

    CarPresenceDetector(int pin){
        this->myPin = pin;
    }

    bool isAnyone(){
        return isAnyone;
    }

    void init(){

    }

    void tick(){
        if (digitalRead(myPin) == HIGH) { //se c'è qualcuno
            isAnyone = true;
        } else {
            isAnyone = false;
        }
    }
    
    bool updateAndCheckTIme(int millis) {
        this->millis += millis;
    }

};