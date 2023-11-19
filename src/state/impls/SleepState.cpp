
#include "./components/pir/PIR.h"
#include "./components/outputComponents/OutputManager.h"

#include "./state/impls/SleepState.h"

#include <Arduino.h>
#include <avr/sleep.h>

SleepState::SleepState(OutputManager* o, Pir* awakePir){
    myPir = awakePir;
    this->o = o;
}

void SleepState::init() {
    int i;
    int amount = o->getAmountLeds();
    for (i = 0; i<amount;i++){
        o->turnOffLed(i);
    }
    o->printOut("NOT HELO\n");
    // set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    // sleep_enable();
    // sleep_mode();
}

StateName SleepState::changeState(){
    if (myPir->isAnyone()){
        return WELCOME_STATE;
    } else {
        return NONE;
    }  
};