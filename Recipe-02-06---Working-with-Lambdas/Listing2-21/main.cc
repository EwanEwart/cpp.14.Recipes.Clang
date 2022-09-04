/*
  Unnamed function objects

  Passing a Closure into a Function using the function<T> template
*/

#include <iostream>   // cout, ...
#include <array>      // std::array<T>
#include <algorithm>  // for_each
#include <functional> // std::function<T>
#include <typeinfo>   // typeid

#include <cstdint> //

#include "../../../demangle.h"

using std::cout ;
using std::endl ;
using std::array ;
using std::function ;
using std::for_each ;

using XArray = array    < uint32_t, 5 > ; // type-alias
using AFunc  = function < void ( XArray::value_type ) > ; // type-alias

void PrintArray ( AFunc const & aFunc )
{
  XArray xArray { { 1, 2, 3, 4, 5 } } ;

  cout << "xArray ... " << cxx::demangle ( typeid ( xArray ) .name () ) << '\n' ;
  cout << "aFunc  ... " << cxx::demangle ( typeid ( aFunc  ) .name () ) << '\n' ;

  for_each
  (
      xArray.begin ()
    , xArray.end   ()
    ,	aFunc
    )
  ;
  cout << endl ;
}

int main ()
{
  #if 200400L < __cplusplus && __cplusplus < 201200L
  auto xClosure = [] ( XArray::value_type && number ) // since c++11
  #else
  auto xClosure = [] ( auto&& number ) // since c++14
  #endif
  {
    cout << number << ", " ;
  }
  ;

  cout << "xClosure ... " << cxx::demangle ( typeid ( xClosure ) .name () ) << '\n' ;

  PrintArray ( xClosure ) ;

  cout << endl ;

  return 0 ;
}
