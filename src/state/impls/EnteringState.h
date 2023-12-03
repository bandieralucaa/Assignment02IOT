#include "./state/State.h"
#include "./components/distanceSensor/CarDistanceDetector.h"
#include "./components/cooldown/Cooldown.h"

class EnteringState : public State {

public:
    EnteringState(CarDistanceDetector* sonar, Cooldown* globalTimer);
    void init();
    StateName changeState(); 

private:
    CarDistanceDetector* sonar;
    Cooldown* timer;
};