#include "TemperatureSensorTimered.h"
#include "configs.h"

TemperatureSensorTimered::TemperatureSensorTimered(int pin){
    this->myPin = pin;
}

void TemperatureSensorTimered::init(){
    this->tick();
}

double TemperatureSensorTimered::senseTemperature(){
    return this->lastTemp;
}

bool TemperatureSensorTimered::isOverHeat(){
    return this->lastTemp > DANGEROUS_TEMP;
}

void TemperatureSensorTimered::tick(){
    // codice ispirato da internet
    int sensorInput = analogRead(this->myPin); 
    double temp = (double)sensorInput / 1024; 
    temp = temp * 5; 
    temp = temp - 0.5; 
    temp = temp * 100; 
    
    #ifdef TEMP_DEBUG
    Serial.print("Current Temperature: ");
    Serial.println(temp);
    #endif

    this->lastTemp = temp;
}