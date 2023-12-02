#include "./state/impls/WaitEnteringState.h"

#include "Arduino.h"

WaitEnteringState::WaitEnteringState(CarDistanceDetector* sonar, Cooldown* clock){
    this->sonar = sonar;
    this->clock = clock;
}

void WaitEnteringState::init() {
    #ifdef STATE_CHANGE_DEBUG
    Serial.print("WaitEnteringState");
    #endif
    this->sonar->start();

    this->clock->format(N2_TIME);
}


StateName WaitEnteringState::changeState() {
    if (!this->sonar->isUnderMin()){
        return ENTERING_STATE;
    } else  if (this->clock->isOver()) {
        return AFTER_ENTERING_STATE;
    } else {
        return NONE;
    }
};