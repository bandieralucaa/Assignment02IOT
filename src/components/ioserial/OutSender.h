#ifndef __OUT_S__
#define __OUT_S__

#include "configs.h"

#include <Arduino.h>


class OutSender{
public:
    virtual void increaseWashedCar() = 0;
    virtual void updateState(String newState, bool isErrorState) = 0;
    virtual void sendTemperature();
    // virtual void updateMessage(String newMessage, bool isErrorMessage) = 0;

};


#endif