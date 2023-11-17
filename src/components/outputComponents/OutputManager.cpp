#include "OutputManager.h"

#include "configs.h"

int index[] = {LED1_PIN, LED2_PIN};

OutputManager::OutputManager() {
    int i;
    for(i=0; i<AMOUNTLEDS; i++){
        myStaticLeds[i] = new Led(index[i]);
    }
}

void OutputManager::turnOnLed(int witch){
    myStaticLeds[witch]->switchOn();
}
    
void OutputManager::turnOffLed(int witch){
    myStaticLeds[witch]->switchOff();
}
