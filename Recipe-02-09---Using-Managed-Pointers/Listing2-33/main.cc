#include <iostream>
/*
Unfortunately the "make_unique" template is a C++14 feature
and does not exist in C++11.

The code in Listing 2-33 shows how you can rectify this.

*/
/*
  std::make_unique<...>(...) since c++14
  std::make_unique<...>(...) doesn't exist for c++11
  remedy : boost or header file below
*/

#if 200400L < __cplusplus && __cplusplus < 201200L
#include "../../memory-c++11.h"
#else
#include <memory>
using std::make_unique;
using std::unique_ptr;
#endif

using std::cerr;
using std::cout;
using std::endl;
using std::ostream;
using std::string;

class AnyClass
{
private:
  string m_Key;
  int m_Value;

public:
  AnyClass(string const &key, int value) // no explicit default ctor
      : m_Key{key}, m_Value{value}
  {
    cout << "Constructing AnyClass !" << '\n';
  }

  virtual ~AnyClass()
  {
    cout << "Destructing AnyClass !" << '\n';
  }

  string const &GetKey() const
  {
    return m_Key;
  }

  int GetValue() const
  {
    return m_Value;
  }
};

ostream &operator<<(ostream &os, AnyClass const &op)
{
  os
      << "( m_Key, m_Value ) == "
      << op.GetKey()
      << ", "
      << op.GetValue()
      << " )";

  return os;
}

int main()
{
  cout << "Cpp version ... " << __cplusplus << endl;
  auto uniquePointer{make_unique<AnyClass>("AnyClass", 10)};
  if (!uniquePointer)
  { // -------------------------------------^^^^^^^^---^^  variadic
    cerr << "make_unique<AnyClass> ( \"AnyClass\", 10 ) didn't succeed." << endl;
    return -1;
  }
  else
  {
    cout << "make_unique<AnyClass> ( \"AnyClass\", 10 ) did succeed." << endl;
    cout << *uniquePointer << endl;
  }

  return 0;
}
/*
The code in Listing 2-33 uses another "C++11" feature
to create a "make_unique" template.

The template is a "variadic" template
and it can take as many arguments as you wish to pass to it.

This is proven in the call to make_unique:
a string and an int are passed through to the AnyClass constructor.

The "__cplusplus"  preprocessor symbol is used
to detect the version of C++
that the compiler is using to build.

You may need to ensure
that this is working properly with the compiler that you are using
as not all compilers implement this correctly.

This code will build in C++11 using the user supplied make_unique template
and will compile in C++14 using the standard supplied make_unique template.
*/
