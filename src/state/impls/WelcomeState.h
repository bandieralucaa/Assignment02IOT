#include "./state/State.h"

//#include "./components/pir/PIR.h"
#include "./components/cooldown/Cooldown.h"
#include "./components/lcd/LcdMonitor.h"
#include "./components/led/Led.h"

#include "./components/pir/CarPresenceDetector.h"

//#include <arduino-timer.h>
#include "configs.h"

class WelcomeState : public State {
public:
    WelcomeState(CarPresenceDetector* awakePir, Cooldown* clock, LcdMonitor* lcd, Led* l1);
    void init();
    StateName changeState();
private:
    CarPresenceDetector* myPir;
    Cooldown* clock;
    LcdMonitor* lcd;
    Led* l1;
};