#ifndef CAR_H
#define CAR_H

#include"Printable.h"
#include"Vehicle.h"


class Car
    : public Vehicle
    , public Printable
{
public:
  Car() = default;
  virtual ~Car() override;
  uint32_t GetNumberOfWheels() const override;
  void Print() override;
};

#endif // CAR_H
