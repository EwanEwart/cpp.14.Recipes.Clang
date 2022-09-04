/*
  left value && right value references

  "Move constructors" can be utilised to cut down on the complexity of a copy constructor.

  There will be just as many objects in flight however
  you can safely "shallow copy" an object in a "move constructor"
  thanks to the "rvalue reference type"
  that they are passed.

  A "rvalue reference" is a guarantee from the compiler
  that the object referenced by the variable was a temporary object.

  This means that you are free to cannibalise the object
  so that you can implement a copy operation faster
  than if the pre-existing state was needed to be preserved.

  Listing 2-30 shows how to add a move constructor to XClass.
*/

#include <iostream>

using namespace std ;

class XClass
{
private:
  static int s_Counter ; // class variable

  int* m_member { & s_Counter } ;

public:
  XClass ()
  {
    ++ ( *m_member ) ;
    cout << "Constructed XClass ... " << GetValue () << '\n' ;
  }

  ~XClass ()
  {
    if  ( m_member )
    {
      cout << "Destructing: " << s_Counter << '\n' ;
      -- ( *m_member ) ;
      m_member = nullptr ;
    }
    else
    {
      cout << "Destroying a moved-from instance" << '\n' ;
    }
  }

  XClass ( XClass const & rhs ) // copy - ctor
  : m_member { rhs.m_member }
  {
    ++ ( *m_member ) ;
    cout << "Copying: " << GetValue () << '\n' ;
  }

  XClass ( XClass && rhs ) // move - ctor
  : m_member { rhs.m_member }
  {
    cout << hex << showbase ;
    cout << "Moving: " << &rhs << " to " << this << '\n' ;
    cout << noshowbase << dec ;
    rhs.m_member = nullptr ;
  }

  int GetValue () const
  {
    return *m_member ;
  }
} ;

int XClass::s_Counter { 0 } ;

XClass g_copy_XClass ( XClass parameter )
{
  return parameter ;
}

XClass const & g_ref_XClass ( XClass const & parameter )
{
  cout << "g_ref_XClass was called ... " << '\n' ;
  return parameter ;
}

void print_instance_count_of_XClass ( XClass const & object ) // helper
{
  static unsigned int k = 0 ;
  cout << ++k << "   --->   " << object .GetValue () << '\n' ;
}

int main ()
{
  // 1.
  auto object1 = XClass () ;
  print_instance_count_of_XClass ( object1 ) ;

  {
    // 2.
    auto object2 = XClass () ;
    print_instance_count_of_XClass ( object1 ) ;
  }
  // 3.
  print_instance_count_of_XClass ( object1 ) ;

  // 4.
  auto object3 = XClass () ;
  print_instance_count_of_XClass ( object1 ) ;

  // 5.
  auto object4 = g_copy_XClass ( object3 ) ;
  print_instance_count_of_XClass ( object1 ) ;

  // 6. copy ctor - return assignment
  /* ref */ auto object5 = g_ref_XClass ( /* ref */ object3 ) ; // copy ctor
  print_instance_count_of_XClass ( object5 ) ;

  cout << '\n' ;

  return 0 ;
}
