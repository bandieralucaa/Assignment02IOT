#include "./components/pir/PIR.h"
#include "./components/outputComponents/OutputManager.h"
#include "./state/impls/AfterEnteringState.h"
#include <Arduino.h>

AfterEnteringState::AfterEnteringState(Gate* myGate) {
    this->myGate = myGate;
}

void AfterEnteringState::init() {
    Serial.println("CHIUDI GATEEEEE");
    this->myGate->close();
}

StateName AfterEnteringState::changeState() {
    if (this->myGate->isClose()) {
        this->myGate->stop();
        return WAIT_ENTERING_STATE;
    } else {
        return NONE;
    }
}