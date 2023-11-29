import controlP5.*;
import processing.serial.*;

ControlP5 cp5;
Textfield amountInput;
Textfield temperatureInput;
Textfield stateInput;
Button solveButton;

Serial myPort;

void settings() {
  size(int(displayWidth * 0.75 ), int(displayHeight * 0.75 * 0.75) );
  myPort = new Serial(this, Serial.list()[0], 9600);
}

void setup() {
  textAlign(CENTER, CENTER);
  cp5 = new ControlP5(this);

  cp5.addTextlabel("title")
     .setText("Car Washing Machine")
     .setPosition(width / 2 - 100, height * 0.1)
     .setColorValue(color(0)) 
     .setFont(createFont("Arial", 20)); 

  cp5.addTextlabel("amountLabel")
     .setText("Amount car washed")
     .setPosition(width / 2 - 200, height * 0.2)
     .setColorValue(color(0))
     .setFont(createFont("Arial", 16));
     
  amountInput = cp5.addTextfield("amountInput")
                   .setPosition(width / 2, height * 0.2)
                   .setSize(int(width * 0.2), int(height * 0.04))
                   .setFont(createFont("Arial", 16));

  cp5.addTextlabel("temperatureLabel")
     .setText("Temperature value")
     .setPosition(width / 2 - 200, height * 0.3)
     .setColorValue(color(0))
     .setFont(createFont("Arial", 16));
     
  temperatureInput = cp5.addTextfield("temperatureInput")
                        .setPosition(width / 2, height * 0.3)
                        .setSize(int(width * 0.2), int(height * 0.04))
                        .setFont(createFont("Arial", 16));

  cp5.addTextlabel("stateLabel")
     .setText("Actual state of car washing")
     .setPosition(width / 2 - 200, height * 0.4)
     .setColorValue(color(0))
     .setFont(createFont("Arial", 16));
     
  stateInput = cp5.addTextfield("stateInput")
                  .setPosition(width / 2, height * 0.4)
                  .setSize(int(width * 0.2), int(height * 0.04))
                  .setFont(createFont("Arial", 16));

  solveButton = cp5.addButton("Problem solved")
                    .setPosition(width / 2 - 60, height * 0.5)
                    .setSize(int(width * 0.25), int(height * 0.08));
  
  printArray(Serial.list());
}

void draw() {
  background(255);
}

void controlEvent(ControlEvent event) {
  if (event.isAssignableFrom(Textfield.class)) {
    String inputName = event.getName();
    String inputValue = event.getStringValue();
    println(inputName + ": " + inputValue);
  } else if (event.isAssignableFrom(Button.class)) {
    if (event.getName().equals("Problem solved")) {
      myPort.write("o-\n");
      //println("o-");
      
    }
  }
}
