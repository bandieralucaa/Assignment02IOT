#include "./AfterWashingDoneState.h"

#ifdef DEBUG
#include <Arduino.h>
#endif

AfterWashingDoneState::AfterWashingDoneState(Gate* myGate, Light* l2, OutSender* out) {
    this->myGate = myGate;
    this->l2 = l2;
    this->out = out;
}

void AfterWashingDoneState::init() {
    #ifdef STATE_CHANGE_DEBUG
    Serial.println("AfterWashingDoneState");
    #endif
    this->myGate->close();
    this->l2->switchOff();
}

StateName AfterWashingDoneState::changeState() {
    if (this->myGate->isClose()) {
        this->myGate->stop();
        this->out->increaseWashedCar();
        return SLEEP_STATE;
    } else {
        return NONE;
    }
}