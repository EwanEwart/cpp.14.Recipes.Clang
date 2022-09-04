/*
  Unnamed function objects

  Using the Lambda capture feature.

  A method to copy an array into a vector
  through a lambda using the capture block.

*/
#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <functional>
#include <typeinfo>

#include <cstdint>

#include <boost/core/demangle.hpp>

using std::cout ;
using std::endl ;
using std::for_each ;
using boost::core::demangle ;

using XArray   = std::array    < uint32_t, 5 >                 ; // type-alias
using XVector  = std::vector   < XArray::value_type >          ; // type-alias
using XCpFunct = std::function < void ( XArray::value_type ) > ; // type-alias

void PrintArray ( XCpFunct const & aFunc )
{
  XArray xArray { { 1, 2, 3, 4, 5 } } ;

  cout << "typeid ( XArray::value_type ) .name () ... " << demangle ( typeid ( XArray::value_type ) .name () ) << '\n' ;
  // $ type-id ( XArray::value_type ) .name () ... unsigned integer
  cout << "typeid ( aFunc ) .name () ... " << demangle ( typeid ( aFunc ) .name () ) << '\n' ;
  // typeid ( aFunc ) .name () ... std::function<void (unsigned int)>

  for_each
  (
      xArray.begin ()
    , xArray.end ()
    , aFunc
  ) ;
  cout << endl ;
}

int main ()
{

  XVector vCopy ;

  // vector reference capture !
  #if 200400L < __cplusplus && __cplusplus < 201200L
  auto xClosure = [ & vCopy ] ( XArray::value_type && number ) // since c++11
  #else
  auto xClosure = [ & vCopy ] ( auto&& number ) // since c++14
  #endif
  {
    cout << number << ", " ;
    vCopy.push_back ( number ) ;
  } ;

  // auto printClosure = [] ( uint32_t && number )
  #if 200400L < __cplusplus && __cplusplus < 201200L
  auto printClosure = [] ( XVector::value_type const & number ) // since c++11
  #else
  auto printClosure = [] ( auto&& number ) // since c++14
  #endif
  {
    cout << number << ", " ;
  } ;

  cout << "typeid ( xClosure ).name () ... " << demangle ( typeid ( xClosure ).name () ) << '\n' ;
  // typeid ( xClosure ).name () ... main::$_0

  PrintArray ( xClosure ) ;

  cout << '\n' << "The vector Copy using the for_each algorithm && the printClosure : " << '\n' ;
  std::for_each
  (
      vCopy.cbegin () // range : start
    , vCopy.cend   () // range : end
    // , [] ( uint32_t && number ) // CentOS : no "&&", please
    // {
    //   cout << number << '\n' ;
    // }
    , printClosure
  ) ;

  cout << '\n' << "The vector Copy using the range-based for-loop && the printClosure : " << '\n' ;
  for ( auto item : vCopy )
  {
    printClosure ( item ) ;
  }

  cout << endl ;

  return 0 ;
}
