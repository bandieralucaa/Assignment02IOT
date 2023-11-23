#ifndef __CONTROLLER__
#define __CONTROLLER__

#include "./components/pir/PIR.h"
#include "./components/led/Led.h"

#include "./task/Task.h"
#include "./state/State.h"
#include "./components/outputComponents/OutputManager.h"
#include "./components/pir/CarPresenceDetector.h"
#include "./components/distanceSensor/CarDistanceDetector.h"
#include "./components/led/LedExtTimered.h"

#include "./state/impls/SleepState.h"
#include "./state/impls/WelcomeState.h"
#include "./state/impls/PreEnteringState.h"
#include "./state/impls/EnteringState.h"
#include "./state/impls/WaitEnteringState.h"

#include "configs.h"

#include <arduino-timer.h>


class ControllerScheduler{
public:
    ControllerScheduler();
    void init(unsigned long basePeriod);
    void execute();

// private:
//     StateName actState;
//     State** myStates;
//     Timer<1> timer;
    
//     Task** myTasks;
//     int amountTask;
};

#endif
