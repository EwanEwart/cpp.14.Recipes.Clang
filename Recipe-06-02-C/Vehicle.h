#ifndef VEHICLE_H
#define VEHICLE_H

#include<cinttypes>

class Vehicle
{
protected:
  uint32_t _NumberOfWheels{};
public:
  Vehicle() = default;
  virtual ~Vehicle();
  uint32_t GetNumberOfWheels() const;
};
#endif // VEHICLE_H
