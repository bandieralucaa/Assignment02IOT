#include "./components/pir/PIR.h"
#include "components/led/Led.h"
#include "./state/impls/WelcomeState.h"
#include <Arduino.h>


WelcomeState::WelcomeState(CarPresenceDetector* awakePir, Cooldown* clock, LcdMonitor* lcd, Led* l1){
    this->myPir = awakePir;
    this->l1 = l1;
    this->clock = clock;
    this->lcd = lcd;
}

void WelcomeState::init() {
    this->lcd->turnOn();
    this->lcd->writeOnLcd(WELCOME_STRING);
    l1->switchOn();

    #ifdef STATE_CHANGE_DEBUG
    Serial.println("WelcomeState");
    #endif

    this->myPir->start();

    this->clock->format(N1_TIME);
}

StateName WelcomeState::changeState() {
    if (!myPir->isAnyone()) {
        this->lcd->clear();
        return SLEEP_STATE;
    } else if (this->clock->isOver()) {
        this->lcd->clear();
        this->clock->pause();
        return PRE_ENTERING_STATE;
    } else {
        return NONE;
    }

};