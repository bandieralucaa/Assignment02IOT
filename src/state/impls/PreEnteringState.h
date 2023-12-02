#include "./state/State.h"

//#include "./components/servomotor/Servomotor.h"
#include "./components/servomotor/Gate.h"
#include "./components/led/LedExtTimered.h"
#include "./components/lcd/LcdMonitor.h"
#include "./components/ioserial/OutSender.h"

class PreEnteringState : public State {
public:
    PreEnteringState(Gate* myGate, LedExtTimered* blinkLed, LcdMonitor* lcd, OutSender* out);
    void init();
    StateName changeState();

private:
    Gate* myGate;
    LedExtTimered* blinkLed;
    LcdMonitor* lcd;
    OutSender* out;
};