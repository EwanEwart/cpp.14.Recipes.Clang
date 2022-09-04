#ifndef CAR_H
#define CAR_H

#include"Vehicle.h"

class Car : public Vehicle
{
public:
  Car() = default;
  virtual ~Car();

#define IGNORE
#undef IGNORE
#ifdef IGNORE
  uint32_t GetNumberOfWheels() const override;
#endif

};

#endif // CAR_H
