#include "configs.h"

#include "Controller.h"

Controller::Controller() {
    OutputManager* out = new OutputManager();

    CarPresenceDetector* myPir = new CarPresenceDetector(PIR_PIN);
    //Led l1 = new Led(LED1_PIN);

    State* s1 = new SleepState(out, ((Pir*) myPir));
    State* s2 = new WelcomeState(out, ((Pir*) myPir));

    myStates = new State*[2]{s1, s2};
    //State* myStates[] = {s1, s2};
    // myStates[0] = s1;
    // myStates[1] = s2;
    // myStates = (State*){s1, s2};
    
    Task* a[] = {((Task*) myPir)};
    s = new Scheduler(1, a);

    actState = SLEEP_STATE;
    myStates[actState]->init();
    
}

void Controller::execute() {
    s->schedule();
    
    StateName newState = myStates[actState]->changeState();
    if (newState != NONE) {
        actState = newState;
        myStates[actState]->init();
    }
}