#include <Arduino.h>
#include "configs.h"
#include "ControllerScheduler.h"


ControllerScheduler* myController;

#define PROG
#ifndef PROG
#include "./components/ioserial/SerialManager.h"  
#include "./components/serialcomm/MsgService.h"

SerialManager* sm;
MsgServiceClass* m;


#endif


void setup() {
  //Serial.begin(9600);
  #ifdef PROG
  myController = new ControllerScheduler();
  myController->init(SCHEDULE_BASE_PERIOD);
  #endif
  #ifndef PROG
  m->init();
  //sm = new SerialManager();

  #endif
}

#ifndef PROG
bool swit = false;
#endif

void loop() {
  #ifdef PROG
  myController->execute();
  #endif
  #ifndef PROG


  if (MsgService.isMsgAvailable()) {
    Msg* msg = MsgService.receiveMsg();    
    if (msg->getContent() == "ping"){
       delay(500);
       swit ? MsgService.sendMsg("pong") : MsgService.sendMsg("pang");
       swit = !swit;
    }
    /* NOT TO FORGET: message deallocation */
    delete msg;
  }



  // Serial.println("Helo");
  // //Serial.print(a(counter++));
  // delay(500);

  #endif
  //Serial.print("AAAAAA ");
}


