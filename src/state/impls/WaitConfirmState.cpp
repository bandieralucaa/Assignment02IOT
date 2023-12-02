#include "WaitConfirmState.h"

#ifdef DEBUG
#include <Arduino.h>
#endif

WaitConfirmState::WaitConfirmState(WashingMachineButton* b, LcdMonitor* lcd, OutSender* out){
    this->button = b;
    this->lcd = lcd;
    this->out = out;
}

void WaitConfirmState::init(){
    #ifdef STATE_CHANGE_DEBUG
    Serial.println("WaitingState");
    #endif

    this->button->start();
    this->out->updateState(STATE3, false);
    this->lcd->writeOnLcd(WAITING_STRING);
};

StateName WaitConfirmState::changeState(){
    if (this->button->isPressed()){
        return WASHING_STATE;
    } else {
        return NONE;
    }
}
