#include "Cooldown.h

Cooldown::Cooldown(bool pressed) {
    this->pressed = false;
}

bool Cooldown::isOver() {
    pressed = !pressed;
    return pressed;
}