#include <Arduino.h>
#include "Controller.h"

Controller* myController;

void setup() {
  Serial.begin(9600);
  myController = new Controller();
}

void loop() {
  myController->execute();
<<<<<<< HEAD
  // Serial.println("CIAOOO");
=======
  // Serial.print(" A ");
>>>>>>> tmp3
}
