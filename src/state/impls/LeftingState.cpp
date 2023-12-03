#include "./state/impls/LeftingState.h"

#ifdef DEBUG
#include "Arduino.h"
#endif

LeftingState::LeftingState(CarDistanceDetector* sonar, Cooldown* clock){
    this->sonar = sonar;
    this->clock = clock;
}

void LeftingState::init() {
    #ifdef STATE_CHANGE_DEBUG
    Serial.print("LeftingState");
    #endif
    this->sonar->start();
    this->clock->format(N4_TIME);
}

StateName LeftingState::changeState() {
    if (!this->sonar->isAboveMax()){
        return WASHING_DONE_STATE; 
    } else  if (this->clock->isOver()) {
        return AFTER_WASHING_DONE_STATE; 
    } else {
        #ifdef SONAR_DEBUG_LEFTING
        Serial.println("---> " + (String) this->sonar->getDistance());
        #endif
        return NONE;
    }
};