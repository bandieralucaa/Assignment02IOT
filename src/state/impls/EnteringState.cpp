
#include "components/outputComponents/OutputManager.h"
#include "./state/impls/EnteringState.h"

EnteringState::EnteringState(Servomotor* myMotor){
    this->myMotor = myMotor;
}

void EnteringState::init() {
    
}

StateName EnteringState::changeState() {
    if (this->myMotor->isOpen()){
        return ENTERING_STATE;
    } else {
        return NONE;
    }
};