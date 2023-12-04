#ifndef __TEMP_S_T__
#define __TEMP_S_T__

#include "./task/Task.h"
#include "TemperatureSensor.h"
#include <Arduino.h>

#define DANGEROUS_TEMP 80.0

class TemperatureSensorTimered : public Task, public TemperatureSensor  {
public:
    TemperatureSensorTimered(int pin);
    double senseTemperature();
    bool isOverHeat();

    void init();
    void tick();

private:
    int myPin;
    double lastTemp;
};


#endif