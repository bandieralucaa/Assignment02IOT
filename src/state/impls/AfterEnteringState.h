#include "./state/State.h"
#include "./components/servomotor/Gate.h"
#include "./components/led/LedExtTimered.h"

class AfterEnteringState : public State{
public:
    AfterEnteringState(Gate* myGate, LedExtTimered* blink);
    void init();
    StateName changeState();

private:
    Gate* myGate;
    LedExtTimered* blink;

};

