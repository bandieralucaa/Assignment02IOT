#include "components/outputComponents/OutputManager.h"
#include "./WashingDoneState.h"
#include "components/led/Led.h"
#include "Arduino.h"

WashingDoneState::WashingDoneState(LedExtTimered* blinkLed, CarDistanceDetector* sonar) {
    this->blinkLed = blinkLed;
    this->sonar = sonar;
}

void WashingDoneState::init() {
    this->blinkLed->switchOff();
}

StateName WashingDoneState::changeState() {
    if (this->sonar->isAboveMax()){
        return LEFTING_STATE;
    } else {
        return NONE;
    }
    
}

    