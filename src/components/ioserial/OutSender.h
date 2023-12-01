#ifndef __OUT_S__
#define __OUT_S__

#include "configs.h"

#ifdef DEBUG
#include <Arduino.h>
#endif

class OutSender{
public:
    virtual void increaseWashedCar() = 0;
    virtual void updateState(String newState, bool isErrorState) = 0;
    // virtual void updateMessage(String newMessage, bool isErrorMessage) = 0;

};


#endif