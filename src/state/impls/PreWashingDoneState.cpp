
#include "./components/pir/PIR.h"
#include "components/outputComponents/OutputManager.h"
#include "./PreWashingDoneState.h"
#include <Arduino.h>

PreWashingDoneState::PreWashingDoneState(Gate* myGate){
    this->myGate = myGate;
}

void PreWashingDoneState::init() {
    this->myGate->open();
}

StateName PreWashingDoneState::changeState() {
    if (this->myGate->isOpen()){
        this->myGate->stop();
        return WASHING_DONE_STATE;
    } else {
        return NONE;
    }
    
};