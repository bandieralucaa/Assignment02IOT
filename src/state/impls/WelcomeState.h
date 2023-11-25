#include "./state/State.h"

#include "./components/pir/PIR.h"
#include "./components/outputComponents/OutputManager.h"
#include "./components/cooldown/Cooldown.h"
//#include <arduino-timer.h>
#include "configs.h"

class WelcomeState : public State {
public:
    WelcomeState(OutputManager* o, Pir* awakePir, Cooldown* clock);
    void init();
    StateName changeState();
private:
    Pir* myPir;
    OutputManager* o;
    Cooldown* clock;
    //void flushTimer();
    // Timer<1> clock;
    // Timer* cooldown;
};