/*
The c++ most vexing parse problem
*/
#include <iostream>
#include <typeinfo> // typeid
#include <iomanip>
#include <boost/core/demangle.hpp>

using std::cout ;
using std::endl ;
using std::boolalpha ;

using boost::core::demangle ;

class XClass
{
private:
  int m_Member ;

public:
  XClass () = default ; // Explicitly forcing the automatic generation of a default constructor by the compiler.
  XClass ( XClass const & rhs ) = default ; // copy ctor
} ;

int main ()
{
  XClass objectA ;

  // C++96's most vexing parsing problen
  // XClass objectB ( XClass () ) ; // c++14 : function call disambiguation
  /*
warning: parentheses were disambiguated as a function declaration [-Wvexing-parse]
  XClass objectB ( XClass () ) ; // c++14 : function call disambiguation
                 ^~~~~~~~~~~~~
  */

  // C++11 Uniform Initialisation gets rid of of the vexing parsing problem - disambiguation
  XClass objectB { XClass {} } ; // copy ctor

  cout
    << demangle ( typeid ( objectA) .name () ) << '\n'
    << demangle ( typeid ( objectB) .name () ) << '\n'
    << "Are they two instances of the same type ... " << boolalpha << ( typeid ( objectA) == typeid ( objectB ) ) << '\n'
    << "Are they two different instances ... " << boolalpha << ( & objectA != & objectB ) << '\n'
    << endl ;

  return 0 ;
}
