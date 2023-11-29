#ifndef __MY_LCD__
#define __MY_LCD__

#include "configs.h"

#include "LcdMonitor.h"
#include "./task/Task.h"
#include "rgb_lcd.h"

#include "Arduino.h"

#define PROG_BAR_ROW 1
#define PROG_BAR_COLS 0

class MyLcdMonitor : public LcdMonitor{
public:

    MyLcdMonitor();

    void writeOnLcd(String toWrite);
    void clear();
    void turnOn();
    void turnOff();

    void raiseError();
    void goBackNormal();

    void initProgBar();
    void printProgBar();
    bool changeProgBar(int percentage);

private:
    void myPrint();
    String actString;
    rgb_lcd lcd;

};

#endif