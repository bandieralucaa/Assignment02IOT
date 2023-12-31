#include "./AfterWashingDoneState.h"


AfterWashingDoneState::AfterWashingDoneState(Gate* myGate, Light* l2, OutSender* out) {
    this->myGate = myGate;
    this->l2 = l2;
    this->out = out;
}

void AfterWashingDoneState::init() {
    #ifdef STATE_CHANGE_DEBUG
    Serial.println("AfterWashingDoneState");
    #endif

    this->out->increaseWashedCar();
    this->out->updateState(STATE1, false);
    
    this->myGate->start();
    this->myGate->close();

    this->l2->switchOff();
}

StateName AfterWashingDoneState::changeState() {
    if (this->myGate->isClose()) {
        this->myGate->stop();
        return SLEEP_STATE;
    } else {
        return NONE;
    }
}