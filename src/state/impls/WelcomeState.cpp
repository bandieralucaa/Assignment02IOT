
#include "./components/pir/PIR.h"
#include "components/outputComponents/OutputManager.h"
#include "./state/impls/WelcomeState.h"

WelcomeState::WelcomeState(OutputManager* o, Pir* awakePir, Cooldown* cool){
    myPir = awakePir;
    this->o = o;
    this->cool = cool;
}

void WelcomeState::init() {
    o->printOut("HELO\n");
    this->cool = this->cool->format(N1);
}

StateName WelcomeState::changeState() {
    if (!myPir->isAnyone()){
        return SLEEP_STATE;
    } else if (this->cool->isOver()){
        return PRE_ENTERING_STATE;
    } else {
        return NONE;
    }
};