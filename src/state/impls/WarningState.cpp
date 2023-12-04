#include "WarningState.h"

#include "Arduino.h"

static volatile bool isOver;

WarningState::WarningState(TemperatureSensorTimered* tempSens, Cooldown* globalClock, Cooldown* washingClock, LcdMonitor* lcd, OutSender* out){
    this->tempSens = tempSens;
    this->globalClock = globalClock;
    this->washingClock = washingClock;
    this->lcd = lcd;
    this->out = out;

}

void WarningState::init() {
    #ifdef STATE_CHANGE_DEBUG
    Serial.print("WarningState");
    #endif
    this->globalClock->format(N4_TIME);
    this->tempSens->start();
}


StateName WarningState::changeState() {
    if (!this->tempSens->isOverHeat()){
        return WASHING_STATE;
    } else if (this->globalClock->isOver()) {
        this->washingClock->pause();
        return HOT_STATE;
    } else {
        if (this->lcd->changeProgBar(this->washingClock->percentageComplete())){
            this->lcd->printProgBar();
        }
        this->out->sendTemperature();
        return NONE;
    }
};