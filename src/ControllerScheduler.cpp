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

    int amountTask = 1;
    myTasks = new Task*[amountTask]{(myPir),myGate};
    actAmountTask = amountTask;

    actState = SLEEP_STATE;
    myStates[actState]->init();


    State* s1 = new SleepState(out, (myPir));
    State* s2 = new WelcomeState(out, (myPir), timer);
    State* s3 = new PreEnteringState(myGate);

    myStates = new State*[3]{s1, s2, s3};
    
}


unsigned long t1 = 0;

bool interuptAppened(void*) {
    unsigned long t2 = millis();
    unsigned long t3 = t2 - t1;
    Serial.print(" ");
    Serial.print(t3);
    Serial.print("\n");

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
    timer.every(basePeriod, interuptAppened);
}

void ControllerScheduler::execute() {
    timer.tick();   
}

