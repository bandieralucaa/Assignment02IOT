#ifndef __CONTROLLER__
#define __CONTROLLER__

#include "./components/pir/PIR.h"
#include "./components/led/Led.h"

#include "./task/Task.h"
#include "./task/Scheduler.h"
#include "./state/State.h"
#include "./components/outputComponents/OutputManager.h"
#include "./components/pir/CarPresenceDetector.h"


#include "./state/impls/SleepState.h"
#include "./state/impls/WelcomeState.h"
#include "./state/impls/PreEnteringState.h"
#include "./state/impls/EnteringState.h"


#include "configs.h"



class Controller{
public:
    Controller();
    void execute();

private:
    Scheduler* s;
    StateName actState;
    State** myStates;
};

#endif
