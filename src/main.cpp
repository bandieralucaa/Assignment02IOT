#include <Arduino.h>
#include "Controller.h"

Controller* myController;

void setup() {
  myController = new MyController();
}

void loop() {
  myController->execute();
}
