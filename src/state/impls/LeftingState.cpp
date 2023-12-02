#include "./state/impls/LeftingState.h"

#include "Arduino.h"

// static volatile bool isOver;

LeftingState::LeftingState(CarDistanceDetector* sonar, Cooldown* clock){
    this->sonar = sonar;
    this->clock = clock;
}

void LeftingState::init() {
    #ifdef STATE_CHANGE_DEBUG
    Serial.print("LeftingState");
    #endif
    this->sonar->start();
    this->clock->format(N2_TIME);

    // tt = this->clock->every(N2_TIME, isOverTime3);
}

StateName LeftingState::changeState() {
    if (!this->sonar->isAboveMax()){
        
        //flushTimer();
        return WASHING_DONE_STATE; //WHASING_DONE_STATE
    } else  if (this->clock->isOver()) {
        //flushTimer();
        return AFTER_WASHING_DONE_STATE; //AFTER_WASHING_DONE_STATE
    } else {
        #ifdef SONAR_DEBUG_LEFTING
        Serial.println("---> " + (String) this->sonar->getDistance());
        #endif
        return NONE;
    }
};