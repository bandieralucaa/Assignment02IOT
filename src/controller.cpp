// #include <map>
using namespace std;

#include "./components/pir/PIR.h"
#include "./task/Task.h"
#include "./state/State.h"
#include "./components/outputComponents/outputs.h"

#include "configs.h"


class Controller{
public:

    StateName actState;
    State myState[2];
    //map<StateName, State> a;

    Controller(){
        OutputDevice out = new OutputManager();

        CarPresenceDetector* myPir = new CarPresenceDetector(PIR_PIN);
        Led l1 = new Led(LED1_PIN);

        State s1 = new SleepState(myPir)
        State s2 = new WelcomeState(myPir)
        myState = {s1, s2}
        // State s1 = new SleepState(myPir);
    }

    void execute() {

    }
};