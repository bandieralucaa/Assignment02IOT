
#include "./components/pir/PIR.h"
#include "components/outputComponents/OutputManager.h"
#include "./state/impls/WelcomeState.h"

volatile bool isOver;

bool isOverTime(void*){
    isOver = true;
    return true;
}

WelcomeState::WelcomeState(OutputManager* o, Pir* awakePir, Timer<3> clock){
    myPir = awakePir;
    this->o = o;
    this->clock = &clock;
    // this->clock.at(N1_TIME, isOverTime);
    // this->cooldown = cooldown;
    
}

void* tt;

void WelcomeState::init() {
    o->printOut("HELO\n");
    isOver = false;
    tt = this->clock->at(N1_TIME, isOverTime);
}

void WelcomeState::flushTimer(){
    this->clock->cancel(tt);
}

StateName WelcomeState::changeState() {
    if (!myPir->isAnyone()) {
        flushTimer();
        return SLEEP_STATE;
    } else if (isOver) {
        flushTimer();
        return PRE_ENTERING_STATE;
    } else {
        return NONE;
    }
};