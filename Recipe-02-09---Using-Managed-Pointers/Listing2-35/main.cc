#include <iostream>
#include <iomanip>
#include <memory> // make_shared

#include "../../../demangle.h"

using std::boolalpha;
using std::cout;
using std::endl;
using std::make_shared;
using std::shared_ptr;
using std::string;

class AnyClass
{

private:
  string m_Key;
  int m_Value;

public:
  AnyClass(string const &key, int value)
      : m_Key{key}, m_Value{value}
  {
    cout << "Constructing AnyClass !" << endl;
  }

  virtual ~AnyClass()
  {
    cout << "Destructing AnyClass !" << endl;
  }

  string const &GetKey() const
  {
    return m_Key;
  }

  int GetValue() const
  {
    return m_Value;
  }
};

using SpAnyClass = shared_ptr<AnyClass>; // alias, sort of typedef

#if 200400L < __cplusplus && __cplusplus < 201200L
auto passSp(XClassSharedPtr ptr) -> decltype(ptr) // since c++11
#else
auto passSp(SpAnyClass sp) // since c++14
#endif
{
  cout << "In Function passSp ... " << sp->GetKey() << endl;
  cout << "In Function passSp ...  sp.use_count () ... " << sp.use_count() << '\n';
  return sp;
}

int main()
{
  string demangled;

  auto sp = make_shared<AnyClass>("AnyClass", 10);

  int status = cxx::demangle2(demangled, typeid(sp).name());
  cout << "1. sharedPointer -- " << typeid(sp).name() << ".use_count () ... " << sp.use_count() << '\n';
  cout << "1. sharedPointer -- " << demangled << " -- sp.use_count () ... " << sp.use_count() << '\n';

  {
    auto newSp = passSp(sp);
    cout << "2. sharedPointer -- " << typeid(sp).name() << ".use_count () ... " << sp.use_count() << '\n';
    cout << "2. sharedPointer -- " << cxx::demangle(typeid(sp).name()) << " -- .use_count () ... " << sp.use_count() << '\n';
    if (sp)
    {
      cout << "First Object Name: " << sp->GetKey() << endl;
      cout << "3. sharedPointer -- " << typeid(sp).name() << ".use_count () ... " << sp.use_count() << '\n';
    }

    cout << "Second Object Name: " << newSp->GetKey() << endl;
    cout << "4. newSharedPointer -- " << typeid(sp).name() << ".use_count () ... " << newSp.use_count() << '\n';
    cout << "4. newSharedPointer -- " << cxx::demangle(typeid(sp).name()) << ".use_count () ... " << newSp.use_count() << '\n';
    cout
        << boolalpha
        << "( sharedPointer .get () == newSharedPointer .get () ) ... "
        << (sp.get() == newSp.get())
        << '\n';
    cout
        << boolalpha
        << "( sharedPointer == newSharedPointer ) ... "
        << (sp == newSp)
        << '\n';
  }
  cout << "5. sharedPointer -- " << typeid(sp).name() << ".use_count () ... " << sp.use_count() << '\n';
  cout << "5. sharedPointer -- " << cxx::demangle(typeid(sp).name()) << ".use_count () ... " << sp.use_count() << '\n';

  return 0;
}
/*
A --- unique_ptr can give you --- sole ownership --- over a single object
that you can --- move --- around in a --- single pointer instance ---,
a --- shared_ptr --- can give you --- shared ownership --- over a single object.

This works by having a --- shared_ptr ---
storing an --- internal reference count ---
along with the pointer to the object
and only deleting the object
once all of the values have gone out of scope.

This Listing 2-35 shows the use of a shared_ptr.

The ---shared_ptr--- in Listing 2-35 has a different to the unique_ptr 
that you have seen before. 

A shared_ ptr can be copied through your program 
and you can have multiple shared pointers pointing to the same object.

*/
