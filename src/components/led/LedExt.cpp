#include "LedExt.h"
#include <Arduino.h>

LedExt::LedExt(int pin) {
    pinMode(pin, OUTPUT);
}

void LedExt::switchOn() {
    digitalWrite(pin, HIGH);
}

void LedExt::switchOff() {
    digitalWrite(pin, LOW);
}

void LedExt::setIntensity(int intensity) {
    analogWrite(pin, intensity);
}