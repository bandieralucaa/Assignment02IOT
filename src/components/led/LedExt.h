#ifndef __LED_EXT_H__
#define __LED_EXT_H__

#include "LightExt.h"
#include "Led.h"

class LedExt : public Led, public LightExt  {

public:
    LedExt(int pin);
    void switchOn();
    void switchOff();
    void setIntensity(int intensity);

private:
    int pin;
    bool isOn;

};

#endif