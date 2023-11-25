#include "./state/State.h"

#include "configs.h"

#include "./components/button/Button.h"

#ifdef STATE_CHANGE_DEBUG
#include <Arduino.h>
#endif

class HotState : public State {
public:
    HotState(Button* butt);
    void init();
    StateName changeState(); 

private:
    Button* button;
};