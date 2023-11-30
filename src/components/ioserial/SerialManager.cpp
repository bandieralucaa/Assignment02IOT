#include "SerialManager.h"

#include <Arduino.h>
#define AMOUNT_COMM 4


SerialManager::SerialManager(TemperatureSensor* tS){
    this->tS = tS;
    this->amountCarWashed = 0;
    this->actState = "";
    this->actMessage = "";
    this->isSolvedProblem = false;
    
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
    this->isSolvedProblem = !isErrorMessage;

    this->isNewMessage = true;
}





// String trasdutter(String codec, String value){
//     return codec + value + "\n";
// }

String trasdutter2(char command, String value){
    return "$" + ((String)command) + "." + value;
}


void SerialManager::init(){
    String comm = "";
    comm += trasdutter2('t', (String)this->tS->senseTemperature());
    comm += trasdutter2('s', "Powering up");
    comm += trasdutter2('c', "0");
    comm += trasdutter2('m' , "Powering up");
    MsgService.sendMsg(comm);
    // MsgService.sendMsg(trasdutter("s-", "Powering up"));
    // MsgService.sendMsg(trasdutter("m-", "Powering up"));
    // MsgService.sendMsg(trasdutter("c-", "0"));
    // MsgService.sendMsg(trasdutter("t-", "0"));
}

void SerialManager::executeCommandByGui(String command, String value){
    char c = command.charAt(0);
    switch (c)
    {
    case 'o':
        this->isSolvedProblem = true;
        break;
    
    default:
        break;
    }
}

void SerialManager::executeCommands(String comm){
    int a = comm.length();
    int i=0;
    String command = "";
    String argument = "";
    bool parsingCommand = true;
    while(i<a) {
        char c = comm.charAt(i);
        switch (c)
        {
        case '$':
            if(command.length() > 0){
                executeCommandByGui(command, argument);
            }
            command = "";
            argument = "";
            parsingCommand = true;
            break;
        
        case '.':
            parsingCommand = false;
            break;

        default:
            parsingCommand ? command += c : argument += c;
            break;
        }

    }

}


// void send(bool haveTo, String toSend){
//     if(haveTo){
//         MsgService.sendMsg(toSend);
//     }
// }

// void sendMessage(bool haveTo, bool isAnError, String mess){
//     if(haveTo){
//         if(isAnError){
//             MsgService.sendMsg(trasdutter("e-", mess));
//         } else {
//             MsgService.sendMsg(trasdutter("m-", mess));
//         }
//     }
// }

void SerialManager::tick(){
    String comm = "";
    comm += trasdutter2('t', (String)this->tS->senseTemperature());
    comm += this->isNewState ? trasdutter2('s', this->actState) : "";
    comm += this->isNewAmount ? trasdutter2('c', (String)this->amountCarWashed) : "";
    comm += this->isNewMessage ? trasdutter2(this->isErrorMessage ? 'e' : 'm' , this->actMessage) : "";
    MsgService.sendMsg(comm);
    // this->ioManager->boardSendMsg(trasdutter("s-", this->actState));
    // this->ioManager->boardSendMsg(trasdutter("c-", (String)this->amountCarWashed));
    // this->ioManager->boardSendMsg(trasdutter("t-", (String)this->tS->senseTemperature()));
    // send(this->isNewState, trasdutter("s-", this->actState));
    // send(true, trasdutter("t-", (String)this->tS->senseTemperature()));
    // send(this->isNewAmount, trasdutter("c-", (String)this->amountCarWashed));
    // sendMessage(this->isNewMessage, this->isErrorMessage, this->actMessage);
    //MsgService.sendMsg();

    this->isNewState = false;
    this->isNewAmount = false;
    this->isNewMessage = false;

    // if (this->ioManager->boardIsMsgAvaiable()){
    //     String tmp = this->ioManager->boardReceiveMsg();
    //     Serial.print(tmp);
    //     executeCommand(tmp);
    // }
    if (MsgService.isMsgAvailable()){
        Msg* m = MsgService.receiveMsg();
        String tmp = m->getContent();//->ioManager->boardReceiveMsg();
        delete m;
        executeCommands(tmp);
    }
}

















bool SerialManager::checkIfOk(){
    return this->isSolvedProblem;
}
