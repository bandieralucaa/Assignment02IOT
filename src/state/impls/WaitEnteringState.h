#include "./state/State.h"

#include "./components/distanceSensor/CarDistanceDetector.h"
#include "./components/led/LedExtTimered.h"
#include <arduino-timer.h>

class WaitEnteringState : public State {
public:
    WaitEnteringState(LedExtTimered* blinkLed, CarDistanceDetector* sonar, Timer<3>* clock);
    void init();
    StateName changeState(); 

private:
    LedExtTimered* blinkLed;
    CarDistanceDetector* sonar;
    Timer<3>* clock;
    void flushTimer();
};