#include "WashingState.h"

#ifdef DEBUG
#include "Arduino.h"
#endif

//static volatile bool isOver;

WashingState::WashingState(TemperatureSensor* tempSens, Cooldown* clock, LcdMonitor* lcd, LedExtTimered* blink, OutSender* out){
    this->tempSens = tempSens;
    this->clock = clock;
    this->lcd = lcd;
    this->blink = blink;
    this->out = out;
}

// static void* tt;

// bool isOverTime2(void*){
//     isOver = true;
//     return true;
// }

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
    // this->out->updateMessage(MESS4, false);
    
    //tt = this->clock->every(N3_TIME, isOverTime2);
}


// void WashingState::flushTimer(){
    // Serial.print("\n");
    // Serial.print(this->clock->size());
    // Serial.print("\n");
    //this->clock->cancel(tt);
    // Serial.print(this->clock->size());
    // Serial.print("\n");
// }


StateName WashingState::changeState() {
    #ifdef TEMP_DEBUG
    Serial.println("oooooooo: " + (String)this->tempSens->senseTemperature());
    #endif
    if(this->tempSens->isOverHeat()) {
        this->clock->pause();
        return WARNING_STATE;
    } else if (this->clock->isOver()) {
        //flushTimer();
        startNewWash = true;
        return PRE_WASHING_DONE_STATE;
    } else {
        if (this->lcd->changeProgBar(this->clock->percentageComplete())){
            this->lcd->printProgBar();
        }
        #ifdef LCD_DEBUG
        Serial.println(this->clock->percentageComplete());
        #endif
        return NONE;
    }
    //delay(1000);
};