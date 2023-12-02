#include "./state/State.h"
// #include "./components/pir/PIR.h"
// #include "./components/led/Light.h"
// #include "./components/lcd/LcdMonitor.h"
// #include "./components/ioserial/OutSender.h"
#include "./components/pir/CarPresenceDetector.h"
#include "./components/led/Light.h"
#include "./components/lcd/LcdMonitor.h"
#include "./components/ioserial/OutSender.h"


class SleepState : public State {
public:
    SleepState(CarPresenceDetector* awakePir, Light* l1, LcdMonitor* lcd, OutSender* out);
    void init();
    StateName changeState();
    
private:
    CarPresenceDetector* myPir;
    Light* l1;
    LcdMonitor* lcd;
    OutSender* out;
};