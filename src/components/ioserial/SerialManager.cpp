#include "SerialManager.h"

#include <Arduino.h>
#define AMOUNT_COMM 4

#define COMMAND_CHAR '?'
#define ARGUMENT_CHAR '#'

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
    #ifdef S_DEBUG
    Serial.print((String)this->amountCarWashed);
    #endif
    this->isNewAmount = true;
}


void SerialManager::updateState(String newState){
    this->actState = newState;
    #ifdef S_DEBUG
    Serial.print(newState)
    #endif
    this->isNewState = true;
}


void SerialManager::updateMessage(String newMessage, bool isErrorMessage){
    this->actMessage = newMessage;
    this->isErrorMessage = isErrorMessage;
    this->isSolvedProblem = !isErrorMessage;
    #ifdef S_DEBUG
    Serial.print(newMessage + " " + (String)isErrorMessage);
    #endif
    this->isNewMessage = true;
}





// String trasdutter(String codec, String value){
//     return codec + value + "\n";
// }

String trasdutter2(char command, String value){
    return ((String)COMMAND_CHAR) + ((String)command) + ((String)ARGUMENT_CHAR) + value;
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
        case COMMAND_CHAR:
            if(command.length() > 0){
                executeCommandByGui(command, argument);
            }
            command = "";
            argument = "";
            parsingCommand = true;
            break;
        
        case ARGUMENT_CHAR:
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
    //if(this->isNewState){
        comm += trasdutter2('s', this->actState);
    //}
    if (this->isNewAmount){
        comm += trasdutter2('c', (String)this->amountCarWashed);
    }
    //if(this->isNewMessage){
    char com;
    if (this->isErrorMessage){
        com = 'e';
    } else {
        com = 'm';
    }
        comm += trasdutter2(com , this->actMessage);
    //}
    MsgService.sendMsg(comm);
    Serial.println((String) this->isNewState + (String)this->isNewAmount + (String)this->isNewMessage);
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
