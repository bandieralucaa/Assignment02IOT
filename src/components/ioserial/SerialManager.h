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
    void updateState(String newState);
    void updateMessage(String newMessage, bool isErrorMessage);

    bool checkIfOk();

    void init();
    void tick();

private:

    //IOSerialManager* ioManager;
    TemperatureSensor* tS;
    int amountCarWashed;
    bool isSolvedProblem;
    String actState;
    String actMessage;
    
    void executeCommand(String comm);

    bool isNewAmount = false;
    bool isNewState = false;
    bool isNewMessage = false;
    bool isErrorMessage = false;
};


#endif