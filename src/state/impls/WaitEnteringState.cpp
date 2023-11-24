


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
  //  Serial.print("WaitEnteringState");
    this->blinkLed->switchOn();
    this->blinkLed->setFading(5);
    this->blinkLed->init();

    tt = this->clock->every(N2_TIME, isOverTime1);
}


void WaitEnteringState::flushTimer(){
    this->clock->cancel(tt);
}


StateName WaitEnteringState::changeState() {
    if (!this->sonar->isUnderMin()){
        return ENTERING_STATE;
    } else  if (isOver) {
       // Serial.print("non va");
        return ENTERING_STATE;
    } else {
        return NONE;
    }
};