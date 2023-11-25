#include "./state/State.h"

#include "./components/temperature/TemperatureSensor.h"
#include "./components/cooldown/Cooldown.h"
//#include <arduino-timer.h>

class WashingState : public State {
public:
    WashingState(TemperatureSensor* tempSens, Cooldown* clock);
    void init();
    StateName changeState(); 

private:
    TemperatureSensor* tempSens;
    Cooldown* clock;
    bool startNewWash;
};