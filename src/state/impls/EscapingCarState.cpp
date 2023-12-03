#include "EscapingCarState.h"

EscapingCarState::EscapingCarState(CarDistanceDetector* sonar, CarPresenceDetector* pir, Gate* gate, LcdMonitor* lcd){
    this->sonar = sonar;
    this->pir = pir;
    this->gate = gate;
    this->lcd = lcd;
}

void EscapingCarState::init(){
    this->sonar->start();
    this->pir->start();
    this->gate->start();
}

StateName EscapingCarState::changeState(){
    if(this->pir->isAnyone() || !this->sonar->isAboveMax()){
        return ENTERING_STATE;
    } else {
        this->gate->close();
        this->lcd->writeOnLcd(MYSTRING_1);
        while(!this->gate->isClose());
        this->gate->stopGate();
        this->lcd->clear();
        return SLEEP_STATE;
    }
}