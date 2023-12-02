#include "./state/State.h"

#include "./components/temperature/TemperatureSensor.h"
#include "./components/cooldown/Cooldown.h"
#include "./components/lcd/LcdMonitor.h"
#include "./components/ioserial/OutSender.h"
//#include "./components/
//#include <arduino-timer.h>

class WarningState : public State {
public:
    WarningState(TemperatureSensor* tempSens, Cooldown* globalClock, Cooldown* washingClock, LcdMonitor* lcd, OutSender* out);
    void init();
    StateName changeState(); 

private:
    TemperatureSensor* tempSens;
    Cooldown* globalClock;
    Cooldown* washingClock;
    LcdMonitor* lcd;
    OutSender* out;
};