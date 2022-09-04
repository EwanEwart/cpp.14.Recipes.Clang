#include <iostream>
using namespace std;

#include"Car.h"
#include"Motorcycle.h"

int main()
{
  Car aCar{};
  cout << "A car has " << aCar.m_NumberOfWheels << " wheels." << endl;
  aCar.m_NumberOfWheels = 3;
  cout << "A car has " << aCar.m_NumberOfWheels << " wheels." << endl;

  Motorcycle myMotorcycle{};
  cout << "A motorcycle has " << myMotorcycle.m_NumberOfWheels << " wheels." << endl;
  myMotorcycle.m_NumberOfWheels = 3;
  cout << "A motorcycle has " << myMotorcycle.m_NumberOfWheels << " wheels." << endl;

  return 0;
}
