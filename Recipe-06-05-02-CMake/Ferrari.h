#ifndef FERRARI_H
#define FERRARI_H

#include"Car.h"

class Ferrari : public Car
{
public:
  Ferrari() = default;
  virtual ~Ferrari();

#define IGNORE
#ifndef IGNORE
  uint32_t GetNumberOfWheels() const override;
#endif
};

#endif // FERRARI_H
