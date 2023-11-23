// #include "Timer.h"
// #include "Arduino.h"
// // #include "TimerThree.h"

// volatile bool timerFlag;
// volatile unsigned long l1 = 0;

// ISR(TIMER1_COMPB_vect){
//   unsigned long l2 = millis();
//   unsigned long delta = l2 - l1;
//   Serial.print(" " + (String)delta + "\n ");
//   timerFlag = true;
//   l1 = l2;
// }

// Timer::Timer(){
//   timerFlag = false;  
// }

// /* period in ms */
// void Timer::setupPeriod(int period){
  
//   // disabling interrupt
//   cli();

//   // TCCR1A = 0; // set entire TCCR1A register to 0
//   TCCR1B = 0; // same for TCCR1B
//   TCNT1  = 0; //initialize counter value to 0
  
//   /* 
//    * set compare match register
//    * 
//    * OCR1A = (16*2^20) / (100*PRESCALER) - 1 (must be < 65536)
//    *
//    * assuming a prescaler = 1024 => OCR1A = (16*2^10)* period/1000 (being in ms) 
//    */
//   OCR1B = 16.384*period; //16.384
//   // turn on CTC mode
//   TCCR1B |= (1 << WGM12);
//   // Set CS11 for 8 prescaler
//   TCCR1B |= (1 << CS12) | (1 << CS10);
//   // enable timer compare interrupt
//   TIMSK1 |= (1 << OCIE1B);


//   // OCR1A = 16.384*period; //16.384
//   // // turn on CTC mode
//   // TCCR1A |= (1 << WGM12);
//   // // Set CS11 for 8 prescaler
//   // TCCR1A |= (1 << CS12) | (1 << CS10);
//   // // enable timer compare interrupt
//   // TIMSK1 |= (1 << OCIE1A);

//   // enabling interrupt
//   sei();


//   // // disabling interrupt
//   // cli();

//   // //set timer2 interrupt at 8kHz
//   // TCCR2A = 0;// set entire TCCR2A register to 0
//   // TCCR2B = 0;// same for TCCR2B
//   // TCNT2  = 0;//initialize counter value to 0

//   // // set compare match register for 8khz increments
//   // OCR2A = 16.384*period;// = (16*10^6) / (8000*8) - 1 (must be <256)
//   // // turn on CTC mode
//   // TCCR2A |= (1 << WGM21);
//   // // Set CS21 bit for 8 prescaler
//   // TCCR2B |= (1 << CS21);   
//   // // enable timer compare interrupt
//   // TIMSK2 |= (1 << OCIE2A);
  
//   // // Enable global interrupts  
//   // sei(); 
// }

// void Timer::waitForNextTick(){
//   /* wait for timer signal */
//   while (!timerFlag){}
//   timerFlag = false;
  
// }