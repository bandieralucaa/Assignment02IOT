#ifndef __STATE__
#define __STATE__

enum StateName {
    NONE = -1,
    SLEEP_STATE,
    WELCOME_STATE,
    PRE_ENTERING_STATE,
    ENTERING_STATE
};

class State {
    public:
        virtual void init() = 0;
        virtual StateName changeState() = 0;
};


#endif