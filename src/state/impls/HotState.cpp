#include "HotState.h"

HotState::HotState(Button* butt){
    this->button = butt;
}

void HotState::init(){
    #ifdef STATE_CHANGE_DEBUG
    Serial.print("HotState");
    #endif
}

StateName HotState::changeState(){
    if (this->button->isPressed()){
        return WASHING_STATE;
    } else {
        return NONE;
    }
}
