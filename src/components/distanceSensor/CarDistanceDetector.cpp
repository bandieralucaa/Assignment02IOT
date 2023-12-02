#include "CarDistanceDetector.h"
#define TIMEOUT_SONAR (100) //(SONAR_PERIOD / 2)

CarDistanceDetector::CarDistanceDetector(int trigPin, int echoPin){
    this->trigPin = trigPin ;
    this->echoPin = echoPin;
    this->period = SONAR_PERIOD;
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);  
}

double CarDistanceDetector::getDistance(){
    return this->lastRead;
}

bool CarDistanceDetector::isAboveMax(){
    return this->getDistance() > MAX_DIST;
}

bool CarDistanceDetector::isUnderMin(){
    return this->getDistance() < MIN_DIST;
}

void CarDistanceDetector::init(){

}

void CarDistanceDetector::measure(){
    float temperature = 20; // SENSORE_TEMP?

    float vs = 331.45 + 0.62*temperature;

    /* Triggering stage: sending the impulse */

    digitalWrite(this->trigPin,LOW);
    delayMicroseconds(3);
    digitalWrite(this->trigPin,HIGH);
    delayMicroseconds(5);
    digitalWrite(this->trigPin,LOW);
    
    /* Receiving the echo */
    unsigned long m = pulseIn(this->echoPin, HIGH, TIMEOUT_SONAR);
    if (m == 0) {
        this->lastRead = 999.0;
        return;
    }
    float tUS = m;
    float t = tUS / 1000.0 / 1000.0 / 2;
    float d = t*vs;

    #ifdef SONAR_DEBUG
    Serial.println("@\n@" + (String) tUS);
    Serial.print(" ########################## ");
    Serial.println(d);
    #endif
    
    this->lastRead = d;
}

void CarDistanceDetector::tick(){
    this->lastRead = this->getDistance();
}
