#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include"Vehicle.h"

class Motorcycle : public Vehicle
{
public:
  Motorcycle() = default;
  virtual ~Motorcycle();
  uint32_t GetNumberOfWheels() const;
};
#endif // MOTORCYCLE_H
