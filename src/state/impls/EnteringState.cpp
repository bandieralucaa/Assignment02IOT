#include "./state/impls/EnteringState.h"

EnteringState::EnteringState(CarDistanceDetector* sonar){
    this->sonar = sonar;
}


void EnteringState::init() {
    #ifdef STATE_CHANGE_DEBUG
    Serial.print("EnteringState");
    #endif
    this->sonar->start();
}

StateName EnteringState::changeState() {
    if (this->sonar->isUnderMin()) {
        return WAIT_ENTERING_STATE;
    } else {
        return NONE;
    }
};