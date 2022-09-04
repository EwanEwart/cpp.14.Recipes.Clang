#include <iostream>
#include <memory>
/*
Recipe 2-9. Using Managed Pointers

=======
Wish
=======
You would like to automate the task of managing memory in your C++ programs.
========
Solution
========
Modern C++ provides the capability to automatically manage dynamically allocated memory.
============
How It Works
============
Using unique_ptr
C++ provides three smart pointer types
that can be used to automatically manage the lifetime
of dynamically allocated objects.
============
Listing 2-32
============
shows the use of a unique_ptr.
*/
/*
  std::make_unique<...>(...) since c++14
  std::make_unique<...>(...) doesn't exist for c++11
  remedy : boost or header file below
*/
// #include "../../memory-c++11.h"

using std::cerr;
using std::cout;
using std::endl;
using std::make_unique;
using std::ostream;
using std::string;

class AnyClass
{

private:
  string m_key{"std::make_unique"};
  int m_value{10};

public:
  AnyClass() // default ctor
  {
    cout << "Constructing Class !" << '\n';
  }

  virtual ~AnyClass()
  {
    cout << "Destructing Class !" << '\n';
  }

  string GetKey() const
  {
    return m_key;
  }
  int GetValue() const
  {
    return m_value;
  }
};

ostream &operator<<(ostream &os, AnyClass const &obj)
{
  os
      << "( m_key, m_value ) == ( "
      << obj.GetKey()
      << ", "
      << obj.GetValue()
      << " )";
  return os;
}

int main()
{
  auto uniquePointer{make_unique<AnyClass>()};
  if (!uniquePointer)
  {
    cerr << "make_unique<Class> failed." << endl;
    return -1;
  }
  else
  {
    cout << "make_unique<Class> succeeded." << endl;
    cout << *uniquePointer << endl;
    return 0;
  }
}
/*
The code in Listing 3-32 manages to
- create and
- destroy
a dynamically allocated object
without ever using "new" or "delete".

The "make_unique" template handles calling new
and the "unique_ptr" object handles calling delete
when the unique_ptr instance goes out of scope.

*/
