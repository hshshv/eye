#include "Arduino.h"

#ifndef Coo_
#define Coo_

class Coordinate
{
  public:
    Coordinate();
    Coordinate(float XVal, float YVal, float ZVal);
    float x = 0.0;
    float y = 0.0;
    float z = 0.0;
};

#endif
