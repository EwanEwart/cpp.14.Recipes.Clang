#include <iostream>
#include <memory>

/*
  std::make_unique<...>(...) since c++14
  std::make_unique<...>(...) doesn't exist for c++11
  remedy : boost or header file below
*/
// #include "../../memory-c++11.h"

// using std::cerr;
// using std::cout;
// using std::endl;
// using std::make_unique;
// using std::string;
// using std::unique_ptr;

class AnyClass
{

private:
  std::string m_Key;
  int m_Value;

public:
  AnyClass(std::string const &key, int value)
      : m_Key{key}, m_Value{value}
  {
    std::cout << "Constructing AnyClass !" << '\n';
  }

  virtual ~AnyClass()
  {
    std::cout << "Destructing AnyClass !" << std::endl;
  }

  std::string const &GetKey() const
  {
    return m_Key;
  }

  int GetValue() const
  {
    return m_Value;
  }
};
// up == unique ptr
// up == unique ptr
// up == unique ptr
using UpAnyClass = std::unique_ptr<AnyClass>;

#if 200400L < __cplusplus && __cplusplus < 201200L
auto passUptr(upXCls up) -> decltype(up)
#else
auto passUp(UpAnyClass up)
#endif
{
  std::cout << "In Function passUp ... " << up->GetKey() << '\n';
  return up;
}

int main()
{
  auto up1 = std::make_unique<AnyClass>("AnyClass", 10);

  // auto up2 = std::move(up1);
  auto up2 = passUp(std::move(up1));

  if (up1)
  {
    std::cerr << "--- Panic!   up1 still points to  " << up1->GetKey() << '\n';
  }
  else
  {
    std::cout << "up1 invalidated." << std::endl;
  }

  if (up2)
  {
    std::cout << "Now \"up2\" points to the unique object \"" << up2->GetKey() << "\"." << '\n';
  }
  else
  {
    std::cerr << "--- Panic!   up1 wasn't moved to up2.  " << std::endl;
  }

  return 0;
}
/*
Moving a unique_up
===================
Unique pointers are exactly as you expect: they are unique.

Therefore your code cannot have more than a single instance of a unique_ptr
pointing to the same object at a time.

It achieves this
by preventing copy operations on unqiue_ptr instances.

A unique ptr can be "moved" however
and this allows to pass a unique_up around in a program.

Listing 2-34 shows
how you can use move semantics
to pass a unqiue_ptr around your program.


The code in Listing 2-34 moves a unique_ptr instance into a function.

That instance is then moved back out of the function
into a second unique_ptr object.

There’s no reason why the same unique_ptr couldn’t have been used in main
other than to show
that the original instance is not valid after it has been moved from.

This is evident in the if call to check if the pointer is valid
as this will fail when the code is executed.

The unique_ptr can be used in this manner
and the object pointed to by the instance will be deleted
once it goes out of scope without having been moved from.

*/
