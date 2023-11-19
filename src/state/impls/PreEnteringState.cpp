
#include "./components/pir/PIR.h"
#include "components/outputComponents/OutputManager.h"
#include "./state/impls/EnteringState.h"

EnteringState::EnteringState(OutputManager* o, Pir* awakePir){
    myPir = awakePir;
    this->o = o;
}

void EnteringState::init() {
    o->printOut("HELO\n");
}

StateName EnteringState::changeState() {
    if (!myPir->isAnyone()){
        return SLEEP_STATE;
    } else {
        return NONE;
    }
};