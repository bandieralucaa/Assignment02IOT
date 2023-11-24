#include "./state/State.h"
#include "./components/servomotor/Gate.h"

class AfterEnteringState : public State{
public:
    AfterEnteringState(Gate* myGate);
    void init();
    StateName changeState();

private:
    Gate* myGate;

};

