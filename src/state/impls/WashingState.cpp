#include "WashingState.h"

#include "Arduino.h"

static volatile bool isOver;

WashingState::WashingState(TemperatureSensor* tempSens, Cooldown* clock){
    this->tempSens = tempSens;
    this->clock = clock;
}

// static void* tt;

// bool isOverTime2(void*){
//     isOver = true;
//     return true;
// }

void WashingState::init() {
    Serial.println("Washing state");
    this->clock->format(N3_TIME);
    //tt = this->clock->every(N3_TIME, isOverTime2);
}


void WashingState::flushTimer(){
    // Serial.print("\n");
    // Serial.print(this->clock->size());
    // Serial.print("\n");
    //this->clock->cancel(tt);
    // Serial.print(this->clock->size());
    // Serial.print("\n");
}


StateName WashingState::changeState() {
    if(this->tempSens->isOverHeat()) {
        return WARNING_STATE;
    } else if (this->clock->isOver()) {
        //flushTimer();
        return PRE_WASHING_DONE_STATE;
    } else {
        return NONE;
    }
};