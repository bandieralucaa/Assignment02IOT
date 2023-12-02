#include "./WashingDoneState.h"
#include "components/led/Led.h"

#ifdef DEBUG
#include "Arduino.h"
#endif

WashingDoneState::WashingDoneState(LedExtTimered* blinkLed, CarDistanceDetector* sonar) {
    this->blinkLed = blinkLed;
    this->sonar = sonar;
}

void WashingDoneState::init() {
    #ifdef STATE_CHANGE_DEBUG
    Serial.println("WashingDoneState");
    #endif

    this->blinkLed->start();
    this->sonar->start();

    this->blinkLed->switchOff();
}

StateName WashingDoneState::changeState() {
    if (this->sonar->isAboveMax()){
        return LEFTING_STATE;
    } else {
        #ifdef SONAR_DEBUG_LEFTING
        Serial.println("---> " + (String) this->sonar->getDistance());
        #endif
        return NONE;
    }
    
}

    