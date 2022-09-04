/*
  Unnamed function objects

  Creating a mutable closure

  Listing 2-24 contains the solution to all of the error output that you can see in Listing 2-23.

  The "mutable" keyword is used
  to tell the compiler
  that the lambda function should generate a closure
  with non-const members
  that have been copied by value.

*/
#include <iostream>

#include <functional>
#include <array>
#include <algorithm>
#include <vector>

#include <typeinfo>

#include <boost/core/demangle.hpp>

#include <cstdint>

using std::cout ;
using std::endl ;

using std::for_each ;

using boost::core::demangle ;

using SrcArray   = std::array      < uint32_t, 5                   > ; // type-alias
using DestVector = std::vector     < SrcArray::value_type          > ; // type-alias

#if 200400L < __cplusplus && __cplusplus < 201200L
using Action     = std::function   < void ( SrcArray::value_type ) > ; // type-alias
#else
using Action     = std::function   < void ( auto&& ) > ; // type-alias
#endif

void PrintArray ( Action const & action )
{
  SrcArray myArray { { 1, 2, 3, 4, 5 } } ;

  cout << "- (1) -  typeid ( SrcArray::value_type ) ... " << demangle ( typeid ( SrcArray::value_type ) .name () ) << '\n' ;
  cout << "- (2) -  typeid ( Action ) .name () ... " << demangle ( typeid ( Action ) .name () ) << '\n' ;
  for_each
  (
      myArray.begin () // range begin
    , myArray.end   () // range end
    , action
    ) ;
}

/*
The "closures"   created by the compiler
when they encounter a lambda function
are const by default.

This causes the compiler to create a type for the closure
that can no longer be implicitly converted to a standard function pointer.

The resulting error messages generated by a compiler
when you try to use a lambda function to generate a closure
 that is not a suitable type for your code can be exceptionally confusing.

There is no real solution here
other than to properly learn
how to use lambda functions
and to compile often when working
to pick up when you have made a change that the compiler cannot handle.
*/

// A const closure ???
//
class C1
{
  int x ;
public:
  int operator () () const { return x ; }
} ;

int main ()
{
  // house-keeping
  //

  DestVector destVecCopy ;

  // auto CopyClosure = [destVecCopy] ( auto && number ) mutable // c++11: no auto in c++11 lambdas, whereas this c++14 version is type-independent
  #if 200400L < __cplusplus && __cplusplus < 201200L
  auto CopyClosure = [destVecCopy] ( DestVector::value_type && number ) mutable
  #else
  auto CopyClosure = [destVecCopy] ( auto && number ) mutable
  #endif
  {
    cout << number << ", " ; // print
    destVecCopy.push_back ( number ) ; // destVecCopy is now mutable !!!
  } ;
  cout << "- (3) - typeid ( CopyClosure ) .name () ... " << demangle ( typeid ( CopyClosure ) .name () ) << '\n' ;

  // auto printClosure = [ ] ( auto&& number )  // c++11: no auto in c++11 lambdas, whereas this c++14 version is type-independent
  #if 200400L < __cplusplus && __cplusplus < 201200L
  auto printClosure = [ ] ( DestVector::value_type && number )  // c++11: no auto in c++11 lambdas
  #else
  auto printClosure = [ ] ( auto && number )  // c++11: no auto in c++11 lambdas
  #endif
  {
    cout << number << ", " ; // print
  } ;
  cout << '\n' ;
  cout << "- (4) - typeid ( printClosure ) .name () ... " << demangle ( typeid ( printClosure ) .name () ) << '\n' ;
  //
  // end of house-keeping

  // actual processing
  //
  PrintArray ( CopyClosure ) ;

  cout << '\n' << "My Copy: " << '\n' ;
  PrintArray ( printClosure ) ;

  cout << endl ;

  return 0 ;
}
