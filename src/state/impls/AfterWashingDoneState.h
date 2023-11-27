#include "./state/State.h"
#include "./components/servomotor/Gate.h"
#include "./components/led/Light.h"

class AfterWashingDoneState : public State{
public:
    AfterWashingDoneState(Gate* myGate, Light* l2);
    void init();
    StateName changeState();

private:
    Gate* myGate;
    Light* l2;
};

