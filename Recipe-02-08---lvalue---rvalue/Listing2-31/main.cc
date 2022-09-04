/*
  left value && right value references
*/
#include <chrono>
#include <iostream>
#include <string>
#include <vector>

using namespace std ;
using namespace chrono ;
using namespace literals ;

class XClass
{
private:
  vector<string> m_String{
    "This is a pretty long string that"
    " must be copy constructed into"
    " copyConstructed!"s
  } ;

  int m_Value{ 1 } ;

public:
  XClass () = default ;
  XClass ( const XClass& rhs ) = default ;
  XClass ( XClass&& rhs ) = default ;

  int GetValue () const
  {
    return m_Value ;
  }
} ;

int main ()
{
  using MyVector = vector<XClass> ;
  constexpr unsigned int ITERATIONS{ 1000000U } ;

  MyVector copyConstructed ( ITERATIONS ) ;
  int value{ 0 } ;

  auto copyStartTime = high_resolution_clock::now () ;
  for  ( unsigned int i=0 ; i < ITERATIONS ; ++i )
  {
    XClass xClass ;
    copyConstructed.push_back ( xClass ) ;
    value = xClass.GetValue () ;
  }
  auto copyEndTime = high_resolution_clock::now () ;

  MyVector moveConstructed ( ITERATIONS ) ;

  auto moveStartTime = high_resolution_clock::now () ;
  for  ( unsigned int i=0 ; i < ITERATIONS ; ++i )
  {
    XClass xClass ;
    moveConstructed.push_back ( move ( xClass ) ) ;
    value = xClass.GetValue () ;
  }
  auto moveEndTime = high_resolution_clock::now () ;

  cout << value << endl ;

  auto copyDuration =
  duration_cast<milliseconds> ( copyEndTime - copyStartTime ) ;
  cout << "Copy lasted: " << copyDuration.count () << "ms" << endl ;

  auto moveDuration =
  duration_cast<milliseconds> ( moveEndTime - moveStartTime ) ;
  cout << "Move lasted: " << moveDuration.count () << "ms" << endl ;

  return 0 ;
}
