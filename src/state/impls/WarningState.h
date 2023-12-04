#include "./state/State.h"
#include "./components/temperature/TemperatureSensorTimered.h"
#include "./components/cooldown/Cooldown.h"
#include "./components/lcd/LcdMonitor.h"
#include "./components/ioserial/OutSender.h"

class WarningState : public State {
public:
    WarningState(TemperatureSensorTimered* tempSens, Cooldown* globalClock, Cooldown* washingClock, LcdMonitor* lcd, OutSender* out);
    void init();
    StateName changeState(); 

private:
    TemperatureSensorTimered* tempSens;
    Cooldown* globalClock;
    Cooldown* washingClock;
    LcdMonitor* lcd;
    OutSender* out;
};