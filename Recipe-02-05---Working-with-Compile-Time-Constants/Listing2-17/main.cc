/*
Creating constexpr class Constructors
*/
#include <iostream>
#include <array>
#include <cstdint>

using std::cout ;
using std::endl ;
using std::array ;

class XClass
{
private:
  uint32_t m_Member ;

public:
  constexpr XClass ( uint32_t parameter )
  : m_Member { parameter }
  {
  }

  uint32_t constexpr GetValue () const
  {
    return m_Member * 5 ;
  }
} ;

int main ()
{
  uint32_t constexpr ARRAY_SIZE {  XClass {  2  }.GetValue ()  } ;
  array<uint32_t, ARRAY_SIZE> xArray {  { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29  } } ;
  for ( auto&& number : xArray )
    cout << number << ", " ;
  cout << endl ;

  return 0 ;
}
