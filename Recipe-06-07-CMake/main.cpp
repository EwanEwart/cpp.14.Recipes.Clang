#include"Printable.h"

#include"Car.h"
#include"Motorcycle.h"

int main()
{
  Printable* pPrintable{};

  Car aCar{};
  pPrintable = &aCar;
  pPrintable->Print();

  Motorcycle aMotorcycle;
  pPrintable = &aMotorcycle;
  pPrintable->Print();


  return 0;
}
