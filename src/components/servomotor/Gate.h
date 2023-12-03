#ifndef __GATE__
#define __GATE__

#include "./task/Task.h"
#include "./components/servomotor/Servomotor.h"
#include <Servo.h>
#include "configs.h"

#ifdef SERVO_MOTOR_DEBUG
#include <Arduino.h>
#endif

#define MAX_ANGLE 90
#define MIN_ANGLE 0

class Gate : public Servomotor, public Task{
public:
    Gate(int pin, bool isActOpen);
    bool isOpen();
    bool isClose();
    void open();
    void close();
    void stopGate();

    void init();
    void tick();

private:
    Servo motor;
    bool actOpen;
    bool actClose;
    int actGrade;
    int direction;
};


#endif