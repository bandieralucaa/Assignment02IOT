#include "./state/impls/SleepState.h"

#ifdef DEBUG
#include <Arduino.h>
#endif
#include <avr/sleep.h>

SleepState::SleepState(CarPresenceDetector* awakePir, Light* l1, LcdMonitor* lcd, OutSender* out){
    this->myPir = awakePir;
    this->l1 = l1;
    this->lcd = lcd;
    this->out = out;
}

void SleepState::init() {
    #ifdef STATE_CHANGE_DEBUG
    Serial.println("SleepState");
    #endif
    this->l1->switchOff();
    this->lcd->turnOff();
    this->out->updateState((String)STATE1, false);
    this->myPir->start();

    delay(1000); 

    set_sleep_mode(SLEEP_MODE_PWR_DOWN); 
    sleep_enable(); 
    sleep_mode();   
}

StateName SleepState::changeState(){
    if (myPir->isAnyone()){
        return WELCOME_STATE;
    } else {
        return NONE;
    }  
};