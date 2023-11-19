#include "./state/State.h"
#include "./components/pir/PIR.h"
#include "./components/outputComponents/OutputManager.h"

class SleepState : public State {
public:
    SleepState(OutputManager* o, Pir* awakePir);
    void init();
    StateName changeState();
    
private:
    Pir* myPir;
    OutputManager* o;
};