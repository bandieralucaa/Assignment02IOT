#include "./state/State.h"
#include "./components/servomotor/Gate.h"

class PreEnteringState : public State {
public:
    PreEnteringState(Gate* myGate);
    void init();
    StateName changeState();

private:
    Gate* myGate;
};