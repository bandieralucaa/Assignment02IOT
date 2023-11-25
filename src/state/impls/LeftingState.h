#include "./state/State.h"

#include "./components/distanceSensor/CarDistanceDetector.h"
#include "./components/cooldown/Cooldown.h"
//#include <arduino-timer.h>

class LeftingState : public State {
public:
    LeftingState(CarDistanceDetector* sonar, Cooldown* clock);
    void init();
    StateName changeState(); 

private:
    CarDistanceDetector* sonar;
    Cooldown* clock;
    void flushTimer();
};