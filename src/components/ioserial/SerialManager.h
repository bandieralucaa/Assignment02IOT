#ifndef __S_M__
#define __S_M__

#include "configs.h"

#include "./task/Task.h"
#include "OutSender.h"
#include "InReceiver.h"


#include "./components/temperature/TemperatureSensor.h"
//#include "IOSerialManager.h"
#include "MsgService.h"

#include <Arduino.h>


class SerialManager: public Task, public OutSender, public InReceiver{
public:
    SerialManager(TemperatureSensor* tS);

    void increaseWashedCar();
    void updateState(String newState, bool isErrorState);
    //void updateState(String newState);
    //void updateMessage(String newMessage, bool isErrorMessage);

    bool checkIfOk();

    void init();
    void tick();

private:

    TemperatureSensor* tS;
    int amountCarWashed;
    String actState;
    //String actMessage;
    
    bool isSolvedProblem;
    
    void executeCommands(String comm);
    void executeCommandByGui(String comm, String value);

    bool isNewTemp = true;
    bool isNewAmount = false;
    bool isNewState = false; bool isErrorMessage = false;
    // bool isNewMessage = false; 
};


#endif