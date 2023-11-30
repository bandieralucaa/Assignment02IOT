
#include "./state/impls/SleepState.h"

#ifdef DEBUG
#include <Arduino.h>
#endif
#include <avr/sleep.h>

SleepState::SleepState(Pir* awakePir, Light* l1, LcdMonitor* lcd, OutSender* out){
    this->myPir = awakePir;
    this->l1 = l1;
    this->lcd = lcd;
    this->out = out;
}

void SleepState::init() {
    #ifdef STATE_CHANGE_DEBUG
    Serial.println("NOT HELO\n");
    #endif
    this->l1->switchOff();
    this->lcd->turnOff();
    this->out->updateState(STATE1);
    this->out->updateMessage(MESS1,false);
    delay(100); //giving time to serial port

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