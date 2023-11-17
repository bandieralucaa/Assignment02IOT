#include "./state/State.h"
#include "./components/pir/PIR.h"
#include "./components/outputComponents/outputs.h"
#include <Arduino.h>
#include <avr/sleep.h>

class SleepState : public State {
public:

    Pir* myPir;
    OutputDevice* o;

    SleepState(OutputDevice* o, Pir* awakePir){
        myPir = awakePir;
        this->o = o;
    }

    void init() {
        int i;
        int amount = o->getAmountLeds();
        for (i = 0; i<amount;i++){
            o->turnOffLed(i);
        }

        // set_sleep_mode(SLEEP_MODE_PWR_DOWN); 
        // sleep_enable(); 
        // sleep_mode();
    }

    StateName changeState(){
        if (myPir->isAnyone()){
            return WELCOME_STATE;
        } else {
            return NONE;
        }
        
    };
};