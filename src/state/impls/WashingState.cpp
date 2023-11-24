#include "WashingState.h"

#include "Arduino.h"

static volatile bool isOver;

WashingState::WashingState(Timer<3>* clock){
    this->clock = clock;
}

static void* tt;

bool isOverTime2(void*){
    isOver = true;
    return true;
}

void WashingState::init() {
    tt = this->clock->every(N3_TIME, isOverTime2);
}


void WashingState::flushTimer(){
    // Serial.print("\n");
    // Serial.print(this->clock->size());
    // Serial.print("\n");
    this->clock->cancel(tt);
    // Serial.print(this->clock->size());
    // Serial.print("\n");
}


StateName WashingState::changeState() {
    if (isOver) {
        flushTimer();
        return NONE;
    } else {
        return NONE;
    }
};