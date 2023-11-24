
#include "./components/pir/PIR.h"
#include "components/outputComponents/OutputManager.h"
#include "./PreEnteringWashDoneState.h"
#include <Arduino.h>

PreEnteringWashDoneState::PreEnteringWashDoneState(Gate* myGate){
    this->myGate = myGate;
}

void PreEnteringWashDoneState::init() {
    this->myGate->open();
}

StateName PreEnteringWashDoneState::changeState() {
    if (this->myGate->isOpen()){
        this->myGate->stop();
        return NONE;
    } else {
        return NONE;
    }
    
};