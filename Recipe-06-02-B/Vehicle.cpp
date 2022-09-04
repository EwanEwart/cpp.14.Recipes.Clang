#include "Vehicle.h"


Vehicle::Vehicle(uint32_t numberOfWheels)
  : m_NumberOfWheels{ numberOfWheels }
{
}

Vehicle::~Vehicle()
{

}

uint32_t Vehicle::GetNumberOfWheels() const
{
  return m_NumberOfWheels;
}
