#include "./state/State.h"
#include "./components/pir/PIR.h"

class SleepState : public State {
public:

    Pir* myPir;

    SleepState(Pir* awakePir){
        myPir = awakePir;
    }

    void init() {

    }

    StateName changeState(){
        if (myPir->isAnyone()){
            return WELCOME_STATE;
        }
        
    };
};