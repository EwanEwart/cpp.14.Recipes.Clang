#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include"Vehicle.h"
#include"Printable.h"

class Motorcycle
    : public Vehicle
    , public Printable
{
public:
  Motorcycle() = default;
  virtual ~Motorcycle() override;

  uint32_t GetNumberOfWheels() const override;
  void Print() override;
};

#endif // MOTORCYCLE_H
