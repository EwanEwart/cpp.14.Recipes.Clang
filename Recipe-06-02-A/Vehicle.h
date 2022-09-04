#ifndef VEHICLE_H
#define VEHICLE_H

#include<cinttypes>

class Vehicle
{
public:
  Vehicle() = default;
  virtual ~Vehicle();
  uint32_t m_NumberOfWheels{};
};

#endif // VEHICLE_H
