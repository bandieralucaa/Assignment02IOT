#ifndef __LED_EXT_H__
#define __LED_EXT_H__

#include "LightExt.h"
#include "Led.h"

class LedExt : public Light, public LightExt  {

public:
    LedExt(int pin);
    void switchOn();
    void switchOff();
    void setIntensity(int intensity);

};

#endif