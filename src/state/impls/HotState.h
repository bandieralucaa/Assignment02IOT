#include "./state/State.h"

#include "configs.h"

#include "./components/button/Button.h"
#include "./components/lcd/LcdMonitor.h"

#ifdef STATE_CHANGE_DEBUG
#include <Arduino.h>
#endif

class HotState : public State {
public:
    HotState(Button* butt, LcdMonitor* lcd);
    void init();
    StateName changeState(); 

private:
    Button* button;
    LcdMonitor* lcd;
};