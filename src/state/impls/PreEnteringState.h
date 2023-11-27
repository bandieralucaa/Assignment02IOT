#include "./state/State.h"
#include "./components/servomotor/Gate.h"
#include "./components/led/LedExtTimered.h"
#include "./components/lcd/LcdMonitor.h"

class PreEnteringState : public State {
public:
    PreEnteringState(Gate* myGate, LedExtTimered* blinkLed, LcdMonitor* lcd);
    void init();
    StateName changeState();

private:
    Gate* myGate;
    LedExtTimered* blinkLed;
    LcdMonitor* lcd;
};