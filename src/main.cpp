#include <Arduino.h>
#include "ControllerScheduler.h"

ControllerScheduler* myController;

void setup() {
  Serial.begin(115200);
  myController = new ControllerScheduler();
  myController->init(50);
}

void loop() {
  myController->execute();
  // Serial.print(" A ");
}
