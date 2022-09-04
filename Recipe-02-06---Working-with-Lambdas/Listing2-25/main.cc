/*
  Unnamed function objects

  A C++11 Compatible Lambda Function
*/
#include <iostream>

#include <array>
#include <vector>
#include <functional>
#include <algorithm>

#include <typeinfo>

#include <boost/core/demangle.hpp>

#include <cstdint>

using std::for_each ;
using std::cout ;
using std::endl ;

using SrcArray   = std::array    < uint32_t, 5                   > ; // type-alias
using DestVector = std::vector   < SrcArray::value_type          > ; // type-alias
using Action     = std::function < void ( SrcArray::value_type ) > ; // type-alias

using boost::core::demangle ;

void PrintArray ( Action const & action )
{
  SrcArray myArray { { 1, 2, 3, 4, 5 } } ;

  for_each
  (
      myArray.begin ()
    , myArray.end ()
    , action
  ) ;
}

template<typename T>
void printIlist ( std::initializer_list<T> const & vals )
{
  // // process a list of values
  // for ( auto p = vals .begin () ;   p != vals .end () ;   ++p )
  // {
  //   cout << *p << ", " ;
  // }

  // process a list of values
  for ( auto item : vals )
    cout << item << ", " ;
  cout << '\n' ;
}

int main ()
{
  DestVector vecCopy ;

  #if 200400L < __cplusplus && __cplusplus < 201200L
  // C++11 version, less portable, because it is limited to SrcArray::value_type
  auto copyClosure = [ & vecCopy ] ( SrcArray::value_type const & number ) // Type "const" ref !!!
  #else
  auto copyClosure = [ & vecCopy ] ( auto && number )
  #endif
  {
    cout << number << ", " ;
    vecCopy.push_back ( number ) ;
  } ;
  cout << "- (1) -  typeid ( copyClosure ).name () ... "  << demangle ( typeid ( copyClosure ).name () ) << '\n' ;

  #if 200400L < __cplusplus && __cplusplus < 201200L
  // C++11 version, less portable, because it is limited to SrcArray::value_type
  auto printClosure = [ & vecCopy ] ( SrcArray::value_type const & number )  // Type "const" ref !!!
  #else
  auto printClosure = [ & vecCopy ] ( auto && number )
  #endif
  {
    cout << number << ", " ;
  } ;
  cout << "- (2) -  typeid ( printClosure ).name () ... "  << demangle ( typeid ( printClosure ).name () ) << '\n' ;

  PrintArray ( copyClosure ) ;

  cout << '\n' << "My Copy: " << '\n' ;
  PrintArray ( printClosure ) ;
  cout << '\n' ;

  // test IList, initialisation list
  //
  printIlist ( { 2,3,5,7,11,13,17,19} ) ;
  printIlist ( { 2.2f,3.3f,5.5f,7.7f,11.11f,13.13f,17.17f,19.19f} ) ;

  cout << endl ;

  return 0 ;
}
