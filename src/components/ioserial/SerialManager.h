#ifndef __S_M__
#define __S_M__

#include "configs.h"

#include "./task/Task.h"
#include "OutSender.h"
#include "InReceiver.h"


#include "./components/temperature/TemperatureSensor.h"
#include "IOSerialManager.h"



#ifdef DEBUG
#include <Arduino.h>
#endif

class SerialManager: public Task, public OutSender, public InReceiver{
public:
    SerialManager(TemperatureSensor* tS);

    void increaseWashedCar();
    void updateState(String newState);

    bool checkIfOk();

    void init();
    void tick();

private:

    IOSerialManager* ioManager;
    TemperatureSensor* tS;
    int amountCarWashed;
    bool isSolvedProblem;
    String actState;
    
    void executeCommand(String comm);
};


#endif