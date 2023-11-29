#ifndef __IO_S_M__
#define __IO_S_M__

#include "Arduino.h"
#include "SerialManager.h"

class IOSerialManager{
public:
    IOSerialManager(SerialManager* toNotify);
    void boardSendMsg(String toSend);
    String boardReceiveMsg();
    bool boardIsMsgAvaiable();
private:
    bool isInMsgReady;
    String lastInCommand;  
    SerialManager* notifier;
    //void serialEvent();
};


#endif