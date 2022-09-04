#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include"Vehicle.h"

class Motorcycle : public Vehicle
{
public:
  Motorcycle() = default;
  virtual ~Motorcycle() override;
#ifdef MUST_BE_IMPLEMENTED
  uint32_t GetNumberOfWheels() const override;
#endif
};

#endif // MOTORCYCLE_H
