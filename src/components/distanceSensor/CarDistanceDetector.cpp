#include "CarDistanceDetector.h"

CarDistanceDetector::CarDistanceDetector(int trigPin, int echoPin){
    this->trigPin = trigPin;
    this->echoPin = echoPin;
}

double CarDistanceDetector::getDistance(){
    float temperature = 20; // SENSORE_TEMP?
    
    float vs = 331.45 + 0.62*temperature;


    /* Triggering stage: sending the impulse */

    digitalWrite(this->trigPin,LOW);
    delayMicroseconds(3);
    digitalWrite(this->trigPin,HIGH);
    delayMicroseconds(5);
    digitalWrite(this->trigPin,LOW);
    
    /* Receiving the echo */

    float tUS = pulseIn(this->echoPin, HIGH);
    float t = tUS / 1000.0 / 1000.0 / 2;
    float d = t*vs;
    return d;
}

bool CarDistanceDetector::isAboveMax(){
    return this->getDistance() > MAX_DIST;
}

bool CarDistanceDetector::isUnderMin(){
    return this->getDistance() > MAX_DIST;
}

void CarDistanceDetector::init(){

}

void CarDistanceDetector::tick(){
    this->lastRead = this->getDistance();
}
