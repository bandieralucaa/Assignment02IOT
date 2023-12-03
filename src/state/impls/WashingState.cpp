#include "WashingState.h"

#ifdef DEBUG
#include "Arduino.h"
#endif

WashingState::WashingState(TemperatureSensor* tempSens, Cooldown* clock, LcdMonitor* lcd, LedExtTimered* blink, OutSender* out){
    this->tempSens = tempSens;
    this->clock = clock;
    this->lcd = lcd;
    this->blink = blink;
    this->out = out;
}

void WashingState::init() {
    #ifdef STATE_CHANGE_DEBUG
    Serial.println("Washing state");
    #endif
    this->lcd->clear();
    this->lcd->initProgBar();

    if(startNewWash){
        this->clock->format(N3_TIME);
    } else {
        this->clock->resume();
        this->lcd->printProgBar();
    }
    startNewWash = false;
    this->blink->canBlink(true);
    this->blink->setFading(BLINK_DELTA_2);
    

    this->out->updateState(STATE4, false);
}

StateName WashingState::changeState() {
    #ifdef TEMP_DEBUG
    Serial.println(" -- " + (String)this->tempSens->senseTemperature() + " -- ");
    #endif
    this->out->sendTemperature();
    
    if(this->clock->isOver()) {
        startNewWash = true;
        return PRE_WASHING_DONE_STATE;
    } else if (this->tempSens->isOverHeat()) {
        this->out->sendTemperature();
        return WARNING_STATE;
    } else {
        this->out->sendTemperature();
        if (this->lcd->changeProgBar(this->clock->percentageComplete())){
            this->lcd->printProgBar();
        }
        #ifdef LCD_DEBUG
        Serial.println(this->clock->percentageComplete());
        #endif
        return NONE;
    }
};