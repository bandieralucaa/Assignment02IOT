#include "WaitConfirmState.h"

#ifdef DEBUG
#include <Arduino.h>
#endif

WaitConfirmState::WaitConfirmState(Button* b, LcdMonitor* lcd){
    this->button = b;
    this->lcd = lcd;
}

void WaitConfirmState::init(){
    #ifdef STATE_CHANGE_DEBUG
    Serial.println("WaitingState");
    #endif
    this->lcd->writeOnLcd(WAITING_STRING);
};

StateName WaitConfirmState::changeState(){
    if (this->button->isPressed()){
        return WASHING_STATE;
    } else {
        return NONE;
    }
}
