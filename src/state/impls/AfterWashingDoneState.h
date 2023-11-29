#include "./state/State.h"
#include "./components/servomotor/Gate.h"
#include "./components/led/Light.h"
#include "./components/ioserial/OutSender.h"

class AfterWashingDoneState : public State{
public:
    AfterWashingDoneState(Gate* myGate, Light* l2, OutSender* o);
    void init();
    StateName changeState();

private:
    Gate* myGate;
    Light* l2;
    OutSender* out;
};

