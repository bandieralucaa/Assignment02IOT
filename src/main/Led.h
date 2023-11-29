// Led.h
#ifndef __LED__
#define __LED__

#include "Config.h"

class Led {
public:
  Led();
  void toggle();
  void turnOn();
  void turnOff();
  bool getState() const;  // Dichiarazione del metodo per ottenere lo stato
  void updateLastMeasurementTime();  // Dichiarazione del metodo per aggiornare il tempo
private:
  bool state;
};

#endif
