#include <Arduino.h>
#include "configs.h"
#include "ControllerScheduler.h"

ControllerScheduler* myController;

void setup() {
  pinMode(11, OUTPUT);
  myController = new ControllerScheduler();
  myController->init(SCHEDULE_BASE_PERIOD);
}


void loop() {
  myController->execute();
}


