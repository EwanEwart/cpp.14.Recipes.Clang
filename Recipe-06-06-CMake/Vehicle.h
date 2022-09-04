#ifndef VEHICLE_H
#define VEHICLE_H

#include<cinttypes>

#undef MUST_BE_IMPLEMENTED
#define  MUST_BE_IMPLEMENTED

class Vehicle
{
public:
  Vehicle() = default;
  virtual ~Vehicle();
  virtual uint32_t GetNumberOfWheels() const = 0;
};
#endif // VEHICLE_H
