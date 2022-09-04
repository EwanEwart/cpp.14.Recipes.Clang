#ifndef CAR_H
#define CAR_H

#include"Vehicle.h"

class Car : public Vehicle
{
public:
  Car() = default;
  virtual ~Car() override;
#ifdef MUST_BE_IMPLEMENTED
  uint32_t GetNumberOfWheels() const override;
#endif
};
#endif // CAR_H
