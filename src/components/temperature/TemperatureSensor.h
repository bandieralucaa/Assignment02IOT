#ifndef __TEMP_S__
#define __TEMP_S__


#define DANGEROUS_TEMP 80.0

class TemperatureSensor {
public:
    virtual double senseTemperature() = 0;
    virtual bool isOverHeat() = 0;
};


#endif