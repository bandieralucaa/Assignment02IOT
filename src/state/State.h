#ifndef __STATE__
#define __STATE__

#include "configs.h"

enum StateName {
    NONE = -1,
    SLEEP_STATE,
    WELCOME_STATE,
    PRE_ENTERING_STATE,
    ENTERING_STATE,
    WAIT_ENTERING_STATE,
    AFTER_ENTERING_STATE,
    WAIT_CONFIRM_STATE,
    WASHING_STATE,
    PRE_WASHING_DONE_STATE,
    WASHING_DONE_STATE,
    LEFTING_STATE,
    AFTER_WASHING_DONE_STATE
};

class State {
    public:
        virtual void init() = 0;
        virtual StateName changeState() = 0;
};


#endif