#ifndef __MY_LCD__
#define __MY_LCD__

#include "LcdMonitor.h"
#include "./task/Task.h"
#include "rgb_lcd.h"

#define PROG_BAR_ROW 1
#define PROG_BAR_COLS 0

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
    void myPrint();
    char* actString;
    rgb_lcd lcd;

};

#endif