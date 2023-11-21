
#include "./components/pir/PIR.h"
#include "components/outputComponents/OutputManager.h"
#include "./state/impls/WelcomeState.h"

WelcomeState::WelcomeState(OutputManager* o, Pir* awakePir){
    myPir = awakePir;
    this->o = o;
    // this->cooldown = cooldown;
}

void WelcomeState::init() {
    o->printOut("HELO\n");
}

StateName WelcomeState::changeState() {
    if (!myPir->isAnyone()){
        return SLEEP_STATE;
    } else {
        return NONE;
    }
};