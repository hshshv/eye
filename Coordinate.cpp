#include "Coordinate.h"

Coordinate::Coordinate(float XVal, float YVal, float ZVal)
{
  x = XVal;
  y = YVal;
  z = ZVal;
}

Coordinate::Coordinate()
{
  Coordinate(0.0, 0.0, 0.0);
}
