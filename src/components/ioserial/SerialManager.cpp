#include "SerialManager.h"

#include <Arduino.h>

#define COMMAND_CHAR '_'
#define ARGUMENT_CHAR ':'

SerialManager::SerialManager(TemperatureSensor* tS){
    this->tS = tS;
    this->amountCarWashed = 0;
    this->actState = "";
    this->isSolvedProblem = true;
    this->period = IOMAN_PERIOD;
    MsgService.init();
    //Serial.begin(9600);
    Serial.setTimeout(100);
}

String trasdutter(char command, String value){
    return ((String)COMMAND_CHAR) + ((String)command) + ((String)ARGUMENT_CHAR) + value;
}

void SerialManager::increaseWashedCar(){
    this->amountCarWashed++;
    this->isNewAmount = true;

    #ifdef S_DEBUG
    Serial.println((String)this->amountCarWashed);
    #endif

    String comm = trasdutter('c', (String) this->amountCarWashed);
    MsgService.sendMsg(comm);
}

void SerialManager::updateState(String newState, bool isErrorState){
    this->actState = newState;
    this->isErrorMessage = isErrorState;
    this->isSolvedProblem = !isErrorState;

    #ifdef S_DEBUG
    Serial.println(newMessage + " " + (String)isErrorMessage);
    #endif

    this->isNewState = true;

    char com;
    if (isErrorState){
        com = 'e';
    } else {
        com = 'm';
    }

    String comm = trasdutter(com , newState);
    MsgService.sendMsg(comm);
}




void SerialManager::init(){
    String comm = "";
    comm += trasdutter('t', (String)this->tS->senseTemperature());
    comm += trasdutter('c', "0");
    comm += trasdutter('m' , STATE1);
    MsgService.sendMsg(comm);
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


void SerialManager::sendTemperature() {
    String comm = "";
    comm += trasdutter('t', (String)this->tS->senseTemperature());
    
    MsgService.sendMsg(comm);
}


void SerialManager::executeCommands(String comm){
    unsigned int a = comm.length();
    unsigned int i=0;
    String command = "";
    String argument = "";
    bool parsingCommand = true;
    #ifdef DEBUG_IOMAN_WITHOUT_CONSOLE
    Serial.print(comm);
    #endif
    while(i<a || comm.charAt(i) != '\n') {
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
        i++;

    }
}


void SerialManager::tick(){
    if (MsgService.isMsgAvailable()){           
        Msg* msg = MsgService.receiveMsg();    
        //delay(100);
        if (msg->getContent().length() > 0) {
            #ifdef DEBUG_IOMAN_WITHOUT_CONSOLE
            Serial.println(msg->getContent());
            #endif
            this->isSolvedProblem = true;

            /* Abbiamo provato a gestire l'input della gui "in modo dinamico" (ovvero parsando
            la stringa di ingresso ricevuta e gestendo tutte le eventuali chiamate a funzione nella funzione apposita
            executeCommands()), ma senza successo.
            Essendo che la Gui doveva assolvere solo una funzione, abbiamo deciso di gestire direttamente questa casistica*/
            //this->executeCommands(msg->getContent());
        }
        delete msg;
    }   
}


bool SerialManager::checkIfOk(){
    return this->isSolvedProblem;
}
