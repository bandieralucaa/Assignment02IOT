#include "MyLcdMonitor.h"

#define AMOUNT_COLS 16
#define AMOUNT_ROWS 2

#define AMOUNT_BARS (AMOUNT_COLS - 2)
#define START_BAR_INDEX 1

#define FULL_CHAR '#'
#define EMPTY_CHAR ' '

char progressBar[AMOUNT_COLS] = {' '};

void initProgBar(){
    int i;
    for (i=0; i<AMOUNT_BARS;i++){
      char c = ' ';
      if (i == 0){
        c = '[';
      }
      if (i == (AMOUNT_BARS-1)){
        c = ']';
      }
      progressBar[i] = c;
    }
}

MyLcdMonitor::MyLcdMonitor(){
    this->goBackNormal();
}

void MyLcdMonitor::writeOnLcd(char* toWrite){
    this->actString = toWrite;
    ///////
}

void MyLcdMonitor::clear(){
    this->lcd.clear();
}

void MyLcdMonitor::turnOn(){
    this->lcd.display();
}
void MyLcdMonitor::turnOff(){
    this->lcd.noDisplay();
}

void MyLcdMonitor::raiseError(){
    this->lcd.setRGB(255,0,0); //ColorR, colorG, colorB
    this->writeOnLcd("TOO HOT");
}

void MyLcdMonitor::goBackNormal(){
    this->clear();
    this->lcd.setRGB(0,255,0);
}

void printProgBar(int percentage){
    int amount = percentage * AMOUNT_BARS / MAX_VALUE;
    int i; 
    for (i = START_BAR_INDEX; i<=amount; i++){
        progressBar[i] = FULL_CHAR;
    }
    for (i = amount+1; i< (AMOUNT_BARS + START_BAR_INDEX); i++){
        progressBar[i] = EMPTY_CHAR;
    }
}
