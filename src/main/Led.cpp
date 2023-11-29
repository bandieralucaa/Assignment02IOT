#include "Led.h"
#include <Arduino.h>

Led::Led() {
  pinMode(LED_PIN, OUTPUT);
  state = LOW;
}

void Led::toggle() {
  state = !state;
  digitalWrite(LED_PIN, state);
}

void Led::turnOn() {
  state = HIGH;
  digitalWrite(LED_PIN, state);
}

void Led::turnOff() {
  state = LOW;
  digitalWrite(LED_PIN, state);
}

// Se desideri aggiungere uno stato alla tua classe Led
bool Led::getState() const {
  return state;
}

// Se desideri aggiungere la gestione del tempo alla tua classe Led
void Led::updateLastMeasurementTime() {
  // Aggiungi la logica per la gestione del tempo qui
}
