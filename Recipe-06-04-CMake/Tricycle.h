#ifndef TRICYCLE_H
#define TRICYCLE_H

#include "Vehicle.h"

class Tricycle : public Vehicle
{
public:
  Tricycle() = default;
  virtual ~Tricycle();

  // won't be called by base class pointer
  int GetNumberofWheels();
};

#endif // TRICYCLE_H
