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
    OutputManager* out = new OutputManager();

    CarPresenceDetector* myPir = new CarPresenceDetector(PIR_PIN);

    Gate* myGate = new Gate(SERVO_MOTOR_PIN, false);
    myGate->init();

    CarDistanceDetector* sonar = new CarDistanceDetector(SONAR_TRIG,SONAR_ECHO);

    LedExtTimered* blinkLed = new LedExtTimered(BLINKING_LED, 5);

    WashingMachineButton* butt = new WashingMachineButton(BUTT_PIN);

    TemperatureSensor* tS = new TemperatureSensor(TEMPERATURE_SENSOR_PIN);

    Cooldown* washingCooldown = new Cooldown(N3_TIME);

    Cooldown* globalCooldown = new Cooldown(N1_TIME);

    int amountTask = 5;
    myTasks = new Task*[amountTask]{(myPir), myGate, sonar, blinkLed, butt};
    // int amountTask = 1;
    // myTasks = new Task*[amountTask]{sonar};
    actAmountTask = amountTask;

    State* s1 = new SleepState(out, (myPir));
    //State* s2 = new WelcomeState(out, (myPir), &timer);
    State* s2 = new WelcomeState(out, myPir, globalCooldown);
    State* s3 = new PreEnteringState(myGate);
    State* s4 = new EnteringState(blinkLed,sonar);
    State* s5 = new WaitEnteringState(blinkLed, sonar, globalCooldown);
    State* s6 = new AfterEnteringState(myGate);
    State* s7 = new WaitConfirmState(butt);
    State* s8 = new WashingState(tS, washingCooldown);
    State* s9 = new PreWashingDoneState(myGate);
    State* s10 = new WashingDoneState(blinkLed, sonar);
    State* s11 = new LeftingState(sonar, globalCooldown);
    State* s12 = new AfterWashingDoneState(myGate);
    State* s13 = new WarningState(tS, globalCooldown);
    State* s14 = new HotState(butt);

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

