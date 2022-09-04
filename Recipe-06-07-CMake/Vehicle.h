#ifndef VEHICLE_H
#define VEHICLE_H

#include<cinttypes>

// interface
class Vehicle
{
public:
  Vehicle() = default;
  virtual ~Vehicle();
  virtual uint32_t GetNumberOfWheels() const = 0;
};

#endif // VEHICLE_H
