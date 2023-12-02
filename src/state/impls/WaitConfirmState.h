#include "./state/State.h"
#include "./components/button/WashingMachineButton.h"
#include "./components/lcd/LcdMonitor.h"
#include "./components/ioserial/OutSender.h"

class WaitConfirmState : public State {
public:
    WaitConfirmState(WashingMachineButton* b, LcdMonitor* lcd, OutSender* out);
    void init();
    StateName changeState();
    
private:
    WashingMachineButton* button;
    LcdMonitor* lcd;
    OutSender* out;
};