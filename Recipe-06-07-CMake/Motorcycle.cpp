#include "Motorcycle.h"

Motorcycle::~Motorcycle()
{

}

uint32_t Motorcycle::GetNumberOfWheels() const
{
  return 2;
}

void Motorcycle::Print()
{
  cout << "A motorcycle has " << GetNumberOfWheels() << " wheels." << endl;
}
