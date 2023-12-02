#include "EscapingCarState.h"

EscapingCarState::EscapingCarState(CarDistanceDetector* sonar, CarPresenceDetector* pir){
    this->sonar = sonar;
    this->pir = pir;
}

void EscapingCarState::init(){
}

StateName EscapingCarState::changeState(){
    if(this->pir->isAnyone() || !this->sonar->isAboveMax()){
        return ENTERING_STATE;
    } else {
        return SLEEP_STATE;
    }
}