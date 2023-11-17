#include "./state/State.h"
#include "./components/PIR.h"

class SleepState : public State {
public:

    Pir* myPir;

    SleepState(){

    }

    void init(){

    }

    virtual StateName changeState(){
        if (myPir->isAnyone()){
            return SLEEP_STATE;
        }  
    };
};