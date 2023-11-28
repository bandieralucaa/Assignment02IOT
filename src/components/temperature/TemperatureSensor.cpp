#include "TemperatureSensor.h"
#include "configs.h"

TemperatureSensor::TemperatureSensor(int pin){
    this->myPin = pin;
}

double TemperatureSensor::senseTemperature(){
    int sensorInput = analogRead(TEMPERATURE_SENSOR_PIN); //read the analog sensor and store it
    double temp = (double)sensorInput / 1024; //find percentage of input reading
    temp = temp * 5; //multiply by 5V to get voltage
    temp = temp - 0.5; //Subtract the offset
    temp = temp * 100; //Convert to degrees
    
    #ifdef TEMP_DEBUG
    Serial.print("Current Temperature: ");
    Serial.println(temp);
    #endif

    return temp;

    
}

bool TemperatureSensor::isOverHeat(){
    //return false;
    return this->senseTemperature() > DANGEROUS_TEMP;
}

