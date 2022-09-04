/*
Deducing a Function’s Return Type Using auto
*/
#include <iostream>
#include <typeinfo>
#include <boost/core/demangle.hpp>

using namespace std ;

using boost::core::demangle ;

auto AutoFunctionFromReturn ( double parameter )
{
  return parameter ;
}

int main ()
{
  auto value { AutoFunctionFromReturn ( 1.0 )  } ;

  cout << "typeid ( value ) .name () ... " << demangle ( typeid ( value ) .name () ) << '\n' ; // int
  cout << "value ... " << value << '\n' ;

  cout << endl ;

  return 0 ;
}
