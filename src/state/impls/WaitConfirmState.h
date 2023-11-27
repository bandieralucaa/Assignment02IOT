#include "./state/State.h"
#include "./components/button/Button.h"
#include "./components/lcd/LcdMonitor.h"


class WaitConfirmState : public State {
public:
    WaitConfirmState(Button* b, LcdMonitor* lcd);
    void init();
    StateName changeState();
    
private:
    Button* button;
    LcdMonitor* lcd;
};