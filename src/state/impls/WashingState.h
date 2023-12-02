#include "./state/State.h"
#include "./components/temperature/TemperatureSensor.h"
#include "./components/cooldown/Cooldown.h"
#include "./components/lcd/LcdMonitor.h"
#include "./components/led/LedExtTimered.h"
#include "./components/ioserial/OutSender.h"

class WashingState : public State {
public:
    WashingState(TemperatureSensor* tempSens, Cooldown* clock, LcdMonitor* lcd, LedExtTimered* blink, OutSender* out);
    void init();
    StateName changeState(); 

private:
    TemperatureSensor* tempSens;
    Cooldown* clock;
    LcdMonitor* lcd;
    LedExtTimered* blink;
    OutSender* out;
    bool startNewWash;
};