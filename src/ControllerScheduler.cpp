#include "configs.h"

#include "ControllerScheduler.h"

StateName actState;
State** myStates;
Timer<3> timer;

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

    int amountTask = 5;
    myTasks = new Task*[amountTask]{(myPir), myGate, sonar, blinkLed, butt};
    // int amountTask = 1;
    // myTasks = new Task*[amountTask]{sonar};
    actAmountTask = amountTask;

    State* s1 = new SleepState(out, (myPir));
    State* s2 = new WelcomeState(out, (myPir), &timer);
    State* s3 = new PreEnteringState(myGate);
    State* s4 = new EnteringState(blinkLed,sonar);
    State* s5 = new WaitEnteringState(blinkLed, sonar, &timer);
    State* s6 = new AfterEnteringState(myGate);
    State* s7 = new WaitConfirmState(butt);
    State* s8 = new WashingState(&timer);
    State* s9 = new PreWashingDoneState(myGate);
    State* s10 = new WashingDoneState(blinkLed, sonar);
    State* s11 = new LeftingState(sonar, &timer);
    State* s12 = new AfterWashingDoneState(myGate);

    myStates = new State*[12]{s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12};
    
    actState = AFTER_ENTERING_STATE;
    myStates[actState]->init();
}


unsigned long t1 = 0;

bool interuptAppened(void*) {
    unsigned long t2 = millis();
    unsigned long t3 = t2 - t1;
    Serial.print(" ");
    Serial.print(t3);
    Serial.print(" <-------------\n");

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
    
    t1 = t2;
    return true;
}

void ControllerScheduler::init(unsigned long basePeriod) {
    bPeriod = basePeriod;
    Serial.print(timer.size());
    timer.every(basePeriod, interuptAppened);
    Serial.print(timer.size());
    Serial.print("****** init controller scheduler");
}

void ControllerScheduler::execute() {
    timer.tick();   
}

