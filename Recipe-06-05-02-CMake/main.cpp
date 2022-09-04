#include <iostream>
using namespace std;

#include"Vehicle.h"
#include"Car.h"
#include"Ferrari.h"

int main()
{
  Vehicle* pVehicle{};
  Vehicle aVehicle{};
  pVehicle = &aVehicle;
  cout << "A vehicle has " << pVehicle->GetNumberOfWheels() << " wheels." << endl;

  Car aCar{};
  pVehicle = &aCar;
  cout << "A car has " << pVehicle->GetNumberOfWheels() << " wheels." << endl;

  Ferrari aFerrari;
  pVehicle = &aFerrari;
  cout << "A Ferrari has " << pVehicle->GetNumberOfWheels() << " wheels." << endl;

  return 0;
}
