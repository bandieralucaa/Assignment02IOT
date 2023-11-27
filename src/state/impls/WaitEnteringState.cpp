#include "./state/impls/WaitEnteringState.h"

#include "Arduino.h"

// static volatile bool isOver;

WaitEnteringState::WaitEnteringState(CarDistanceDetector* sonar, Cooldown* clock){
    this->sonar = sonar;
    this->clock = clock;
}

// static void* tt;

// bool isOverTime1(void*){
//     isOver = true;
//     return true;
// }

void WaitEnteringState::init() {
    #ifdef STATE_CHANGE_DEBUG
    Serial.print("WaitEnteringState");
    #endif
    // this->blinkLed->switchOn();
    // this->blinkLed->setFading(5);
    // this->blinkLed->init();

    this->clock->format(N2_TIME);
    //tt = this->clock->every(N2_TIME, isOverTime1);
}


// void WaitEnteringState::flushTimer(){
//     Serial.print("\n");
//     Serial.print(this->clock->size());
//     Serial.print("\n");
//     this->clock->cancel(tt);
//     Serial.print(this->clock->size());
//     Serial.print("\n");
// }


StateName WaitEnteringState::changeState() {
    if (!this->sonar->isUnderMin()){
        //flushTimer();
        return ENTERING_STATE;
    } else  if (this->clock->isOver()) {
        //flushTimer();
        return AFTER_ENTERING_STATE;
    } else {
        return NONE;
    }
};