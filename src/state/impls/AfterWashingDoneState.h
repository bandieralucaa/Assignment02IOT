#include "./state/State.h"
#include "./components/servomotor/Gate.h"

class AfterWashingDoneState : public State{
public:
    AfterWashingDoneState(Gate* myGate);
    void init();
    StateName changeState();

private:
    Gate* myGate;

};

