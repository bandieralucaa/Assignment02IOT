#include "OutputManager.h"

#include "configs.h"

<<<<<<< HEAD
int index[] = {LED1_PIN, LED2_PIN};

OutputManager::OutputManager() {
    int i;
    for(i=0; i<AMOUNTLEDS; i++){
        myStaticLeds[i] = new Led(index[i]);
    }
=======

OutputManager::OutputManager() {
        myStaticLeds[0] = new Led(LED1_PIN);
        myStaticLeds[1] = new Led(LED2_PIN);
>>>>>>> main
}

void OutputManager::turnOnLed(int witch){
    myStaticLeds[witch]->switchOn();
}
<<<<<<< HEAD
    
void OutputManager::turnOffLed(int witch){
    myStaticLeds[witch]->switchOff();
}
=======

void OutputManager::turnOffLed(int witch){
        myStaticLeds[witch]->switchOff();
}

// class OutputManager{

//     Led* myStaticLeds[AMOUNTLEDS];

//     OutputManager::OutputManager() {
//         myStaticLeds[0] = new Led(LED1_PIN);
//         myStaticLeds[1] = new Led(LED2_PIN);
//     }

//     void OutputManager::turnOnLed(int witch){
//         myStaticLeds[witch]->switchOn();
//     }
    
//     void OutputManager::turnOffLed(int witch){
//         myStaticLeds[witch]->switchOff();
//     }

//     int OutputManager::getAmountLeds() {
//         return AMOUNTLEDS;
//     }

// };
>>>>>>> main
