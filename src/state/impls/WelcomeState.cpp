
#include "./components/pir/PIR.h"
#include "components/outputComponents/OutputManager.h"
#include "./state/impls/WelcomeState.h"
#include <Arduino.h>

volatile bool isOver;

bool isOverTime(void*){
    isOver = true;
    return true;
}

WelcomeState::WelcomeState(OutputManager* o, Pir* awakePir, Timer<3>* clock){
    myPir = awakePir;
    this->o = o;
    this->clock = clock;
}

void* tt;

void WelcomeState::init() {
    // Serial.print(this->clock->size());
    o->printOut("HELO\n");
    o->turnOnLed(LED1_PIN);
    isOver = false;
    tt = this->clock->every(N1_TIME, isOverTime);
    // Serial.print(this->clock->size());
}

void WelcomeState::flushTimer(){
    // Serial.print("\n");
    // Serial.print(this->clock->size());
    // Serial.print("\n");
    this->clock->cancel(tt);
    // Serial.print(this->clock->size());
    // Serial.print("\n");
}

StateName WelcomeState::changeState() {
    /*if (!myPir->isAnyone()) {
        flushTimer();
        return SLEEP_STATE;
    } else if (isOver) {
        flushTimer();
    } else {
        return NONE;
    }*/
    o->turnOffLed(LED1_PIN);
    return PRE_ENTERING_STATE;

};