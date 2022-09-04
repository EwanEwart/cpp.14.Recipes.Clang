/*
  Unnamed function objects

  Referencing a Closure in a Variable
*/
#include <iostream>
#include <array>
#include <algorithm> // for_each
#include <typeinfo>  // typeid

#include <cstdint>  // uint32_t

#include "../../../demangle.h"

using std::array ;
using std::cout ;
using std::endl ;
using std::for_each ;

int main()
{
  using XArray = array<uint32_t, 5> ; // type - alias / type definition

  XArray xArray { { 2,3,5,7,11 } } ;

  #if 200400L < __cplusplus && __cplusplus < 201200L
  auto xClosure = [] ( XArray::value_type const & number ) // since c++11
  #else
  auto xClosure = [] ( auto&& number ) // since c++14
  #endif
  {
    cout << number << ", " ;
  }
  ;
  cout << '\n' ;
  cout << "typeid ( XArray ).name ()   ... " << cxx::demangle ( typeid ( XArray ).name () )   << '\n' ;
  cout << "typeid ( xClosure ).name () ... " << cxx::demangle ( typeid ( xClosure ).name () ) << '\n' ;

  for_each
  (
      xArray.begin ()
    , xArray.end   ()
    ,	xClosure
    )
  ;

  cout << endl ;

  return 0 ;
}
