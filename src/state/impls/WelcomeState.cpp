
#include "./components/pir/PIR.h"
#include "components/led/Led.h"
#include "./state/impls/WelcomeState.h"
#include <Arduino.h>

volatile bool isOver;

// bool isOverTime(void*){
//     isOver = true;
//     return true;
// }

WelcomeState::WelcomeState(CarPresenceDetector* awakePir, Cooldown* clock, LcdMonitor* lcd, Led* l1){
    this->myPir = awakePir;
    this->l1 = l1;
    this->clock = clock;
    this->lcd = lcd;
}

void* tt;

void WelcomeState::init() {
    this->lcd->turnOn();
    this->lcd->writeOnLcd(WELCOME_STRING);
    l1->switchOn();

    #ifdef STATE_CHANGE_DEBUG
    Serial.println("WelcomeState ");
    #endif

    this->myPir->start();

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