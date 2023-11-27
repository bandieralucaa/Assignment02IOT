#include "./state/State.h"

#include "./components/temperature/TemperatureSensor.h"
#include "./components/cooldown/Cooldown.h"
#include "./components/lcd/LcdMonitor.h"
#include "./components/led/LedExtTimered.h"
//#include <arduino-timer.h>

class WashingState : public State {
public:
    WashingState(TemperatureSensor* tempSens, Cooldown* clock, LcdMonitor* lcd, LedExtTimered* blink);
    void init();
    StateName changeState(); 

private:
    TemperatureSensor* tempSens;
    Cooldown* clock;
    LcdMonitor* lcd;
    LedExtTimered* blink;
    bool startNewWash;
};