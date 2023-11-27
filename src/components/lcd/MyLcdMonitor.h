#ifndef __MY_LCD__
#define __MY_LCD__

#include "LcdMonitor.h"
#include "./task/Task.h"
#include "rgb_lcd.h"

class MyLcdMonitor : public LcdMonitor{
public:

    MyLcdMonitor();

    void writeOnLcd(char* toWrite);
    void clear();
    void turnOn();
    void turnOff();

    void raiseError();
    void goBackNormal();

    void printProgBar(int percentage);

private:
    char* actString;
    rgb_lcd lcd;

};

#endif