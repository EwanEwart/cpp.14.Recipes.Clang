#include <iostream>

using namespace std;

#include"Vehicle.h"
#include"Car.h"
#include"Motorcycle.h"

#define IGNORE

int main()
{
#ifndef IGNORE
  Vehicle vehicle{};
#endif
  Vehicle* pVehicle{};
  Car aCar{};
  pVehicle = &aCar;
  cout << "A car has " << pVehicle->GetNumberOfWheels() << " wheels." << endl;

  Motorcycle aMotorcycle;
  pVehicle = &aMotorcycle;
  cout << "A motorcycle has " << pVehicle->GetNumberOfWheels() << " wheels." << endl;

  return 0;
}
