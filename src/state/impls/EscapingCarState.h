#include "./state/State.h"
#include "./components/distanceSensor/CarDistanceDetector.h"
#include "./components/pir/CarPresenceDetector.h"
#include "./components/cooldown/Cooldown.h"
#include "./components/servomotor/Gate.h"
#include "./components/lcd/LcdMonitor.h"

class EscapingCarState : public State{
public:
    EscapingCarState(CarDistanceDetector* sonar, CarPresenceDetector* pir, Gate* gate, LcdMonitor* lcd);
    void init();
    StateName changeState();

private:
    CarDistanceDetector* sonar;
    CarPresenceDetector* pir;
    Gate* gate;
    LcdMonitor* lcd;


};

