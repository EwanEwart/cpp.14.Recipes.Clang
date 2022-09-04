/*
  left value && right value references

  A Class that Counts the Number of Instances using a class variable.

  Modern C++ contains two different reference operators,
  & (lvalue) and && (rvalue).
  These work hand-in-hand with move semantics
  to reduce the time spent copying objects.
*/

//
// Class Variables
//
#include <iostream>

using namespace std ;

class XClass
{

private:
  static int s_Counter ; // "class variable"

  int* m_Member { &s_Counter } ; // "instance variable" : a pointer to the "class variable"

public:
  XClass ()
  {
    ++ ( *m_Member ) ;
  }

  ~XClass ()
  {
    -- ( *m_Member ) ;
    m_Member = nullptr ; // Is this really necessary ???
  }

  int GetValue () const
  {
    return *m_Member ;
  }
} ;

int XClass::s_Counter { 0 } ; // initialise the class variable

void print_instance_count ( XClass const & object )
{
  static unsigned short cnt = 0 ;

  cout
    << ++cnt << ". "
    << object .GetValue ()
    << " times XClass."
    << '\n'
    ;
}

int main ()
{
  // 1.
  auto object1 = XClass () ;
  print_instance_count ( object1 ) ;

  {
    // 2.
    auto object2 = XClass () ;
    print_instance_count ( object2 ) ;
  }

  // 3.
  print_instance_count ( object1 ) ;

  // 4.
  auto object3 = XClass () ;
  print_instance_count ( object3 ) ;

  cout << endl ;

  return 0 ;
}
