#include "./components/pir/PIR.h"
#include "./PreWashingDoneState.h"

#ifdef DEBUG
#include <Arduino.h>
#endif

PreWashingDoneState::PreWashingDoneState(Gate* myGate, LcdMonitor* lcd, LedExtTimered* blink, Light* l2){
    this->myGate = myGate;
    this->lcd = lcd;
    this->blink = blink;
    this->l2 = l2;
}

void PreWashingDoneState::init() {
    #ifdef STATE_CHANGE_DEBUG
    Serial.println("PreWashingDoneState");
    #endif
    this->myGate->open();
    this->lcd->writeOnLcd(PRE_WASHING_DONE_STRING);
    this->blink->switchOff();
    this->l2->switchOn();
}

StateName PreWashingDoneState::changeState() {
    if (this->myGate->isOpen()){
        this->myGate->stop();
        return WASHING_DONE_STATE;
    } else {
        return NONE;
    }
    
};