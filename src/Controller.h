#ifndef __CONTROLLER__
#define __CONTROLLER__

#include "./components/pir/PIR.h"
#include "./task/Task.h"
#include "./state/State.h"

#include "configs.h"


class Controller{
public:
    
    StateName actState;
    State myState[2];
    //map<StateName, State> a;

    Controller(){
        CarPresenceDetector* myPir = new CarPresenceDetector(PIR_PIN);
    }

    void execute(){

    }
};
#endif
