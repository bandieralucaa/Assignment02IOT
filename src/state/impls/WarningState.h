#include "./state/State.h"

#include "./components/temperature/TemperatureSensor.h"
#include "./components/cooldown/Cooldown.h"
//#include <arduino-timer.h>

class WarningState : public State {
public:
    WarningState(TemperatureSensor* tempSens, Cooldown* globalClock, Cooldown* washingClock);
    void init();
    StateName changeState(); 

private:
    TemperatureSensor* tempSens;
    Cooldown* globalClock;
    Cooldown* washingClock;
    void flushTimer();
};