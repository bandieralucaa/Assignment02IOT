#include "./state/State.h"
#include "./components/pir/PIR.h"

class WelcomeState : public State {
public:

    Pir* myPir;

    WelcomeState(Pir* awakePir){
        myPir = awakePir;
    }

    void init() {

    }

    StateName changeState(){
        if (!myPir->isAnyone()){
            return SLEEP_STATE;
        }
    };
};