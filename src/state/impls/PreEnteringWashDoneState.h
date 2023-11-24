#include "./state/State.h"
#include "./components/servomotor/Gate.h"

class PreEnteringWashDoneState : public State {

public:
    PreEnteringWashDoneState(Gate* myGate);
    void init();
    StateName changeState();


private:
    Gate* myGate;
};