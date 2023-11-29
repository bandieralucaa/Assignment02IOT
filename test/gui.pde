import controlP5.*;
import processing.serial.*;

ControlP5 cp5;
Textlabel titleLabel;
Textlabel distanceLabel;
Serial myPort;  // Oggetto Serial per la comunicazione seriale
int lastUpdateTime = 0;  // Memorizza l'ultimo tempo in cui è stata aggiornata la distanza
int updateInterval = 5000;  // Intervallo di aggiornamento in millisecondi (5 secondi)
boolean measuring = false;  // Flag per indicare se la misurazione è in corso

void setup() {
  //int a = displayWidth/4*3;
  //int b = displayHeight/4*3;
  size(400, 300);
  cp5 = new ControlP5(this);

  titleLabel = cp5.addTextlabel("titleLabel")
                 .setText("Carwashing")
                 .setPosition(10, 10)
                 .setColorValue(color(255))
                 .setFont(createFont("Arial", 24));

  distanceLabel = cp5.addTextlabel("distanceLabel")
                    .setPosition(10, 50)
                    .setColorValue(color(0))
                    .setFont(createFont("Arial", 16));

  // Inizializza la comunicazione seriale
  String[] portList = Serial.list();
  if (portList.length > 0) {
    String portName = portList[0];
    myPort = new Serial(this, portName, 9600);
  } else {
    println("Nessuna porta seriale disponibile.");
  }

  // Aggiungi il pulsante Start
  cp5.addButton("startMeasurement")
     .setPosition(10, 200)
     .setSize(80, 30)
     .setLabel("Start")
     .setFont(createFont("Arial", 16));

  // Aggiungi il pulsante Stop
  cp5.addButton("stopMeasurement")
     .setPosition(100, 200)
     .setSize(80, 30)
     .setLabel("Stop")
     .setFont(createFont("Arial", 16));
}

void draw() {
  background(200);
  //size(displayWidth, displayHeight);

  // Aggiorna la distanza ogni 5 secondi quando la misurazione è attiva
  if (measuring && millis() - lastUpdateTime >= updateInterval) {
    myPort.write("M\n");  // Invia un comando ad Arduino per misurare la distanza
    lastUpdateTime = millis();
  }

  // Leggi i dati sulla porta seriale
  while (myPort.available() > 0) {
    String distanceString = myPort.readStringUntil('\n');
    if (distanceString != null) {
      distanceString = distanceString.trim();  // Rimuovi eventuali spazi vuoti
      distanceLabel.setText("Distanza: " + distanceString + " cm");
    }
  }
}

void controlEvent(ControlEvent event) {
  if (event.isController()) {
    if (event.getName().equals("startMeasurement")) {
      println("Start button pressed!");
      measuring = true;
      myPort.write("S\n");  // Invia il comando "S" ad Arduino per segnalare l'inizio della misurazione e accendere il LED
    } else if (event.getName().equals("stopMeasurement")) {
      println("Stop button pressed!");
      measuring = false;
      myPort.write("Q\n");  // Invia il comando "Q" ad Arduino per segnalare la fine della misurazione e spegnere il LED
    }
  }
}
