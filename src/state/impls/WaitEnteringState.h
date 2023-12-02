#include "./state/State.h"
#include "./components/distanceSensor/CarDistanceDetector.h"
#include "./components/cooldown/Cooldown.h"

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