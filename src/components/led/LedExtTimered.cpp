#include "LedExtTimered.h"

LedExtTimered::LedExtTimered(int pin, int delta) {
    this->pin = pin;
    this->delta = delta;
    this->isIncrease = true;
    this->period = LED_BLINKING_PERIOD;
}

void LedExtTimered::setFading(int newDelta){
    this->delta = newDelta;
}


void LedExtTimered::updateIntensity(int toUpdate){
    this->actIntensity = toUpdate;
    this->setIntensity(this->actIntensity);
}


void LedExtTimered::init(){
    updateIntensity(0);
    this->isIncrease = true;
};


void LedExtTimered::tick(){
    if (!this->isBlinking){
        return;
    }
    int inc = this->isIncrease ? 1 : -1;
    int newInt = this->actIntensity + (inc * this->delta);
    if (newInt >= MAX_INTENSITY){
        this->isIncrease = false;
        newInt = MAX_INTENSITY;
    } else if (newInt <= MIN_INTENSITY){
        this->isIncrease = true;
        newInt = MIN_INTENSITY;
    }
    updateIntensity(newInt);
}
    


void LedExtTimered::canBlink(bool canBlink){
    this->isBlinking = canBlink;
}





void LedExtTimered::switchOn() {
    digitalWrite(pin, HIGH);
    isOn = true;
    this->setIntensity(MAX_INTENSITY);
    this->isIncrease = false;
}

void LedExtTimered::switchOff() {
    digitalWrite(pin, LOW);
    isOn = false;
}

void LedExtTimered::setIntensity(int intensity) {
    if (isOn)
    {
        analogWrite(pin, intensity);
    }
}