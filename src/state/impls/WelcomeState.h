#include "./state/State.h"
#include "./components/pir/PIR.h"
#include "./components/outputComponents/OutputManager.h"


class WelcomeState : public State {
public:
    WelcomeState(OutputManager* o, Pir* awakePir);
    void init();
    StateName changeState();
private:
    Pir* myPir;
    OutputManager* o;
};