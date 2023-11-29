#include "HotState.h"

HotState::HotState(Button* butt, LcdMonitor* lcd, InReceiver* in){
    this->button = butt;
    this->lcd = lcd;
    this->in = in;
}

void HotState::init(){
    #ifdef STATE_CHANGE_DEBUG
    Serial.print("HotState");
    #endif
    this->lcd->raiseError();
    this->lcd->writeOnLcd(ERROR_STRING);
}

StateName HotState::changeState(){
    if (this->button->isPressed() || this->in->checkIfOk()){
        this->lcd->goBackNormal();
        return WASHING_STATE;
    } else {
        return NONE;
    }
}
