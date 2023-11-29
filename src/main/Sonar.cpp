#include "Sonar.h"
#include <Arduino.h>

Sonar::Sonar() {
  trigPin = SONAR_TRIG_PIN;
  echoPin = SONAR_ECHO_PIN;
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

double Sonar::getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Attendere un breve periodo prima di iniziare la lettura dell'ECHO
  delayMicroseconds(200);

  // Leggi l'ECHO
  long duration = pulseIn(echoPin, HIGH);

  // Calcola la distanza
  double distance = duration * 0.034 / 2;

  Serial.print("Distanza misurata: ");
  Serial.print(distance);
  Serial.println(" cm");

  return distance;
}
