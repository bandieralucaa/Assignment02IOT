#include "./state/State.h"
#include "./components/servomotor/Gate.h"

class AfterEnteringWashDoneState : public State{
public:
    AfterEnteringWashDoneState(Gate* myGate);
    void init();
    StateName changeState();

private:
    Gate* myGate;

};

