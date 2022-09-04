#ifndef CAR_H
#define CAR_H

#include"Vehicle.h"

class Car : public Vehicle
{
public:
  Car() = default;
  virtual ~Car();
  uint32_t GetNumberOfWheels() const;
};
#endif // CAR_H
