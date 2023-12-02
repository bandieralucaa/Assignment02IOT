#include "HotState.h"

HotState::HotState(LcdMonitor* lcd, InReceiver* in, OutSender* out){
    this->lcd = lcd;
    this->in = in;
    this->out = out;
}

void HotState::init(){
    #ifdef STATE_CHANGE_DEBUG
    Serial.print("HotState");
    #endif

    this->out->updateState(STATE5, true);
    this->lcd->raiseError();
    this->lcd->writeOnLcd(ERROR_STRING);
}

StateName HotState::changeState(){
    if(this->in->checkIfOk()){
        this->lcd->goBackNormal();
        return WASHING_STATE;
    } else {
        this->out->sendTemperature();
        return NONE;
    }
}
