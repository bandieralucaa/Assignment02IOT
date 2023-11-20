#ifndef __GATE__
#define __GATE__

#include "./task/Task.h"
#include "./components/servomotor/Servomotor.h"
#include <Arduino.h>
#include <Servo.h>

class Gate : Servomotor, Task {
public:
    Gate(int pin, bool isActOpen);
    bool isOpen();
    bool isClose();
    void open();
    void close();
    void stop();

    void init();
    void tick();
    // bool updateAndCheckTime(int millis);

private:
    Servo motor;
    int pin;
    bool actOpen;
    bool actClose;
    int actGrade;
    int direction;
};


#endif