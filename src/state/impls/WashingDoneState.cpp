#include "components/outputComponents/OutputManager.h"
#include "./WashingDoneState.h"
#include "components/led/Led.h"
#include "Arduino.h"

void WashingDoneState::ledManage(Led led) {
    led.switchOff();
}


StateName WashingDoneState::changeState() {
    return NONE;
    
};

    