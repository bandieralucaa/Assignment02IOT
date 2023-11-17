
#ifndef __OUTPUTS_COMPONENTS__
#define __OUTPUTS_COMPONENTS__


#define AMOUNTLEDS 2
#include "./components/led/Led.h"

class OutputManager{
public:
    OutputManager();
    void turnOnLed(int witch);
    void turnOffLed(int witch);
    int getAmountLeds(){
        return AMOUNTLEDS;
    }

private:
    Led* myStaticLeds[AMOUNTLEDS];
};

#endif
