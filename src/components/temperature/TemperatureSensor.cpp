#include "TemperatureSensor.h"
#include "configs.h"

TemperatureSensor::TemperatureSensor(int pin){
    this->myPin = pin;
}

double TemperatureSensor::senseTemperature(){
    int sensorInput = analogRead(this->myPin); 
    double temp = (double)sensorInput / 1024; 
    temp = temp * 5; 
    temp = temp - 0.5; 
    temp = temp * 100; 
    
    #ifdef TEMP_DEBUG
    Serial.print("Current Temperature: ");
    Serial.println(temp);
    #endif

    return temp;   
}

bool TemperatureSensor::isOverHeat(){
    return this->senseTemperature() > DANGEROUS_TEMP;
}

