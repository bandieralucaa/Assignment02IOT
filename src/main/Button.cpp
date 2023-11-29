#include "Button.h"

Button::Button(int pin) {
  buttonPin = pin;
  pinMode(buttonPin, INPUT);
  lastButtonState = LOW;
  buttonState = LOW;
}

void Button::update() {
  int reading = digitalRead(buttonPin);

  if (reading != lastButtonState) {
    // Cambiamento di stato rilevato
    buttonState = reading;
  }

  lastButtonState = reading;
}

bool Button::isPressed() {
  return buttonState == HIGH;
}