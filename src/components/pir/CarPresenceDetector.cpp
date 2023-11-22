// #include "PIR.h"
// #include "./task/Task.h"
#include <Arduino.h>
#include <avr/sleep.h>
#include "CarPresenceDetector.h"


CarPresenceDetector::CarPresenceDetector(int pin) {
    this->myPin = pin;
    attachInterrupt(digitalPinToInterrupt(pin),awakeArduino,CHANGE);
    this->period = 300;
    // this->name = "PIR";
}

bool CarPresenceDetector::isAnyone(){
    return anyone;
}

void CarPresenceDetector::init() {}

void CarPresenceDetector::tick() {
    if (digitalRead(myPin) == HIGH) { //se c'è qualcuno
        anyone = true;
    } else {
        anyone = false;
    }
}
    
// bool CarPresenceDetector::updateAndCheckTime(int millis) {
//     bool res = false;
//     this->millis += millis;
//     if (this->millis>period){
//         res = true;
//         this->millis = 0;
//     }
//     return res;
// }

void awakeArduino(){
    sleep_disable(); 
}