#include "./state/State.h"
#include "./components/pir/PIR.h"
#include "components/outputComponents/OutputManager.h"

class WelcomeState : public State {
public:

    Pir* myPir;
    OutputManager* o;

    WelcomeState(OutputManager* o, Pir* awakePir){
        myPir = awakePir;
    }

    void init() {
        // o-> STAMPA CIAOOO
    }

    StateName changeState(){
        if (!myPir->isAnyone()){
            return SLEEP_STATE;
        } else {
            return NONE;
        }
    };
};