#include "./state/State.h"
#include "./components/distanceSensor/CarDistanceDetector.h"
#include "./components/pir/CarPresenceDetector.h"
#include "./components/cooldown/Cooldown.h"

class EscapingCarState : public State{
public:
    EscapingCarState(CarDistanceDetector* sonar, CarPresenceDetector* pir);
    void init();
    StateName changeState();

private:
    CarDistanceDetector* sonar;
    CarPresenceDetector* pir;

};

