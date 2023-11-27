
#include "./components/pir/PIR.h"
#include "components/outputComponents/OutputManager.h"
#include "./state/impls/WelcomeState.h"
#include <Arduino.h>

volatile bool isOver;

bool isOverTime(void*){
    isOver = true;
    return true;
}

WelcomeState::WelcomeState(OutputManager* o, Pir* awakePir, Cooldown* clock, LcdMonitor* lcd){
    this->myPir = awakePir;
    this->o = o;
    this->clock = clock;
    this->lcd = lcd;
}

void* tt;

void WelcomeState::init() {
    
    this->lcd->writeOnLcd(WELCOME_STRING);
    #ifdef STATE_CHANGE_DEBUG
    o->printOut("HELO\n");
    #endif

    this->clock->format(N1_TIME);

    //isOver = false;
    //tt = this->clock->every(N1_TIME, isOverTime);
    // Serial.print(this->clock->size());
}

// void WelcomeState::flushTimer(){
//     // Serial.print("\n");
//     // Serial.print(this->clock->size());
//     // Serial.print("\n");
//     this->clock->cancel(tt);
//     // Serial.print(this->clock->size());
//     // Serial.print("\n");
// }

StateName WelcomeState::changeState() {
    if (!myPir->isAnyone()) {
        //flushTimer();
        this->lcd->clear();
        return SLEEP_STATE;
    } else if (this->clock->isOver()) {
        //flushTimer();
        this->lcd->clear();
        this->clock->pause();
        return PRE_ENTERING_STATE;
    } else {
        return NONE;
    }

};