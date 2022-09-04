/*
  Using a static_cast to Compile Narrowing Conversions
*/
#include <iostream>

using std::cout ;
using std::endl ;

int main ()
{
  int number { 0 } ;

    // static_cast :  inform the compiler that the narrowing conversions are intentional and to compile the code.
  char another { static_cast < char > ( 512 ) } ; // deliberate decision

  double bigNumber    { 1.0 } ;
  float littleNumber  { static_cast < float > ( bigNumber ) } ; // deliberate decision

  cout
    << '|' << number << '|'
    << '\n'
    << '|' << another << '|'
    << '\n'
    << '|' << bigNumber << '|'
    << '\n'
    << '|' << littleNumber << '|'
    << endl
    ;

  return 0 ;
}
