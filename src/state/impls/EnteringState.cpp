
#include "components/outputComponents/OutputManager.h"
#include "./state/impls/EnteringState.h"
#include <Arduino.h>

EnteringState::EnteringState(){
    
}

void EnteringState::init() {
    Serial.print("OOKK");
}

StateName EnteringState::changeState() {
    if (this->myMotor->isOpen()){
        return NONE;
    } else {
        return NONE;
    }
};