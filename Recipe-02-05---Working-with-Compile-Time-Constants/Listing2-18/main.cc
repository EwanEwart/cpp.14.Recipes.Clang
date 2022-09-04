/*
Using a C++14 constexpr Function
*/
#include <iostream>
#include <array>
#include <cstdint>

using std::cout ;
using std::endl ;
using std::array ;

uint32_t constexpr ArraySizeFunction ( uint32_t parameter ) // compile-tiime function
{
  uint32_t value { parameter } ;
  if  ( value > 10  )
  {
    value = 10 ;
  }
  return value ;
}

int main ()
{
  uint32_t constexpr ARRAY_SIZE { ArraySizeFunction ( 15 ) } ;
  array<uint32_t, ARRAY_SIZE> xArray { { 2,3,5,7,11,13,17,19,23,29 } } ;

  for  ( auto&& number : xArray )
    cout << number << ", " ;
  cout << endl ;

  return 0 ;
}
