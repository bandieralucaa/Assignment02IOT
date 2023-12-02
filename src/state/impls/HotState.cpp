#include "HotState.h"

HotState::HotState(WashingMachineButton* butt, LcdMonitor* lcd, InReceiver* in, OutSender* out){
    this->button = butt;
    this->lcd = lcd;
    this->in = in;
    this->out = out;
}

void HotState::init(){
    #ifdef STATE_CHANGE_DEBUG
    Serial.print("HotState");
    #endif

    this->button->start();

    this->out->updateState(STATE5, true);
    this->lcd->raiseError();
    this->lcd->writeOnLcd(ERROR_STRING);
    // this->out->updateMessage(MESS5,true);
}

StateName HotState::changeState(){
    //if (this->in->checkIfOk()){
    if(this->button->isPressed() || this->in->checkIfOk()){
        this->lcd->goBackNormal();
        return WASHING_STATE;
    } else {
        this->out->sendTemperature();
        return NONE;
    }
}
