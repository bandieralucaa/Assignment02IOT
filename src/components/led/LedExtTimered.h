#ifndef __LED_EXT_TIM__
#define __LED_EXT_TIM__

#include "LightExt.h"
#include "./task/Task.h"

#include "configs.h"

#define MAX_INTENSITY 255
#define MIN_INTENSITY 0

class LedExtTimered : public Task, public LightExt  {

public:
    LedExtTimered(int pin, int delta);
    void setFading(int newDelta);

    void init();
    void tick();

    void switchOn();
    void switchOff();

    void setIntensity(int intensity);

    void canBlink(bool canBlink);
    
private:
    void updateIntensity(int toUpdate);
    int delta;
    bool isIncrease;
    int actIntensity;
    bool isBlinking;

    bool isOn;
    int pin;
};

#endif