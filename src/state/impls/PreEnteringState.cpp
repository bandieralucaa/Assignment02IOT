
#include "./state/impls/PreEnteringState.h"

#ifdef DEBUG
#include <Arduino.h>
#endif


PreEnteringState::PreEnteringState(Gate* myGate, LedExtTimered* blinkLed, LcdMonitor* lcd){
    this->myGate = myGate;
    this->blinkLed = blinkLed;
    this->lcd = lcd;
}

void PreEnteringState::init() {
    #ifdef STATE_CHANGE_DEBUG
    Serial.print("PreEnteringState");
    #endif
    this->myGate->open();
    // this->blinkLed->setIntensity(0);
    // this->blinkLed->switchOn();

    this->blinkLed->switchOn();
    this->blinkLed->canBlink(true);
    this->blinkLed->setFading(BLINK_DELTA_1);
    this->blinkLed->init();

    this->lcd->writeOnLcd(PRE_ENTERING_STRING);
}

StateName PreEnteringState::changeState() {
    if (this->myGate->isOpen()){
        // timer->schedule();
        this->myGate->stop();
        return ENTERING_STATE;
    } else {
        return NONE;
    }

};