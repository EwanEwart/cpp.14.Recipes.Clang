/*
Using constexpr to Define the Size of an array
*/
#include <iostream>
#include <array>
#include <cstdint>

using std::cout ;
using std::endl ;

int main ()
{
  uint32_t const x { 6 } ;
  uint32_t const y { 2 } ;
  uint32_t constexpr ARRAY_SIZE { x * y } ;
  std::array<uint32_t, ARRAY_SIZE> xArray { { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 } } ;

  for ( auto&& number : xArray)
    cout << number << ", " ;
  cout << endl ;

  return 0 ;
}
