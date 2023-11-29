#include "Led.h"
#include "Sonar.h"
#include "Button.h"
#include "Config.h"
#include <Arduino.h>

bool ledState = LOW;
unsigned long lastMeasurementTime = 0;
const unsigned long measurementInterval = 5000;  // Intervallo di misurazione in millisecondi (5 secondi)

Led led;
Sonar sonar;
Button button(BUTTON_PIN);

void setup() {
  Serial.begin(9600);
  Serial.println("Programma avviato!");
}

void loop() {
  button.update();  // Aggiorna lo stato del pulsante

  if (button.isPressed() && !ledState) {
    // Il pulsante è stato premuto e il LED è spento
    Serial.write('P');
    led.turnOn();
    ledState = HIGH;
    lastMeasurementTime = millis();  // Inizia il timer
    delay(200);  // Aggiungi un ritardo
  } else if (button.isPressed() && ledState) {
    // Il pulsante è stato premuto e il LED è acceso
    Serial.write('P');
    led.turnOff();
    ledState = LOW;
    delay(200);  // Aggiungi un ritardo
  }

  // Misura la distanza solo se il LED è acceso e il timer è scaduto
  if (ledState == HIGH && (millis() - lastMeasurementTime) >= measurementInterval) {
    double distance = sonar.getDistance();
    Serial.println(distance);
    lastMeasurementTime = millis();  // Riavvia il timer
  }

  // Controlla i comandi seriali
  while (Serial.available() > 0) {
    char command = Serial.read();
    if (command == 'S') {
      // Inizia la misurazione
      Serial.write('P');  // Invia un feedback alla GUI
      led.turnOn();
      ledState = HIGH;
      lastMeasurementTime = millis();  // Inizia il timer
      delay(200);  // Aggiungi un ritardo
    } else if (command == 'Q') {
      // Termina la misurazione
      Serial.write('P');  // Invia un feedback alla GUI
      led.turnOff();
      ledState = LOW;
      delay(200);  // Aggiungi un ritardo
    }
  }

  delay(10);  // Aggiungi una breve pausa per stabilizzare il loop
}
