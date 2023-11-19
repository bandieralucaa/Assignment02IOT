#include "./state/State.h"
#include "./components/servomotor/Servomotor.h"

class EnteringState : public State {
public:
    EnteringState(Servomotor* myMotor);
    void init();
    StateName changeState(); 
private:
    Servomotor* myMotor;
};