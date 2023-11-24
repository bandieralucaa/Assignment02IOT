#include "Servomotor.h"
#include <Arduino.h>

bool Servomotor::isOpen() {
    if (direction == 90) {
        return true;
    } else {
        return false;
    }
}

bool Servomotor::isClose() {
    if (direction == -90) {
        return true;
    } else {
        return false;
    }
}

void Servomotor::open() {
    direction = 90;
}

void Servomotor::close() {
    direction = -90;
}

void Servomotor::stop() {

}