/*
  Unnamed function objects

  Capturing xCopy by Value

  This shows the lambda using "capture by value" to copy xCopy.
*/
#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <functional>
#include <typeinfo>

#include <cstdint>

using std::cout ;
using std::endl ;

using XArray    = std::array    < uint32_t, 5                 > ; // type-alias
using XVector   = std::vector   < XArray::value_type          > ; // type-alias
using TheCpFunc = std::function < void ( XArray::value_type ) > ; // type-alias

void PrintArray ( TheCpFunc const & theCpFunc )
{
  XArray myArray { { 1, 2, 3, 4, 5 } } ;

  for_each
  (
      myArray.begin ()
    , myArray.end ()
    , theCpFunc
  ) ;
}

int main ()
{
  XVector theVectorCopy ;
  //Print auto cpPrintClosure = [ theVectorCopy ] ( auto&& number ) // theVectorCopy w/o ref -> failure // CentOS : no auto, please
  /*
    C++11 lambdas do not support the auto-keyword as a parameter !!!
  */
  // auto cpPrintClosure = [ theVectorCopy ] ( uint32_t && number ) // theVectorCopy w/o ref -> failure
  auto cpPrintClosure = [ theVectorCopy ] ( uint32_t && number ) mutable // "theVectorCopy" w/o ref, but "mutable": fine
  { /*
      The mutable keyword is used to tell the compiler
      that the lambda function should generate a closure
      with non-const members
      that have been copied by value,
      such as theVectorCopy, which was not pass as "& theVectorCopy".
      The closures created by the compiler when it encounters a lambda function are "const" by default.
    */
    cout << number << ", " ;
    theVectorCopy.push_back ( number ) ;
  } ;
  cout << typeid ( cpPrintClosure ).name () << '\n' ;

  auto printClosure = [ ] ( uint32_t && number ) // CentOS: w/o auto, explicit type
  {
    cout << number << ", " ;
  } ;

  PrintArray ( cpPrintClosure ) ;

  cout << '\n' << "My Copy: " << '\n' ;
  for_each
  (
      theVectorCopy.cbegin ()
    , theVectorCopy.cend ()
    , [] ( auto&& number ) // CentOS: no auto, please.
    // , [] ( uint32_t && number ) // CentOS: no &&, please.
    // , [] ( uint32_t number )
    {
      cout << number << ", " ;
    }
  ) ;

  // PrintArray ( printClosure ) ;

  cout << endl ;

  return 0 ;
}
