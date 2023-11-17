// #include <map>
using namespace std;

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
        //Pir myPir = new CarPresenceDetector(PIR_PIN);
    }

    void execute(){

    }
};