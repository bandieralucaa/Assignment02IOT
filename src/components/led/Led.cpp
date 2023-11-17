#include "Led.h"
#include <Arduino.h>

Led::Led(int pin) {
    pinMode(pin, OUTPUT);
}

void Led::switchOn() {
    digitalWrite(pin, HIGH);
}

void Led::switchOff() {
    digitalWrite(pin, LOW);
}