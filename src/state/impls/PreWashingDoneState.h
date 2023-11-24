#include "./state/State.h"
#include "./components/servomotor/Gate.h"

class PreWashingDoneState : public State {

public:
    PreWashingDoneState(Gate* myGate);
    void init();
    StateName changeState();


private:
    Gate* myGate;
};