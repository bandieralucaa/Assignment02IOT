#include "./state/State.h"
#include "./components/distanceSensor/CarDistanceDetector.h"
#include "./components/pir/CarPresenceDetector.h"
#include "./components/cooldown/Cooldown.h"
#include "./components/servomotor/Gate.h"
#include "./components/lcd/LcdMonitor.h"
#include "./components/led/LedExtTimered.h"

class EscapingCarState : public State{
public:
    EscapingCarState(CarDistanceDetector* sonar, CarPresenceDetector* pir, Gate* gate, LcdMonitor* lcd, LedExtTimered* blink );
    void init();
    StateName changeState();

private:
    CarDistanceDetector* sonar;
    CarPresenceDetector* pir;
    Gate* gate;
    LcdMonitor* lcd;
    LedExtTimered* blink;


};

