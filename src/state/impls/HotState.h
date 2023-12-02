#include "./state/State.h"
#include "configs.h"
#include "./components/lcd/LcdMonitor.h"
#include "./components/ioserial/InReceiver.h"
#include "./components/ioserial/OutSender.h"

#ifdef DEBUG
#include <Arduino.h>
#endif

class HotState : public State {
public:
    HotState(LcdMonitor* lcd, InReceiver* in, OutSender* out);
    void init();
    StateName changeState(); 

private:
    LcdMonitor* lcd;
    InReceiver* in;
    OutSender* out;
};