#ifndef __LCD__
#define __LCD__

#include "Arduino.h"

#define MAX_VALUE_PERCENTAGE_BAR 100


class LcdMonitor{
public:
    virtual void writeOnLcd(String toWrite) = 0;
    virtual void clear() = 0;
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;

    virtual void raiseError() = 0;
    virtual void goBackNormal() = 0;

    virtual void initProgBar() = 0;
    virtual void printProgBar() = 0;
    virtual bool changeProgBar(int percentage) = 0;
};

#endif