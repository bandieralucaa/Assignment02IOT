// #include <map>
// using namespace std;
#include "Controller.h"

#include "./components/pir/CarPresenceDetector.h"
#include "./task/Task.h"
#include "./state/State.h"
#include "./task/Scheduler.h"
#include "./components/outputComponents/OutputDevice.h"

#include "configs.h"


class MyController : public Controller{
public:

    Scheduler* s;
    StateName actState;
    State* myStates[2];
    // map<StateName, State> a;

    MyController() {
        OutputDevice* out = new OutputManager();

        CarPresenceDetector* myPir = new CarPresenceDetector(PIR_PIN);
        //Led l1 = new Led(LED1_PIN);

        State* s1 = new SleepState(out, myPir);
        State* s2 = new WelcomeState(out, myPir);
        // myStates = {s1, s2};

        s = new Scheduler(2, {s1,s2});
        actState = SLEEP_STATE;
        // State s1 = new SleepState(myPir);
    }

    void execute() {
        //s fai
        
        StateName newState = myStates[actState]->changeState();
        if(newState != NONE){
            actState = newState;
            myStates[actState]->init();
        }
    }
};