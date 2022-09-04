#include <QCoreApplication>

#include <iostream>
using namespace std;

#include"Vehicle.h"
#include"Car.h"
#include"Motorcycle.h"

int main(int argc, char *argv[])
{
  QCoreApplication app(argc, argv);

  Vehicle aVehicle{};
  cout << "A vehicle has " << aVehicle.GetNumberOfWheels() << " wheels." << endl;

  Car aCar{};
  cout << "A car has " << aCar.GetNumberOfWheels() << " wheels." << endl;

  Motorcycle aMotorcycle;
  cout << "A motorcycle has " << aMotorcycle.GetNumberOfWheels() << " wheels." << endl;

  auto rc = app.exec();

  return rc;
}
