#include "SerialManager.h"

SerialManager::SerialManager(TemperatureSensor* tS){
    this->tS = tS;
    this->amountCarWashed = 0;
    this->actState = "";
    this->isSolvedProblem = false;
    this->ioManager = new IOSerialManager(this);

    this->period = IOMAN_PERIOD;
}

void SerialManager::increaseWashedCar(){
    this->amountCarWashed++;
}
    
void SerialManager::updateState(String newState){
    this->actState = newState;
}

String trasdutter(String codec, String value){
    return codec + value + "\n";
}


// String byIntToString(int value){
//     int amount = log10(value);
//     //Serial.print();
// }

void SerialManager::executeCommand(String comm){
    if(comm.charAt(0) == 'o'){
        this->isSolvedProblem = true;
    }
}

void SerialManager::init(){
    this->tick();
}

void SerialManager::tick(){
    this->ioManager->boardSendMsg(trasdutter("s-", this->actState));
    this->ioManager->boardSendMsg(trasdutter("c-", (String)this->amountCarWashed));
    this->ioManager->boardSendMsg(trasdutter("t-", (String)this->tS->senseTemperature()));

    this->isSolvedProblem = false;

    if (this->ioManager->boardIsMsgAvaiable()){
        String tmp = this->ioManager->boardReceiveMsg();
        executeCommand(tmp);
    }
}



