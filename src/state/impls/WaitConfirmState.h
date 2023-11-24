#include "./state/State.h"
#include "./components/button/WashingMachineButton.h"

class WaitConfirmState : public State {
public:
    WaitConfirmState(WashingMachineButton* b);
    void init();
    StateName changeState();
    
private:
    WashingMachineButton* button;
};