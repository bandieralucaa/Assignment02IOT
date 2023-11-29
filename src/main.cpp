#include <Arduino.h>
#include "configs.h"
#include "ControllerScheduler.h"


ControllerScheduler* myController;

#define PROG
#ifndef PROG
#include "./components/ioserial/SerialManager.h"  

SerialManager* sm;
#endif


void setup() {
  Serial.begin(9600);
  #ifdef PROG
  myController = new ControllerScheduler();
  myController->init(SCHEDULE_BASE_PERIOD);
  #endif
  #ifndef PROG
  //sm = new SerialManager();
  #endif
}

int counter = 0;

String a(int value){
  int amount = log10(value)+1;
  Serial.print(amount);
  return "\n";
}


void loop() {
  #ifdef PROG
  myController->execute();
  #endif
  #ifndef PROG

  Serial.print(a(counter++));
  delay(100);
  #endif
  //Serial.print("AAAAAA ");
}


