#ifndef __TEMP_S__
#define __TEMP_S__


#include <Arduino.h>

#define DANGEROUS_TEMP 80.0

class TemperatureSensor {
public:
    TemperatureSensor(int pin);
    double senseTemperature();
    bool isOverHeat();

private:
    int myPin;
};


#endif