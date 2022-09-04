#include <cinttypes>
#include <iostream>

#include"Vehicle.h"
#include"Car.h"
#include"Motorcycle.h"

using namespace std;

void ref_print_Vehicle(Vehicle const& refVehicle) {
  cout << "2.1.4 A vehicle has " << refVehicle.GetNumberOfWheels() << " wheels." << endl;
}
void ref_print_Car(Car const& refCar) {
  cout << "2.2.4 A car has " << refCar.GetNumberOfWheels() << " wheels." << endl;
}
void ref_print_Motorcycle(Motorcycle const& refMotorcycle){
  cout << "2.3.4 A motorcycle has " << refMotorcycle.GetNumberOfWheels() << " wheels." << endl;
}

int main()
{
  // --------------------------
  cout << "--- 1. Pointer ---" << endl;
  Vehicle* ptrVehicle{};

  Vehicle aVehicle{};

  ptrVehicle = &aVehicle;

  cout << "1.1 A vehicle has " << ptrVehicle->GetNumberOfWheels() << " wheels." << endl;

  Car aCar{};
  ptrVehicle = &aCar;
  auto now = ptrVehicle->GetNumberOfWheels();
  cout << "1.2 A car has " << now << " wheels." << endl;

  Motorcycle aMotorcycle;
  ptrVehicle = &aMotorcycle;
  cout << "1.3 A motorcycle has " << ptrVehicle->GetNumberOfWheels() << " wheels." << endl;


  // --------------------------
  cout << "--- 2. Refernce ---" << endl;
  Vehicle& refVehicle = aVehicle;
  cout << "2.1.1 A vehicle has " << refVehicle.GetNumberOfWheels() << " wheels." << endl;
  ref_print_Vehicle(refVehicle);

  /* Once a reference is initialised to an object,
   * it cannot be changed
   * to refer to another object.
   * Pointers can be pointed to another object at any time.
   */
  refVehicle = aCar; // fault
  cout << "2.2.2 A car has " << refVehicle.GetNumberOfWheels() << " wheels." << endl;
  Vehicle& refNewCar = aCar;
  cout << "2.2.3 A car has " << refNewCar.GetNumberOfWheels() << " wheels." << endl;
  ref_print_Car(aCar);

  /* Once a reference is initialised to an object,
   * it cannot be changed
   * to refer to another object.
   * Pointers can be pointed to another object at any time.
   */
  refVehicle = aMotorcycle; // fault
  cout << "2.3.1 A motorcycle has " << refVehicle.GetNumberOfWheels() << " wheels." << endl;
  Vehicle& refNewMotorcycle = aMotorcycle;
  cout << "2.3.2 A motorcycle has " << refNewMotorcycle.GetNumberOfWheels() << " wheels." << endl;
  ref_print_Motorcycle(aMotorcycle);

  return 0;
}
