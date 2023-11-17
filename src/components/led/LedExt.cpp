#include "LedExt.h"
#include <Arduino.h>

LedExt::LedExt(int pin) {
    pinMode(pin, OUTPUT);
    isOn = false;
}

void LedExt::switchOn() {
    digitalWrite(pin, HIGH);
    isOn = true;
}

void LedExt::switchOff() {
    digitalWrite(pin, LOW);
    isOn = false;
}

void LedExt::setIntensity(int intensity) {
    if (isOn)
    {
        analogWrite(pin, intensity);
    }
}