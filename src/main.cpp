#include <Arduino.h>
#include "Controller.h"

Controller* myController;

void setup() {
  Serial.begin(9600);
  myController = new Controller();
}

void loop() {
  myController->execute();
  // Serial.println("CIAOOO");
}
