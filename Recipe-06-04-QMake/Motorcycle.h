#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include<Vehicle.h>
class Motorcycle : public Vehicle
{
public:
  Motorcycle() = default;
  virtual ~Motorcycle() override;
};

#endif // MOTORCYCLE_H
