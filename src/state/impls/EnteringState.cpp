#include "./state/impls/EnteringState.h"

#ifdef DEBUG
#include "Arduino.h"
#endif

EnteringState::EnteringState(CarDistanceDetector* sonar, Cooldown* timer){
    this->sonar = sonar;
    this->timer = timer;
}

void EnteringState::init() {
    #ifdef STATE_CHANGE_DEBUG
    Serial.print("EnteringState");
    #endif
    this->sonar->start();
    this->timer->format(MYTIME1);
}

StateName EnteringState::changeState() {
    if (this->sonar->isUnderMin()) {
        return WAIT_ENTERING_STATE;
    } else if (this->timer->isOver()){
        return ESCAPING_CAR_STATE;
    } else {
        return NONE;
    }
};