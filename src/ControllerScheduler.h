#ifndef __CONTROLLER__
#define __CONTROLLER__

#include "configs.h"

#include "./components/pir/PIR.h"
#include "./components/led/Led.h"

#include "./task/Task.h"
#include "./state/State.h"
#include "./components/outputComponents/OutputManager.h"
#include "./components/pir/CarPresenceDetector.h"
#include "./components/distanceSensor/CarDistanceDetector.h"
#include "./components/led/LedExtTimered.h"
#include "./components/button/WashingMachineButton.h"
#include "./components/temperature/TemperatureSensor.h"
#include "./components/cooldown/Cooldown.h"
#include "./components/lcd/MyLcdMonitor.h"
#include "./components/led/Led.h"
//#include <arduino-timer.h>



#include "./state/impls/SleepState.h"
#include "./state/impls/WelcomeState.h"
#include "./state/impls/PreEnteringState.h"
#include "./state/impls/EnteringState.h"
#include "./state/impls/WaitEnteringState.h"
#include "./state/impls/AfterEnteringState.h"
#include "./state/impls/WaitConfirmState.h"
#include "./state/impls/WashingState.h"
#include "./state/impls/PreWashingDoneState.h"
#include "./state/impls/WashingDoneState.h"
#include "./state/impls/LeftingState.h"
#include "./state/impls/AfterWashingDoneState.h"

#include "./state/impls/WarningState.h"
#include "./state/impls/HotState.h"

class ControllerScheduler{
public:
    ControllerScheduler();
    void init(unsigned long basePeriod);
    void execute();
};

#endif
