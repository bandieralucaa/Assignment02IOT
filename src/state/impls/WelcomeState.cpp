
#include "./components/pir/PIR.h"
#include "components/outputComponents/OutputManager.h"
#include "./state/impls/WelcomeState.h"

WelcomeState::WelcomeState(OutputManager* o, Pir* awakePir){
    myPir = awakePir;
}

void State::init() {
    // o-> STAMPA CIAOOO
}

StateName WelcomeState::changeState() {
    if (!myPir->isAnyone()){
        return SLEEP_STATE;
    } else {
        return NONE;
    }
};
