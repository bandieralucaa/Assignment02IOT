#include "./state/State.h"

#include "configs.h"

#include "./components/button/Button.h"
#include "./components/lcd/LcdMonitor.h"
#include "./components/ioserial/InReceiver.h"

#ifdef STATE_CHANGE_DEBUG
#include <Arduino.h>
#endif

class HotState : public State {
public:
    HotState(Button* butt, LcdMonitor* lcd, InReceiver* in);
    void init();
    StateName changeState(); 

private:
    Button* button;
    LcdMonitor* lcd;
    InReceiver* in;
};