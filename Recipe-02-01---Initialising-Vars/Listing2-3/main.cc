/*
  Using Uniform Initialization to Prevent Narrowing Conversions

  The ability to prevent narrowing conversions
  is another benefit of using uniform initialisation.

  Using Uniform Initialisation to Prevent Narrowing Conversions
*/

#include <iostream>

using std::cout ;
using std::endl ;

int main ()
{
  // 1. fine
  //
  int number   { 0 } ;

  // 2. uniform initialisation will fail (error) : c++11-narrowing
  //
  // char another { 512 } ;
  /*
error: constant expression evaluates to 512 which cannot be narrowed to type 'char' [-Wc++11-narrowing]
  char another { 512 } ;
                 ^~~
  */
  // 3. assignment will fail (warning) : constant-conversion / implicit conversion / changes value
  //
  // char another = 512 ;
  /*
warning: implicit conversion from 'int' to 'char' changes value from 512 to 0 [-Wconstant-conversion]
char another = 512 ;
     ~~~~~~~   ^~~
  */

  // 4. static_cast : inform the compiler that the narrowing conversions are intentional and to compile the code.
  //
  char another =  static_cast <char> ( 512 ) ;

  // 5.
  //
  double bigNumber   { 1.0 } ;

  // 6.
  // float littleNumber { bigNumber } ( error ) ;
  /*
error: non-constant-expression cannot be narrowed from type 'double' to 'float' in initializer list [-Wc++11-narrowing]
  float littleNumber { bigNumber } ;
                       ^~~~~~~~~
main.cc:18:24: note: insert an explicit cast to silence this issue
  float littleNumber { bigNumber } ;
                       ^~~~~~~~~
  */

   // 7. narrowing - no intialisation list syntax
   //
  float littleNumber = bigNumber ;

  cout
    << "1. int number   { 0 } ... " << number
    << '\n'
    << "4. char another =  static_cast <char> ( 512 ) ... " <<  another
    << '\n'
    << "5. double bigNumber   { 1.0 } ... " << bigNumber
    << '\n'
    << "7. float littleNumber = bigNumber ... " << littleNumber
    << endl ;

  return 0 ;
}
