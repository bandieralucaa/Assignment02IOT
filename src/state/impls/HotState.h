#include "./state/State.h"
#include "configs.h"
#include "./components/button/WashingMachineButton.h"
#include "./components/lcd/LcdMonitor.h"
#include "./components/ioserial/InReceiver.h"
#include "./components/ioserial/OutSender.h"

#ifdef STATE_CHANGE_DEBUG
#include <Arduino.h>
#endif

class HotState : public State {
public:
    HotState(WashingMachineButton* butt, LcdMonitor* lcd, InReceiver* in, OutSender* out);
    void init();
    StateName changeState(); 

private:
    WashingMachineButton* button;
    LcdMonitor* lcd;
    InReceiver* in;
    OutSender* out;
};