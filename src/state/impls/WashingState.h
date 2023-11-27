#include "./state/State.h"

#include "./components/temperature/TemperatureSensor.h"
#include "./components/cooldown/Cooldown.h"
#include "./components/lcd/MyLcdMonitor.h"
//#include <arduino-timer.h>

class WashingState : public State {
public:
    WashingState(TemperatureSensor* tempSens, Cooldown* clock, MyLcdMonitor* lcd);
    void init();
    StateName changeState(); 

private:
    TemperatureSensor* tempSens;
    Cooldown* clock;
    MyLcdMonitor* lcd;
    bool startNewWash;
};