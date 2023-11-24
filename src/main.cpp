#include <Arduino.h>
#include "configs.h"
#include "ControllerScheduler.h"


ControllerScheduler* myController;

void setup() {
  Serial.begin(9600);
  myController = new ControllerScheduler();
  myController->init(SCHEDULE_BASE_PERIOD);
}

void loop() {
  myController->execute();
}
