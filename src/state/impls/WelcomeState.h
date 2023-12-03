#include "./state/State.h"
#include "./components/cooldown/Cooldown.h"
#include "./components/lcd/LcdMonitor.h"
#include "./components/led/Light.h"
#include "./components/pir/CarPresenceDetector.h"
#include "configs.h"

class WelcomeState : public State {
public:
    WelcomeState(CarPresenceDetector* awakePir, Cooldown* clock, LcdMonitor* lcd, Light* l1);
    void init();
    StateName changeState();
private:
    CarPresenceDetector* myPir;
    Cooldown* clock;
    LcdMonitor* lcd;
    Light* l1;
};