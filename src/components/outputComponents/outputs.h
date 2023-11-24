
#ifndef __OUTPUTS_COMPONENTS__
#define __OUTPUTS_COMPONENTS__


class OutputDevice{
public:
    virtual void turnOnLed(int witch) = 0;
    virtual void turnOffLed(int witch) = 0;
    //virtual void writeOnLCD(string message) = 0;
    virtual int getAmountLeds() = 0;
};

#endif
