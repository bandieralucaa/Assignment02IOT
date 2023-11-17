
#ifndef __OUTPUTS_COMPONENTS__
#define __OUTPUTS_COMPONENTS__

#define AMOUNTLEDS 2

class OutputManager{
public:
    void turnOnLed(int witch);
    void turnOffLed(int witch);
    
    int getAmountLeds(){
        return AMOUNTLEDS;
    }

private:
    Led* myStaticLeds[AMOUNTLEDS];
};

#endif
