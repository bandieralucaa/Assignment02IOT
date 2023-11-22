
#include "./components/pir/PIR.h"
#include "components/outputComponents/OutputManager.h"
#include "./state/impls/PreEnteringState.h"
#include "./task/TimerScheduler.h"

// TimerScheduler* timer;

PreEnteringState::PreEnteringState(Gate* myGate){
    this->myGate = myGate;
}

void PreEnteringState::init() {
    // timer->init(3000);
    this->myGate->open();
}

StateName PreEnteringState::changeState() {
    if (myGate->isOpen()){
        // timer->schedule();
        myGate->stop();
        return ENTERING_STATE;
    } else {
        return NONE;
    }
};