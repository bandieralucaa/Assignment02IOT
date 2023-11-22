#include "LedExtTimered.h"

LedExtTimered::LedExtTimered(int pin, int delta) : LedExt(pin) {
    this->delta = delta;
    this->isIncrease = true;
}

void LedExtTimered::setFading(int newDelta){
    this->delta = newDelta;
}

void init(){
    this->actIntensity = 0;
    this->setIntensity(this->actIntensity);
    this->isIncrease = true;
};

void tick(){
    int inc = this->isIncrease ? 1 : -1;
    int newInt = this->actIntensity + (inc * this->delta);
}
    