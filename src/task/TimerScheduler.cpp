// #include "TimerScheduler.h"
// #include "Timer.h"
// #include <Arduino.h>

// TimerScheduler::TimerScheduler(int amount, Task* myTasks[]){
//     int i;
//     for(i=0; i<amount;i++){
//         this->myTasks[i] = myTasks[i];
//     }
//     this->amountTask = amount;
// };

// void TimerScheduler::init(int period){
//     this->basePeriod = period;
//     // this->timer = new Timer<>();
//     // this->timer -> setupPeriod(period);
//     timer.every(period,callFunc);
// }

// bool callFunc(void *){
//     schedule();
//     return true;
// }

// void TimerScheduler::schedule(){
//     // unsigned long t1 = millis();

//     int i;
//     for(i=0; i<amountTask; i++) {
//         if (myTasks[i]->updateAndCheckTime(basePeriod)){
//             myTasks[i]->tick();
//         }
//     }
//     // this->timer->waitForNextTick();

//     // unsigned long t2 = millis() - t1;
//     // Serial.print(" ");
//     // Serial.print(t2);
//     // Serial.print(" ");
// }

// // void TimerScheduler::completeTimer(){
// //     this->timer->waitForNextTick();
// // }