


#include "components/outputComponents/OutputManager.h"
#include "./state/impls/WaitEnteringState.h"

#include "Arduino.h"

static volatile bool isOver;

WaitEnteringState::WaitEnteringState(LedExtTimered* blinkLed, CarDistanceDetector* sonar, Timer<3>* clock){
    this->blinkLed = blinkLed;
    this->sonar = sonar;
    this->clock = clock;
}

static void* tt;

bool isOverTime1(void*){
    isOver = true;
    return true;
}

void WaitEnteringState::init() {
    Serial.print("WaitEnteringState");
    this->blinkLed->switchOn();
    this->blinkLed->setFading(5);
    this->blinkLed->init();

    //tt = this->clock->every(N2_TIME, isOverTime1);
}


void WaitEnteringState::flushTimer(){
    Serial.print("\n");
    Serial.print(this->clock->size());
    Serial.print("\n");
    //this->clock->cancel(tt);
    Serial.print(this->clock->size());
    Serial.print("\n");
}


StateName WaitEnteringState::changeState() {
    if (!this->sonar->isUnderMin()){
        flushTimer();
        return ENTERING_STATE;
    } else  if (isOver) {
        flushTimer();
        Serial.print("NON VALE\n");
        return ENTERING_STATE;
    } else {
        return NONE;
    }
};