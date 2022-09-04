#include "Tricycle.h"


Tricycle::~Tricycle()
{

}

// won't be called by base class pointer
int Tricycle::GetNumberofWheels()
{
  return 3;
}
