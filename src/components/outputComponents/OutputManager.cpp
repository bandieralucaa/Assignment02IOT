#include "OutputManager.h"
#include "./components/led/Led.h"

#include "configs.h"

#define AMOUNTLEDS 2

class OutputManager{

    Led* myStaticLeds[AMOUNTLEDS];

    OutputManager::OutputManager() {
        myStaticLeds[0] = new Led(LED1_PIN);
        myStaticLeds[1] = new Led(LED2_PIN);
    }

    void OutputManager::turnOnLed(int witch){
        myStaticLeds[witch]->switchOn();
    }
    
    void OutputManager::turnOffLed(int witch){
        myStaticLeds[witch]->switchOff();
    }

    int OutputManager::getAmountLeds() {
        return AMOUNTLEDS;
    }

};