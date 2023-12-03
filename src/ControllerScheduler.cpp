#include "ControllerScheduler.h"

StateName actState;
State** myStates;

Cooldown* scheduleCooldown;

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
    myTasks = new Task*[amountTask]{myPir, myGate, sonar, blinkLed, butt, sm};
    // int amountTask = 1;
    // myTasks = new Task*[amountTask]{sonar};
    actAmountTask = amountTask;

    State* s1 = new SleepState(myPir, l1, lcd, sm);
    State* s2 = new WelcomeState(myPir, globalCooldown, lcd, l1);
    State* s3 = new PreEnteringState(myGate, blinkLed, lcd, sm);
    State* s4 = new EnteringState(sonar, globalCooldown);
    State* s5 = new WaitEnteringState(sonar, globalCooldown);
    State* s6 = new AfterEnteringState(myGate,blinkLed);
    State* s7 = new WaitConfirmState(butt,lcd, sm);
    State* s8 = new WashingState(tS, washingCooldown, lcd, blinkLed, sm);
    State* s9 = new PreWashingDoneState(myGate,lcd,blinkLed,l2, sm);
    State* s10 = new WashingDoneState(blinkLed, sonar);
    State* s11 = new LeftingState(sonar, globalCooldown);
    State* s12 = new AfterWashingDoneState(myGate, l2, sm);
    State* s13 = new WarningState(tS,globalCooldown,washingCooldown,lcd,sm);
    State* s14 = new HotState(lcd, sm, sm);
    State* s15 = new EscapingCarState(sonar, myPir,myGate, lcd, blinkLed);

    myStates = new State*[15]{s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12, s13, s14, s15};
    
    actState = SLEEP_STATE;
    myStates[actState]->init();
}

#ifdef SCHEDULER_PERIOD_DEBUG
unsigned long t1 = 0;
#endif

bool interuptAppened() {

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
}

void ControllerScheduler::execute() {
    if (scheduleCooldown->isOver()){
        interuptAppened();
        scheduleCooldown->reset();
    }
}

