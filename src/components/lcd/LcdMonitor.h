#ifndef __LCD__
#define __LCD__

#define MAX_VALUE 100
#define PROG_BAR_ROW 1
#define PRG_BAR_COLS 0

class LcdMonitor{
public:
    virtual void writeOnLcd(char* toWrite) = 0;
    virtual void clear() = 0;
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;

    virtual void raiseError() = 0;
    virtual void goBackNormal() = 0;

    virtual void printProgBar(int percentage) = 0;
};

#endif