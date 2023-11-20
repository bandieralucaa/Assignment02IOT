#include "configs.h"

#include "Controller.h"

Controller::Controller() {
    OutputManager* out = new OutputManager();

    CarPresenceDetector* myPir = new CarPresenceDetector(PIR_PIN);

    Gate* myGate = new Gate(SERVO_MOTOR_PIN, false);

    Cooldown* cool = new Cooldown(N1);
    //Led l1 = new Led(LED1_PIN);

    State* s1 = new SleepState(out, ((Pir*) myPir));
    State* s2 = new WelcomeState(out, ((Pir*) myPir), cool);
    State* s3 = new PreEnteringState(myGate);
    State* s4 = new EnteringState();
    
    // State* s4 = new EnteringState();

    myStates = new State*[4]{s1, s2, s3, s4};
    //State* myStates[] = {s1, s2};
    // myStates[0] = s1;
    // myStates[1] = s2;
    // myStates = (State*){s1, s2};
    
    // Task* a[] = {((Task*) myPir), ((Task*) myGate)};
    Task* a[] = {((Task*) myPir), ((Task*) cool), ((Task*) myGate)};
    s = new Scheduler(3, a);

    actState = SLEEP_STATE;
    myStates[actState]->init();
    
}

void Controller::execute() {
    s->schedule();
    
    StateName newState = myStates[actState]->changeState();
    if (newState != NONE) {
        actState = newState;
        myStates[actState]->init();
    }
}