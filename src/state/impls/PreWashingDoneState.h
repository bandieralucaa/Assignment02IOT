#include "./state/State.h"
#include "./components/servomotor/Gate.h"
#include "./components/lcd/LcdMonitor.h"
#include "./components/led/Light.h"
#include "./components/led/LedExtTimered.h"
#include "./components/ioserial/OutSender.h"

class PreWashingDoneState : public State {

public:
    PreWashingDoneState(Gate* myGate, LcdMonitor* lcd, LedExtTimered* blink, Light* l2, OutSender* out);
    void init();
    StateName changeState();


private:
    Gate* myGate;
    LcdMonitor* lcd;
    LedExtTimered* blink;
    Light* l2;
    OutSender* out;
};