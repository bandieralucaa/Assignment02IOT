#ifndef __S_M__
#define __S_M__

#include "configs.h"

#include "./task/Task.h"
#include "OutSender.h"
#include "InReceiver.h"


#include "./components/temperature/TemperatureSensor.h"
#include "MsgService.h"

#include <Arduino.h>


class SerialManager: public Task, public OutSender, public InReceiver{
public:
    SerialManager(TemperatureSensor* tS);

    void sendTemperature();
    void increaseWashedCar();
    void updateState(String newState, bool isErrorState);
    
    bool checkIfOk();

    void init();
    void tick();

    bool updateAndCheckTime(int millis){
        bool res = false;
        this->millis += millis;
        if (this->millis >= this->period){
            res = true;
            this->millis = 0;
        }
        return res;
    };


private:
    TemperatureSensor* tS;
    int amountCarWashed;
    String actState;
    
    bool isSolvedProblem = false;
    
    void executeCommands(String comm);
    void executeCommandByGui(String comm, String value);

    bool isNewTemp = true;
    bool isNewAmount = false;
    bool isNewState = false; 
    bool isErrorMessage = false;
};


#endif