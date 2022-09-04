#ifndef CAR_H
#define CAR_H

#include"Vehicle.h"

class Car : public Vehicle
{
public:
  Car() = default;
  virtual ~Car() override;
  virtual uint32_t GetNumberOfWheels() const override;
};

#endif // CAR_H
