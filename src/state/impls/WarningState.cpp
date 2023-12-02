
#include "./state/impls/WarningState.h"

#include "Arduino.h"

static volatile bool isOver;

WarningState::WarningState(TemperatureSensor* tempSens, Cooldown* globalClock, Cooldown* washingClock, LcdMonitor* lcd){
    this->tempSens = tempSens;
    this->globalClock = globalClock;
    this->washingClock = washingClock;
    this->lcd = lcd;

}

void WarningState::init() {
    #ifdef STATE_CHANGE_DEBUG
    Serial.print("WarningState");
    #endif
    this->globalClock->format(N4_TIME);
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
        if (this->lcd->changeProgBar(this->washingClock->percentageComplete())){
            this->lcd->printProgBar();
        }
        return NONE;
    }
};