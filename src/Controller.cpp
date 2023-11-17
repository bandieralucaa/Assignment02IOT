#include "configs.h"

#include "Controller.h"

#include "./task/Task.h"
#include "./state/State.h"
#include "./task/Scheduler.h"

#include "./components/outputComponents/OutputManager.h"
#include "./components/pir/CarPresenceDetector.h"

#include "./state/impls/SleepState.h"
#include "./state/impls/WelcomeState.h"





class Controller{
public:

    Scheduler* s;
    StateName actState;
    State* myStates[2];
    

    Controller() {
        OutputManager* out = new OutputManager();

        CarPresenceDetector* myPir = new CarPresenceDetector(PIR_PIN);
        //Led l1 = new Led(LED1_PIN);

        State* s1 = new SleepState(out, myPir);
        State* s2 = new WelcomeState(out, myPir);
        // myStates = {s1, s2};
        Task* a[] = {((Task*) myPir)};
        s = new Scheduler(1, a);

        actState = SLEEP_STATE;
        // State s1 = new SleepState(myPir);
    }

    void execute() {
        s->schedule();
        
        StateName newState = myStates[actState]->changeState();
        if(newState != NONE){
            actState = newState;
            myStates[actState]->init();
        }
    }
};