#include "./state/State.h"
#include "./components/button/Button.h"

class WaitConfirmState : public State {
public:
    WaitConfirmState(Button* b);
    void init();
    StateName changeState();
    
private:
    Button* button;
};