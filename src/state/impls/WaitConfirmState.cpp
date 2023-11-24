#include "WaitConfirmState.h"

WaitConfirmState::WaitConfirmState(WashingMachineButton* b){
    this->button = b;
}

void WaitConfirmState::init(){};

StateName WaitConfirmState::changeState(){
    if (this->button->isPressed()){
        return SLEEP_STATE;
    } else {
        return NONE;
    }
}
