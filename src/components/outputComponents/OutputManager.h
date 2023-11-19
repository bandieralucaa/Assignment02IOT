
#ifndef __OUTPUTS_COMPONENTS__
#define __OUTPUTS_COMPONENTS__

#define AMOUNTLEDS 2

#define AMOUNTLEDS 2
#include "./components/led/Led.h"
// #include <string>

class OutputManager{
public:
    OutputManager();
    void turnOnLed(int witch);
    void turnOffLed(int witch);
    
    void printOut(char* toPrint);

    int getAmountLeds(){
        return AMOUNTLEDS;
    }

private:
    Led* myStaticLeds[AMOUNTLEDS];
};

#endif
