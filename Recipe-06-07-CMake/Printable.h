#ifndef PRINTABLE_H
#define PRINTABLE_H

#include<iostream>
using std::cout;
using std::endl;

// interface
class Printable
{
public:
  virtual void Print() = 0;
  virtual ~Printable();
};
#endif // PRINTABLE_H
