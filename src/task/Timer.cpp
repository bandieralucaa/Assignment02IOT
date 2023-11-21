#include "Timer.h"
#include "Arduino.h"
// #include "TimerThree.h"

volatile bool timerFlag;

ISR(TIMER3_COMPA_vect){
  timerFlag = true;
}

Timer::Timer(){
  timerFlag = false;  
}

/* period in ms */
void Timer::setupPeriod(int period){
  
  // // disabling interrupt
  // cli();

  // TCCR1A = 0; // set entire TCCR1A register to 0
  // TCCR1B = 0; // same for TCCR1B
  // TCNT1  = 0; //initialize counter value to 0
  
  // /* 
  //  * set compare match register
  //  * 
  //  * OCR1A = (16*2^20) / (100*PRESCALER) - 1 (must be < 65536)
  //  *
  //  * assuming a prescaler = 1024 => OCR1A = (16*2^10)* period/1000 (being in ms) 
  //  */
  // OCR1A = 16.384*period; 
  // // turn on CTC mode
  // TCCR1B |= (1 << WGM12);
  // // Set CS11 for 8 prescaler
  // TCCR1B |= (1 << CS12) | (1 << CS10);  
  // // enable timer compare interrupt
  // TIMSK1 |= (1 << OCIE1A);

  // // enabling interrupt
  // sei();








 // Disable global interrupts
  cli();

  disableTimer3();
 
  // Set compare match register to desired timer count - 25ms 40Hz (16000000/1024/40 = 390.63)
  OCR3A = 391;

  // Turn on CTC mode WGM32 set CS10 and CS12 bits for Timer3 prescaler of 1024
  TCCR3B = bit (WGM32) | bit (WGM32) | bit (CS30);

  // Enable timer compare interrupt
  TIMSK3 |= (1 << OCIE3A);
  
  // Enable global interrupts  
  sei(); 
}

void Timer::waitForNextTick(){
  /* wait for timer signal */
  while (!timerFlag){}
  timerFlag = false;
  
}