#ifndef __LED__
#define __LED__

#include "Light.h"

class Led : public Light
{
public:
    int pin;

    Led(int pin);
    void switchOn();
    void switchOff();
};


#endif 