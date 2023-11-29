#include "./state/State.h"

#include "./components/distanceSensor/CarDistanceDetector.h"
#include "./components/led/LedExtTimered.h"
#include "./components/cooldown/Cooldown.h"
//#include <arduino-timer.h>


class WaitEnteringState : public State {
public:
    WaitEnteringState(CarDistanceDetector* sonar, Cooldown* clock);
    void init();
    StateName changeState(); 

private:
    CarDistanceDetector* sonar;
    Cooldown* clock;
    void flushTimer();
};