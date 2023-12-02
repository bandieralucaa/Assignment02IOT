#include "SerialManager.h"

#include <Arduino.h>
#define AMOUNT_COMM 4
//#define S_DEBUG

#define COMMAND_CHAR '_'
#define ARGUMENT_CHAR ':'

SerialManager::SerialManager(TemperatureSensor* tS){
    this->tS = tS;
    this->amountCarWashed = 0;
    this->actState = "";
    // this->actMessage = "";
    this->isSolvedProblem = false;
    //MsgService.init();
    this->period = IOMAN_PERIOD;
    Serial.begin(9600);
    Serial.setTimeout(1000);
}

String trasdutter2(char command, String value){
    return ((String)COMMAND_CHAR) + ((String)command) + ((String)ARGUMENT_CHAR) + value;
}

// String trasdutter(String codec, String value){
//     return codec + value + "\n";
// }

String trasdutter2(char command, String value){
    return ((String)COMMAND_CHAR) + ((String)command) + ((String)ARGUMENT_CHAR) + value;
}

void SerialManager::increaseWashedCar(){
    this->amountCarWashed++;
    #ifdef S_DEBUG
    Serial.println((String)this->amountCarWashed);
    #endif
    this->isNewAmount = true;


    String comm = trasdutter2('c', this->actState);

    MsgService.sendMsg(comm);
}

// virtual void updateState(String newState, bool isErrorState) = 0;
void SerialManager::updateState(String newState, bool isErrorState){
    this->actState = newState;
    this->isErrorMessage = isErrorState;
    this->isSolvedProblem = !isErrorState;
    #ifdef S_DEBUG
    Serial.println(newMessage + " " + (String)isErrorMessage);
    #endif
    this->isNewState = true;

    char com;
    if (this->isErrorMessage){
        com = 'e';
    } else {
        com = 'm';
    }
        // comm += trasdutter2(com , this->actMessage);
    String comm = trasdutter2(com , this->actState);

    MsgService.sendMsg(comm);
    // this->actState = newState;
    // #ifdef S_DEBUG
    // Serial.print(newState)
    // #endif
    // this->isNewState = true;
}


// void SerialManager::updateMessage(String newMessage, bool isErrorMessage){
//     this->actMessage = newMessage;
//     this->isErrorMessage = isErrorMessage;
//     this->isSolvedProblem = !isErrorMessage;
//     #ifdef S_DEBUG
//     Serial.print(newMessage + " " + (String)isErrorMessage);
//     #endif
//     this->isNewMessage = true;
// }






<<<<<<< HEAD

=======
>>>>>>> 50281dacf457c6b60823f776a73345a578bcce35


void SerialManager::init(){
    String comm = "";
    comm += trasdutter2('t', (String)this->tS->senseTemperature());
    // comm += trasdutter2('s', "Powering up");
    comm += trasdutter2('c', "0");
    comm += trasdutter2('m' , STATE1);
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

static int i = 0;
#define UPGRADE_RATIO (((int) (((IOMAN_PERIOD)*1.0) / ((SCHEDULE_BASE_PERIOD)*1.0)))+1)

void SerialManager::sendTemperature() {
    String comm = "";
    comm += trasdutter2('t', (String)this->tS->senseTemperature());
    i++;
    if(i == (UPGRADE_RATIO*4)){
        MsgService.sendMsg(comm);
        i=0;
    }
    
}


void SerialManager::executeCommands(String comm){
    int a = comm.length();
    int i=0;
    String command = "";
    String argument = "";
    bool parsingCommand = true;
    Serial.print(comm);
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


//void SerialManager::manageMsg() {
    //String comm = "";
    
        // comm += trasdutter2('s', this->actState);
    //}
    // if (this->isNewAmount){
    //     comm += trasdutter2('c', (String)this->amountCarWashed);
    // }
    
    //MsgService.sendMsg(comm);
    //Serial.println((String) this->isNewState + (String)this->isNewAmount + (String)this->isNewMessage);
    // this->ioManager->boardSendMsg(trasdutter("s-", this->actState));
    // this->ioManager->boardSendMsg(trasdutter("c-", (String)this->amountCarWashed));
    // this->ioManager->boardSendMsg(trasdutter("t-", (String)this->tS->senseTemperature()));
    // send(this->isNewState, trasdutter("s-", this->actState));
    // send(true, trasdutter("t-", (String)this->tS->senseTemperature()));
    // send(this->isNewAmount, trasdutter("c-", (String)this->amountCarWashed));
    // sendMessage(this->isNewMessage, this->isErrorMessage, this->actMessage);
    //MsgService.sendMsg();

    //this->isNewState = false;
    //this->isNewAmount = false;
    //this->isNewMessage = false;

    // if (this->ioManager->boardIsMsgAvaiable()){
    //     String tmp = this->ioManager->boardReceiveMsg();
    //     Serial.print(tmp);
    //     executeCommand(tmp);
    // }
    
//}



void SerialManager::tick(){
    if (MsgService.isMsgAvailable()){           
        Msg* msg = MsgService.receiveMsg();    
        delay(100);
        if (msg->getContent().length() > 0) {
            //delay(500);
            this->executeCommands(msg->getContent());
        }
        delete msg;
    }   
}


bool SerialManager::checkIfOk(){
    return this->isSolvedProblem;
}
