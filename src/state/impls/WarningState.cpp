
#include "./state/impls/WarningState.h"

#include "Arduino.h"

static volatile bool isOver;

WarningState::WarningState(TemperatureSensor* tempSens, Cooldown* globalClock, Cooldown* washingClock){
    this->tempSens = tempSens;
    this->globalClock = globalClock;
    this->washingClock = washingClock;

}

// static void* tt;

// bool isOverTime1(void*){
//     isOver = true;
//     return true;
// }

void WarningState::init() {
    #ifdef STATE_CHANGE_DEBUG
    Serial.print("WarningState");
    #endif
    this->globalClock->format(N4_TIME);
    //tt = this->clock->every(N2_TIME, isOverTime1);
}


void WarningState::flushTimer(){
    // Serial.print("\n");
    // Serial.print(this->clock->size());
    // Serial.print("\n");
    // this->clock->cancel(tt);
    // Serial.print(this->clock->size());
    // Serial.print("\n");
}


StateName WarningState::changeState() {
    if (!this->tempSens->isOverHeat()){
        //flushTimer();
        return WASHING_STATE;
    } else if (this->globalClock->isOver()) {
        //flushTimer();
        this->washingClock->pause();
        return HOT_STATE;
    } else {
        return NONE;
    }
};