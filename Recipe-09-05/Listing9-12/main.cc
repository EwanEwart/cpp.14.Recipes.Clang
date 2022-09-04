#include <iostream>
using std::cout ;
using std::endl ;

#include <string>
using std::string ;

template <int stringLength>
struct SDBMCalculator
{
  constexpr static unsigned int Calculate ( const char* const stringToHash, unsigned int& value )
  {
    unsigned int character{ SDBMCalculator<stringLength - 1>::Calculate ( stringToHash, value ) } ;
    value = character +  ( value << 6 ) +  ( value << 16 ) - value ;
    return stringToHash[stringLength - 1] ;
  }

  constexpr static unsigned int CalculateValue ( const char* const stringToHash )
  {
    unsigned int value{} ;
    unsigned int character{ SDBMCalculator<stringLength>::Calculate ( stringToHash, value ) } ;
    value = character +  ( value << 6 ) +  ( value << 16 ) - value ;
    return value ;
  }
} ;

template<>
struct SDBMCalculator < 1 >
{
  constexpr static unsigned int Calculate ( const char* const stringToHash, unsigned int& value )
  {
    return stringToHash[0] ;
  }
} ;

constexpr static string const names { "Bruce Sutherland", "Catherine", "Fiona-Louise", "Ewan" } ;

constexpr static unsigned int const sdbmHash
{
  sdbmHash{ SDBMCalculator<16>::CalculateValue ( names[0] ) } ;
  sdbmHash{ SDBMCalculator<16>::CalculateValue ( names[1] ) } ;
  sdbmHash{ SDBMCalculator<16>::CalculateValue ( names[2] ) } ;
  sdbmHash{ SDBMCalculator<16>::CalculateValue ( names[3] ) } ;
} ;

int main ( int ac, char* av[] )
{
  for(auto name:names)
    cout << "The hash of" << name[i] << " is " << sdbmHash << endl ;

  return 0 ;
}
