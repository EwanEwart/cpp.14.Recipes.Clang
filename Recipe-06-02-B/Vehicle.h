#ifndef VEHICLE_H
#define VEHICLE_H

#include<cinttypes>

class Vehicle
{
private:
  uint32_t m_NumberOfWheels{};
public:
  Vehicle(uint32_t numberOfWheels);
  virtual ~Vehicle();
  uint32_t GetNumberOfWheels() const;
};
#endif // VEHICLE_H
