#include "ControllerScheduler.h"


//#define OLD_TIMER
#define INTERESTING_TIMER

StateName actState;
State** myStates;
//Timer<3> timer;
#ifdef INTERESTING_TIMER
Cooldown* scheduleCooldown;
#endif

Task** myTasks;
int actAmountTask;

unsigned long bPeriod;


ControllerScheduler::ControllerScheduler() {


    CarPresenceDetector* myPir = new CarPresenceDetector(PIR_PIN);


    Gate* myGate = new Gate(SERVO_MOTOR_PIN, false);
    myGate->init();


    CarDistanceDetector* sonar = new CarDistanceDetector(SONAR_TRIG,SONAR_ECHO);


    LedExtTimered* blinkLed = new LedExtTimered(BLINKING_LED, 5);
    Led* l1 = new Led(LED1_PIN);
    Led* l2 = new Led(LED2_PIN);

    blinkLed->switchOff();
    l1->switchOff();
    l2->switchOff();

    WashingMachineButton* butt = new WashingMachineButton(BUTT_PIN);

    TemperatureSensor* tS = new TemperatureSensor(TEMPERATURE_SENSOR_PIN);

    SerialManager* sm = new SerialManager(tS);
    sm->init();
    
    Cooldown* washingCooldown = new Cooldown(N3_TIME);

    Cooldown* globalCooldown = new Cooldown(N1_TIME);    


    MyLcdMonitor* lcd = new MyLcdMonitor();
    lcd->turnOff();

    int amountTask = 6;
    myTasks = new Task*[amountTask]{(myPir), myGate, sonar, blinkLed, butt, sm};
    // int amountTask = 1;
    // myTasks = new Task*[amountTask]{sonar};
    actAmountTask = amountTask;



    State* s1 = new SleepState(myPir, l1, lcd, sm);
    //State* s2 = new WelcomeState(out, (myPir), &timer);
    State* s2 = new WelcomeState(myPir, globalCooldown, lcd, l1);
    State* s3 = new PreEnteringState(myGate,blinkLed,lcd, sm);
    State* s4 = new EnteringState(sonar);
    State* s5 = new WaitEnteringState(sonar, globalCooldown);
    State* s6 = new AfterEnteringState(myGate,blinkLed);
    State* s7 = new WaitConfirmState(butt,lcd, sm);
    State* s8 = new WashingState(tS, washingCooldown,lcd, blinkLed, sm);
    State* s9 = new PreWashingDoneState(myGate,lcd,blinkLed,l2, sm);
    State* s10 = new WashingDoneState(blinkLed, sonar);
    State* s11 = new LeftingState(sonar, globalCooldown);
    State* s12 = new AfterWashingDoneState(myGate, l2, sm);
    State* s13 = new WarningState(tS,globalCooldown,washingCooldown,lcd,sm);
    State* s14 = new HotState(butt,lcd, sm, sm);

    myStates = new State*[14]{s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12, s13, s14};
    
    actState = SLEEP_STATE;
    myStates[actState]->init();
}

#ifdef SCHEDULER_PERIOD_DEBUG
unsigned long t1 = 0;
#endif

bool interuptAppened(void*) {

    #ifdef SCHEDULER_PERIOD_DEBUG
    unsigned long t2 = millis();
    unsigned long t3 = t2 - t1;
    Serial.print(" ");
    Serial.print(t3);
    Serial.print(" <-------------\n");
    t1 = t2;
    #endif

    int i;
    for(i=0; i < actAmountTask; i++) {
        if (myTasks[i]->updateAndCheckTime(bPeriod)){
            myTasks[i]->tick();
        }
    }

    StateName newState = myStates[actState]->changeState();
    if (newState != NONE) {
        actState = newState;
        myStates[actState]->init();
    }
    
    
    return true;
}

bool interuptAppened2() {

    #ifdef SCHEDULER_PERIOD_DEBUG
    unsigned long t2 = millis();
    unsigned long t3 = t2 - t1;
    Serial.print(" ");
    Serial.print(t3);
    Serial.print(" <-------------\n");
    t1 = t2;
    #endif

    int i;
    for(i=0; i < actAmountTask; i++) {
        if (myTasks[i]->updateAndCheckTime(bPeriod)){
            myTasks[i]->tick();
        }
    }

    StateName newState = myStates[actState]->changeState();
    if (newState != NONE) {
        actState = newState;
        for(i=0; i < actAmountTask; i++) {
            myTasks[i]->stop();
        }
        myStates[actState]->init();
    }
    
    
    return true;
}

void ControllerScheduler::init(unsigned long basePeriod) {
    bPeriod = basePeriod;
    scheduleCooldown = new Cooldown(bPeriod);
    scheduleCooldown->init();

    #ifdef SCHEDULER_PERIOD_DEBUG
    #ifdef OLD_TIMER
    Serial.print(timer.size());  
    timer.every(basePeriod, interuptAppened);
    #endif
    #endif
    #ifdef SCHEDULER_PERIOD_DEBUG
    #ifdef OLD_TIMER
    Serial.print(timer.size());
    Serial.print("****** init controller scheduler");
    #endif
    #endif
}

void ControllerScheduler::execute() {
    #ifdef OLD_TIMER
    timer.tick();
    #endif

    if (scheduleCooldown->isOver()){
        interuptAppened2();
        scheduleCooldown->reset();
    }
    
}

