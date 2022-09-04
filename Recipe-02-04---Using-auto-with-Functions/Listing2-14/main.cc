/*
Using auto to deduce the return type on a template function
*/

#include <iostream>
#include <typeinfo>
#include <boost/core/demangle.hpp>

using namespace std ;
using boost::core::demangle ;

template <typename T>
auto AutoFunctionFromParameter ( T parameter )
{
  return parameter ;
}

int main ()
{
  auto value = AutoFunctionFromParameter ( 40.04f ) ;
  cout << "typeid ( value ) .name () ... " << demangle ( typeid ( value ) .name () ) << '\n' ;
  cout << "value ... " << value << '\n' ;

  cout << endl ;

  return 0 ;
}
