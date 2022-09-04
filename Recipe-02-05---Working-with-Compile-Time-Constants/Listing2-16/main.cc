/*
 A constexpr Function
 */
#include <iostream>
#include <array>
#include <cstdint>

using std::cout ;
using std::endl ;
using std::array ;

uint32_t constexpr ArraySizeFunction ( int parameter ) // compile-time function
{
  return parameter * 5 ;
}
int main ()
{
  uint32_t constexpr ARRAY_SIZE { ArraySizeFunction ( 2 ) } ;
  array<uint32_t, ARRAY_SIZE> xArray { { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 } } ;
  for  ( auto&& number : xArray )
    cout << number << ", " ;
  cout << endl ;

  return 0 ;
}
