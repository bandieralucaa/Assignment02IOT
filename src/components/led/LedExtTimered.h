#ifndef __LED_EXT_TIM__
#define __LED_EXT_TIM__

#include "LightExt.h"
#include "./task/Task.h"

class LedExtTimered : public Task, public LightExt  {

public:
    LedExtTimered(int pin, int delta);
    void setFading(int newDelta);

    void init();
    void tick();
    
private:
    int delta;
    bool isIncrease;
    int actIntensity;
};

#endif