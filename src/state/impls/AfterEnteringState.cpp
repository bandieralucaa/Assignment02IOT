#include "./components/pir/PIR.h"
#include "./state/impls/AfterEnteringState.h"


AfterEnteringState::AfterEnteringState(Gate* myGate, LedExtTimered* blink) {
    this->myGate = myGate;
    this->blink = blink;
}

void AfterEnteringState::init() {
    #ifdef STATE_CHANGE_DEBUG
    Serial.println("AfterEnteringState");
    #endif

    this->blink->start();
    this->myGate->start();

    this->myGate->close();
    this->blink->canBlink(false);
    this->blink->switchOn();
}

StateName AfterEnteringState::changeState() {
    if (this->myGate->isClose()) {
        this->myGate->stopGate();
        return WAIT_CONFIRM_STATE;
    } else {
        return NONE;
    }
}