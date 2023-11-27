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
    this->lcd.begin(AMOUNT_COLS, 2);
    initProgBar();
    this->lcd.display();
    //Serial.print("ONE");
    this->goBackNormal();
    //Serial.print("TWO");
}

void MyLcdMonitor::myPrint(){
    int i,j;
    for (i = 0; i<AMOUNT_ROWS; i++){
        for(j=0; j<AMOUNT_COLS; j++){
            char c = this->actString[i*(AMOUNT_COLS)+j];
            if (c != '\0'){
                this->lcd.setCursor(j,i);
                this->lcd.print(c);
            } else {
                i=AMOUNT_ROWS;
                j=AMOUNT_COLS;
            }
        }
    }
}

void MyLcdMonitor::writeOnLcd(char* toWrite){
    this->actString = toWrite;
    this->lcd.setCursor(0,0);
    this->myPrint();
    //this->lcd.print(toWrite);
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

void MyLcdMonitor::printProgBar(int percentage) {
    this->lcd.setCursor(PROG_BAR_COLS, PROG_BAR_ROW);
    int amount = -(int) ((percentage *1.0)  * (((AMOUNT_BARS)*1.0) / ((MAX_VALUE)*1.0)));
    int i; 
    for (i = START_BAR_INDEX; i<=amount; i++){
        progressBar[i] = FULL_CHAR;
    }
    for (i = amount+1; i< (AMOUNT_BARS + START_BAR_INDEX); i++){
        progressBar[i] = EMPTY_CHAR;
    }
    this->lcd.print(progressBar);
    delay(50);
}
