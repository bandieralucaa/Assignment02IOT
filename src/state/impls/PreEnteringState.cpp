
#include "./components/pir/PIR.h"
#include "components/outputComponents/OutputManager.h"
#include "./state/impls/PreEnteringState.h"
#include "./task/TimerScheduler.h"
#include <Arduino.h>
// TimerScheduler* timer;

PreEnteringState::PreEnteringState(Gate* myGate){
    this->myGate = myGate;
}

void PreEnteringState::init() {
    Serial.print("ççççç\nPreEnteringState\nççççççççççç");
    this->myGate->open();
}

StateName PreEnteringState::changeState() {
    if (this->myGate->isOpen()){
        // timer->schedule();
        this->myGate->stop();
        return ENTERING_STATE;
    } else {
        return NONE;
    }
    
};