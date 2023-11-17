// #include <map>
// using namespace std;
#include "Controller.h"

#include "configs.h"


Controller::Controller() {
    OutputManager* out = new OutputManager();

    CarPresenceDetector* myPir = new CarPresenceDetector(PIR_PIN);
    //Led l1 = new Led(LED1_PIN);

    State* s1 = new SleepState(out, ((Pir*) myPir));
    State* s2 = new WelcomeState(out, ((Pir*) myPir));
    myStates = {s1, s2};
    Task* a[] = {((Task*) myPir)};
    s = new Scheduler(1, a);

    actState = SLEEP_STATE;
    // State s1 = new SleepState(myPir);
}

void Controller::execute() {
    s->schedule();
    
    StateName newState = myStates[actState]->changeState();
    if(newState != NONE){
        actState = newState;
        myStates[actState]->init();
    }
}