#ifndef __SONAR__
#define __SONAR

#include "Config.h"

class Sonar {
public:
  Sonar();
  double getDistance();

private:
  int trigPin;
  int echoPin;
};

#endif