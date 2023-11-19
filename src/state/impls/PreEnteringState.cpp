
#include "./components/pir/PIR.h"
#include "components/outputComponents/OutputManager.h"
#include "./state/impls/PreEnteringState.h"

PreEnteringState::PreEnteringState(Gate* myGate){
    this->myGate = myGate;
}

void PreEnteringState::init() {
    this->myGate->open();
}

StateName PreEnteringState::changeState() {
    if (myGate->isOpen()){
        myGate->stop();
        return ENTERING_STATE;
    } else {
        return NONE;
    }
};