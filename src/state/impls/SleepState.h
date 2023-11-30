#include "./state/State.h"
#include "./components/pir/PIR.h"
#include "./components/led/Light.h"
#include "./components/lcd/LcdMonitor.h"
#include "./components/ioserial/OutSender.h"

class SleepState : public State {
public:
    SleepState(Pir* awakePir, Light* l1, LcdMonitor* lcd, OutSender* out);
    void init();
    StateName changeState();
    
private:
    Pir* myPir;
    Light* l1;
    LcdMonitor* lcd;
    OutSender* out;
};