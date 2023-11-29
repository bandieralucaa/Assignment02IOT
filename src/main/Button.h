// Button.h
#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

class Button {
public:
  Button(int pin);

  void update();
  bool isPressed();

private:
  int buttonPin;
  int lastButtonState;
  int buttonState;
  unsigned long lastDebounceTime;
  unsigned long debounceDelay;
};

#endif