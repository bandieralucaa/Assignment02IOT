// Button.cpp
#include "Button.h"

Button::Button(int pin) {
  buttonPin = pin;
  pinMode(buttonPin, INPUT);
  lastButtonState = LOW;
  buttonState = LOW;
  lastDebounceTime = 0;
  debounceDelay = 500; // Aumentato il periodo di debounce a 500 millisecondi
}

void Button::update() {
  int reading = digitalRead(buttonPin);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;

    
    }
  }

  lastButtonState = reading;
}

bool Button::isPressed() {
  return buttonState == HIGH;
}