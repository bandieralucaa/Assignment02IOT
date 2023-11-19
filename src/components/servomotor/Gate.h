#ifndef __GATE__
#define __GATE__

#include "./task/Task.h"
#include "./components/pir/PIR.h"

class Gate {
public:
    Servomotor(int pin, bool isActOpen);
    bool isOpen();
    bool isClose();
    void open();
    void close();

private:
    int pin;
    bool actOpen;
    bool actClose;
    int actGrade;
};


#endif