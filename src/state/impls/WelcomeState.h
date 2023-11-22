#include "./state/State.h"

#include "./components/pir/PIR.h"
#include "./components/outputComponents/OutputManager.h"
#include <arduino-timer.h>
#include "configs.h"

class WelcomeState : public State {
public:
    WelcomeState(OutputManager* o, Pir* awakePir, Timer<3> clock);
    void init();
    StateName changeState();
private:
    Pir* myPir;
    OutputManager* o;
    Timer<3>* clock;
    void flushTimer();
    // Timer<1> clock;
    // Timer* cooldown;
};