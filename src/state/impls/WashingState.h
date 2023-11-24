#include "./state/State.h"

#include <arduino-timer.h>

class WashingState : public State {
public:
    WashingState(Timer<3>* clock);
    void init();
    StateName changeState(); 

private:
    Timer<3>* clock;
    void flushTimer();
};