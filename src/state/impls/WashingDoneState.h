#include "./state/State.h"

#include "./components/distanceSensor/CarDistanceDetector.h"
#include "./components/led/LedExtTimered.h"

class WashingDoneState : public State {

public:

    WashingDoneState(LedExtTimered* blinkLed, CarDistanceDetector* sonar);
    void init();
    StateName changeState();

private:
    LedExtTimered* blinkLed;
    CarDistanceDetector* sonar;

};