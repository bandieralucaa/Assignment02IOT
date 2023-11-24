#include "./components/pir/PIR.h"
#include "./components/outputComponents/OutputManager.h"
#include "./AfterEnteringWashDoneState.h"
#include <Arduino.h>

AfterEnteringWashDoneState::AfterEnteringWashDoneState(Gate* myGate) {
    this->myGate = myGate;
}

void AfterEnteringWashDoneState::init() {
    Serial.println("CHIUDI GATE");
    this->myGate->close();
}

StateName AfterEnteringWashDoneState::changeState() {
    if (this->myGate->isClose()) {
        this->myGate->stop();
        return NONE;
    } else {
        return NONE;
    }
}