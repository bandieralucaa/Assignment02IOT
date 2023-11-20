#include "./state/State.h"

#include "configs.h"
#include "./components/pir/PIR.h"
#include "./components/outputComponents/OutputManager.h"
#include "./components/cooldown/Cooldown.h"


class WelcomeState : public State {
public:
    WelcomeState(OutputManager* o, Pir* awakePir, Cooldown* cool);
    void init();
    StateName changeState();
private:
    Pir* myPir;
    OutputManager* o;
    Cooldown* cool;
};