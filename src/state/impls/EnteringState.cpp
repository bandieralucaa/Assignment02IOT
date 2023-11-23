
#include "components/outputComponents/OutputManager.h"
#include "./state/impls/EnteringState.h"

EnteringState::EnteringState(LedExtTimered* blinkLed, CarDistanceDetector* sonar){
    this->blinkLed = blinkLed;
    this->sonar = sonar;
}

void EnteringState::init() {
    Serial.print("EnteringState");
    this->blinkLed->switchOn();
    this->blinkLed->setFading(5);
    this->blinkLed->init();
}

StateName EnteringState::changeState() {
    if (this->sonar->isUnderMin()){
        return WAIT_ENTERING_STATE;
    } else {
        return NONE;
    }
};