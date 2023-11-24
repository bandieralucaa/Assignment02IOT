#include "./state/impls/LeftingState.h"

#include "Arduino.h"

static volatile bool isOver;

LeftingState::LeftingState(CarDistanceDetector* sonar, Timer<3>* clock){
    this->sonar = sonar;
    this->clock = clock;
}

static void* tt;

bool isOverTime3(void*){
    isOver = true;
    return true;
}

void LeftingState::init() {
    Serial.print("LeftingState");

    tt = this->clock->every(N2_TIME, isOverTime3);
}


void LeftingState::flushTimer(){
    Serial.print("\n");
    Serial.print(this->clock->size());
    Serial.print("\n");
    this->clock->cancel(tt);
    Serial.print(this->clock->size());
    Serial.print("\n");
}


StateName LeftingState::changeState() {
    if (!this->sonar->isAboveMax()){
        flushTimer();
        return NONE; //WHASING_DONE_STATE
    } else  if (isOver) {
        flushTimer();
        return AFTER_WASHING_DONE_STATE; //AFTER_WASHING_DONE_STATE
    } else {
        return NONE;
    }
};