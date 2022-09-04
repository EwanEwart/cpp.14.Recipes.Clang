/*
  left value && right value references

  Extend XClass to contain a copy constructor
  and determine the impact this has
  on the number of objects in memory at any given time.
*/
#include <iostream>

using namespace std ;

class XClass
{

private:
  static int s_counter ;                 // class variable
  int*       m_member { & s_counter } ; // instance variable

public:
  XClass ()
  {
    ++ ( *m_member ) ;
    cout << "Constructing XClass ... " << GetValue () << '\n' ;
  }

  ~XClass ()
  {
    cout << "Destructing XClass ... " << s_counter << '\n' ;
    -- ( *m_member ) ;
    m_member = nullptr ;

  }

  XClass ( XClass const & rhs ) // copy-ctor  using left-value reference
  : m_member { rhs.m_member }
  {
    ++ ( *m_member ) ;
    cout << "Copy Ctor ... " << GetValue () << '\n' ;
  }

  int GetValue () const
  {
    return *m_member ;
  }
} ;

int XClass::s_counter { 0 } ; // initialise the "class variable"

// free-standing global copy-function
XClass g_copy_XClass ( XClass parameter )
// XClass parameter : ++copy_XClass;
// copy is going to die as soon as parameter is out of scope
{
  cout << "g_copy_XClass was called ... " << '\n' ;
  return parameter ; // ++copy_XClass : returned copy survives the function scope
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
    print_instance_count_of_XClass ( object2 ) ;
  }
  // 3.
  print_instance_count_of_XClass ( object1 ) ;

  // 4.
  auto object3 = XClass () ; // copy assignment ctor
  print_instance_count_of_XClass ( object3 ) ;

  // 5. copy ctor - parameter & return
  /* copy */ auto object4 = g_copy_XClass ( /* copy */ object3 ) ; // copy ctor
  print_instance_count_of_XClass ( object4 ) ;

  // 6. copy ctor - return assignment
  /* ref */ auto object5 = g_ref_XClass ( /* ref */ object3 ) ; // copy ctor
  print_instance_count_of_XClass ( object5 ) ;

  return 0 ;
}
