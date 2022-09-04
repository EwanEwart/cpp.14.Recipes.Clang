#include "Car.h"

Car::~Car()
{

}

uint32_t Car::GetNumberOfWheels() const
{
  return 4;
}

void Car::Print()
{
  cout << "A car has " << GetNumberOfWheels() << " wheels." << endl;
}
