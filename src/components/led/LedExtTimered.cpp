#include "LedExtTimered.h"

LedExtTimered::LedExtTimered(int pin, int delta) {
    this->pin = pin;
    this->delta = delta;
    this->isIncrease = true;
    this->period = 50;
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
    int inc = this->isIncrease ? 1 : -1;
    int newInt = this->actIntensity + (inc * this->delta);
    if (newInt >= 255){
        this->isIncrease = false;
        newInt = 255;
    } else if (newInt <= 0){
        this->isIncrease = true;
        newInt = 255;
    }
    updateIntensity(newInt);
}
    





void LedExtTimered::switchOn() {
    digitalWrite(pin, HIGH);
    isOn = true;
}

void LedExtTimered::switchOff() {
    digitalWrite(pin, LOW);
    isOn = false;
}

void LedExtTimered::setIntensity(int intensity) {
    if (isOn)
    {
        analogWrite(pin, intensity);
        // Serial.print("\n" + (String)pin + " " + (String)intensity + "\n");
    }
}