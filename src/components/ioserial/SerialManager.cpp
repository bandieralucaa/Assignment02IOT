#include "SerialManager.h"

SerialManager::SerialManager(TemperatureSensor* tS){
    this->tS = tS;
    this->amountCarWashed = 0;
    this->actState = "";
    this->isSolvedProblem = false;
    //this->ioManager = new IOSerialManager();

    this->period = IOMAN_PERIOD;
}

void SerialManager::increaseWashedCar(){
    this->amountCarWashed++;
    this->isNewAmount = true;
}
    
void SerialManager::updateState(String newState){
    this->actState = newState;
    this->isNewState = true;
}


void SerialManager::updateMessage(String newMessate, bool isErrorMessage){
    this->actMessage = newMessate;
    this->isErrorMessage = isErrorMessage;
    this->isNewMessage = true;
    //this->
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
    MsgService.sendMsg(trasdutter("s-", ""));
    MsgService.sendMsg(trasdutter("c-", "0"));
    MsgService.sendMsg(trasdutter("t-", "0"));
}

void send(bool haveTo, String toSend){
    if(haveTo){
        MsgService.sendMsg(toSend);
    }
}

void sendMessage(bool haveTo, bool isAnError, String mess){
    if(haveTo){
        if(isAnError){
            MsgService.sendMsg(trasdutter("e-", mess));
        } else {
            MsgService.sendMsg(trasdutter("m-", mess));
        }
    }
}

void SerialManager::tick(){
    // this->ioManager->boardSendMsg(trasdutter("s-", this->actState));
    // this->ioManager->boardSendMsg(trasdutter("c-", (String)this->amountCarWashed));
    // this->ioManager->boardSendMsg(trasdutter("t-", (String)this->tS->senseTemperature()));
    send(this->isNewState, trasdutter("s-", this->actState));
    send(true, trasdutter("t-", (String)this->tS->senseTemperature()));
    send(this->isNewAmount, trasdutter("c-", (String)this->amountCarWashed));
    sendMessage(this->isNewMessage, this->isErrorMessage, this->actMessage);
    //MsgService.sendMsg();

    this->isSolvedProblem = false;
    this->isErrorMessage = false;

    this->isNewState = false;
    this->isNewAmount = false;
    this->isNewMessage = false;

    // if (this->ioManager->boardIsMsgAvaiable()){
    //     String tmp = this->ioManager->boardReceiveMsg();
    //     Serial.print(tmp);
    //     executeCommand(tmp);
    // }
    if (MsgService.isMsgAvailable()){
        String tmp = MsgService.receiveMsg()->getContent();//->ioManager->boardReceiveMsg();
        Serial.print(tmp);
        executeCommand(tmp);
    }
}


bool SerialManager::checkIfOk(){
    return this->isSolvedProblem;
}
