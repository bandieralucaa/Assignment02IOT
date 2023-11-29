#include "./state/State.h"

#include "./components/pir/PIR.h"
#include "./components/cooldown/Cooldown.h"
#include "./components/lcd/LcdMonitor.h"
#include "./components/led/Led.h"
//#include <arduino-timer.h>
#include "configs.h"

class WelcomeState : public State {
public:
    WelcomeState(Pir* awakePir, Cooldown* clock, LcdMonitor* lcd, Led* l1);
    void init();
    StateName changeState();
private:
    Pir* myPir;
    Cooldown* clock;
    LcdMonitor* lcd;
    Led* l1;
    //void flushTimer();
    // Timer<1> clock;
    // Timer* cooldown;
};