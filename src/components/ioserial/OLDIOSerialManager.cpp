// #include "IOSerialManager.h"

// static String lastRead;
// static bool somethingAppened = false;

// void serialEvent() {
//     String tmp = "";
//     /* reading the content */
//     while (Serial.available()) {
//         char ch = (char) Serial.read();
//         if (ch == '\n'){
//             lastRead = tmp;
//             somethingAppened = true;
//         } else {
//             tmp += ch;      
//         }
//     }
// }

// IOSerialManager::IOSerialManager(){
//     this->isInMsgReady = false;
//     this->lastInCommand.reserve(32);
//     this->lastInCommand = "";
//     //this->notifier = toNotify;
// }

// void IOSerialManager::boardSendMsg(String toSend){
//     Serial.println(toSend);
// }

// String IOSerialManager::boardReceiveMsg(){
//     if (somethingAppened){
//         this->isInMsgReady = true;
//     }
//     somethingAppened = false;

//     if (this->isInMsgReady){
//         //String msg = this->lastInCommand;
//         this->lastInCommand = lastRead;
//         this->isInMsgReady = false;
//         lastRead = "";
//         //content = "";
//         return this->lastInCommand;
//     } else {
//         return ""; 
//     }
// }

// bool IOSerialManager::boardIsMsgAvaiable(){
//     return this->isInMsgReady;
// }
