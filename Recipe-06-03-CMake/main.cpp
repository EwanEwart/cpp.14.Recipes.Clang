#include <iostream>
using namespace std;

#include"Vehicle.h"
#include"Car.h"
#include"Motorcycle.h"

int main()
{
  Vehicle myVehicle{};
  cout << "A vehicle has " << myVehicle.GetNumberOfWheels() << " wheels." << endl;

  Car myCar{};
  cout << "A car has " << myCar.GetNumberOfWheels() << " wheels." << endl;

  Motorcycle myMotorcycle;
  cout << "A motorcycle has " << myMotorcycle.GetNumberOfWheels() << " wheels." << endl;

  return 0;
}
