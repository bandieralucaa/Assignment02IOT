#include <Arduino.h>
#include "Controller.h"

Controller* myController;

void setup() {
  myController = new Controller();
}

void loop() {
  myController->execute();
}
