#include <Arduino.h>
#include "ControllerScheduler.h"
#include "configs.h"

ControllerScheduler* myController;

void setup() {
  Serial.begin(9600);
  myController = new ControllerScheduler();
  myController->init(SCHEDULE_BASE_PERIOD);
}

void loop() {
  myController->execute();
  // Serial.print(" A ");
}
