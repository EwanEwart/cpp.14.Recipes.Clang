#include <iostream>
using namespace std;

#include"Car.h"
#include"Motorcycle.h"

int main()
{
  Car aCar{};
  cout << "A car has " << aCar.GetNumberOfWheels() << " wheels." << endl;

  Motorcycle aMotorcycle;
  cout << "A motorcycle has " << aMotorcycle.GetNumberOfWheels() << " wheels." << endl;

  return 0;
}
