#include "./components/pir/PIR.h"
#include "./components/outputComponents/OutputManager.h"
#include "./AfterWashingDoneState.h"
#include <Arduino.h>

AfterWashingDoneState::AfterWashingDoneState(Gate* myGate) {
    this->myGate = myGate;
}

void AfterWashingDoneState::init() {
    Serial.println("CHIUDI GATE");
    this->myGate->close();
}

StateName AfterWashingDoneState::changeState() {
    if (this->myGate->isClose()) {
        this->myGate->stop();
        return SLEEP_STATE;
    } else {
        return NONE;
    }
}