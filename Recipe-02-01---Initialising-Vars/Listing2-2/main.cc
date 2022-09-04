/*
Listing 2-2. Using Uniform Initialization to Solve the Vexing Parse Problem
*/
#include <typeinfo> // typeid
#include <iostream>
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
  XClass ( const XClass & rhs ) = default ;
  bool operator== ( XClass const & rhs ) { return m_Member == rhs.m_Member ; }
  bool operator!= ( XClass const & rhs ) { return m_Member != rhs.m_Member ; }
  void set ( int value ) { m_Member = value ; }
  int  get () { return m_Member ; }
} ;

int main ()
{
  XClass objectA ;

  // c++11 Uniform Initialisation
  XClass objectB { XClass {} } ; // copy ctor

  objectB.set ( 4711 ) ;

  cout
    << "Type of objectA ... " << demangle ( typeid ( objectA ) .name () ) << '\n'
    << "Type of objectB ... " << demangle ( typeid ( objectB ) .name () ) << '\n'
    << "Are the types the same ? ... " << boolalpha << ( typeid ( objectA ) == typeid ( objectB ) ) << '\n'
    << "Are the instances' locations different from each other ? ... " << boolalpha << ( & objectA != & objectB ) << '\n'
    << "Are the instances - incapsulated values - the same  ? ... " << boolalpha << ( objectA == objectB ) << '\n'
    << "Are the instances - incapsulated values - different ? ... " << boolalpha << ( objectA != objectB ) << '\n'
    << endl
    ;
  return 0 ;
}
