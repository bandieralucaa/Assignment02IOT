#include "./components/pir/PIR.h"
#include "./PreWashingDoneState.h"

#ifdef DEBUG
#include <Arduino.h>
#endif

PreWashingDoneState::PreWashingDoneState(Gate* myGate, LcdMonitor* lcd, LedExtTimered* blink, Light* l2, OutSender* out){
    this->myGate = myGate;
    this->lcd = lcd;
    this->blink = blink;
    this->l2 = l2;
    this->out = out;
}

void PreWashingDoneState::init() {
    #ifdef STATE_CHANGE_DEBUG
    Serial.println("PreWashingDoneState");
    #endif
    this->myGate->open();
    this->lcd->writeOnLcd(PRE_WASHING_DONE_STRING);
    this->blink->switchOff();
    this->l2->switchOn();
    this->out->updateState(STATE6);
    this->out->updateMessage(MESS6,false);
}

StateName PreWashingDoneState::changeState() {
    if (this->myGate->isOpen()){
        this->myGate->stop();
        return WASHING_DONE_STATE;
    } else {
        return NONE;
    }
    
};