#include "OLDOutputDevice.h"
#include "./components/led/Led.h"

#include "configs.h"

#define AMOUNTLEDS 2

namespace outputDevice{

    class OutputManager: public OutputDevice{
    public:
        Led* myStaticLeds[AMOUNTLEDS];

        OutputManager() {
            myStaticLeds[0] = new Led(LED1_PIN);
            myStaticLeds[1] = new Led(LED2_PIN);
        }

        void turnOnLed(int witch){
            myStaticLeds[witch]->switchOn();
        }
        
        void turnOffLed(int witch){
            myStaticLeds[witch]->switchOff();
        }

        int getAmountLeds() {
            return AMOUNTLEDS;
        }

    };
};
