#ifndef __STATE__
#define __STATE__

enum StateName {
    SLEEP_STATE,
    WELCOME_STATE
};

class State {
    public:
        virtual void init() = 0;
        virtual StateName changeState() = 0;
};


#endif