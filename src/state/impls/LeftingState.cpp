#include "./state/impls/LeftingState.h"

#include "Arduino.h"

static volatile bool isOver;

LeftingState::LeftingState(CarDistanceDetector* sonar, Cooldown* clock){
    this->sonar = sonar;
    this->clock = clock;
}

static void* tt;

bool isOverTime3(void*){
    isOver = true;
    return true;
}

void LeftingState::init() {
    #ifdef STATE_CHANGE_DEBUG
    Serial.print("LeftingState");
    #endif
    this->clock->format(N2_TIME);

    // tt = this->clock->every(N2_TIME, isOverTime3);
}


void LeftingState::flushTimer(){
    // Serial.print("\n");
    // Serial.print(this->clock->size());
    // Serial.print("\n");
    // this->clock->cancel(tt);
    // Serial.print(this->clock->size());
    // Serial.print("\n");
}


StateName LeftingState::changeState() {
    if (!this->sonar->isAboveMax()){
        //flushTimer();
        return WASHING_DONE_STATE; //WHASING_DONE_STATE
    } else  if (this->clock->isOver()) {
        //flushTimer();
        return AFTER_WASHING_DONE_STATE; //AFTER_WASHING_DONE_STATE
    } else {
        return NONE;
    }
};