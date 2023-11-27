#include "HotState.h"

HotState::HotState(Button* butt, LcdMonitor* lcd){
    this->button = butt;
    this->lcd = lcd;
}

void HotState::init(){
    #ifdef STATE_CHANGE_DEBUG
    Serial.print("HotState");
    #endif
    this->lcd->raiseError();
    this->lcd->writeOnLcd(ERROR_STRING);
}

StateName HotState::changeState(){
    if (this->button->isPressed()){
        this->lcd->goBackNormal();
        return WASHING_STATE;
    } else {
        return NONE;
    }
}
