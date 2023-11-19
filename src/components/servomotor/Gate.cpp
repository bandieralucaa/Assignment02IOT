#include "Servomotor.h"
#include <Arduino.h>

Servomotor::Servomotor(int pin, bool isActOpen) {
    this->pin = pin;
    this->actOpen = isActOpen;
}

bool Servomotor::isOpen() {
    return this->actOpen;
}

void Servomotor::open() {
    //TODO
}

void Servomotor::close() {
    
}

