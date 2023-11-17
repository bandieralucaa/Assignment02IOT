// #include "PIR.h"
// #include "./task/Task.h"
#include <Arduino.h>
#include "CarPresenceDetector.h"


CarPresenceDetector::CarPresenceDetector(int pin) {
        this->myPin = pin;
}

<<<<<<< HEAD
    bool isAnyone(){
=======
bool Pir::isAnyone(){
>>>>>>> main
        return isAnyone;
}

void Task::init() {}

void CarPresenceDetector::tick() {
    if (digitalRead(myPin) == HIGH) { //se c'è qualcuno
        isAnyone = true;
    } else {
        isAnyone = false;
    }
}
    
bool CarPresenceDetector::updateAndCheckTIme(int millis) {
    bool res = false;
    this->millis += millis;
    if (this->millis>period){
        res = true;
        this->millis = 0;
    }
    return res;
}
