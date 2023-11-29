#include "CarPresenceDetector.h"

CarPresenceDetector::CarPresenceDetector(int pin) {
    this->myPin = pin;
    attachInterrupt(digitalPinToInterrupt(pin),awakeArduino,RISING);
    this->period = PIR_PERIOD;
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

void awakeArduino(){
    sleep_disable(); 
}