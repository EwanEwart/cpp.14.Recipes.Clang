#ifndef VEHICLE_H
#define VEHICLE_H

#include<cinttypes>

class Vehicle
{
private:
  uint32_t _NumberOfWheels{}; // set to 0 by default
public:
  Vehicle(uint32_t numberOfWheels);
  virtual ~Vehicle();
  uint32_t GetNumberOfWheels() const;
};
#endif  // VEHICLE_H
