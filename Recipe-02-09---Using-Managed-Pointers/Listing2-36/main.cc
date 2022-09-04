#include <boost/core/demangle.hpp>
#include <typeinfo> // typeid
#include <memory>
#include <iostream>

// #include "../../../demangle.h"

using std::cout;
using std::endl;
using std::make_shared;
using std::shared_ptr;
using std::string;
using std::weak_ptr;

class AnyClass
{

private:
  string m_Key;
  int m_Value;

public:
  AnyClass(string const &key, int value)
      : m_Key{key}, m_Value{value}
  {
    cout << "Constructing AnyClass !" << '\n';
  }

  ~AnyClass()
  {
    cout << "Destructing AnyClass !" << '\n';
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

using TypeSharedPtrAnyClass = shared_ptr<AnyClass>; // alias
using TypeWeakPtrAnyClass = weak_ptr<AnyClass>;     // alias

#if __cplusplus > 200400L && __cplusplus < 201200L
auto PassSharedPtr(TypeSharedPtrAnyClass ptr) -> decltype(ptr)
#else
auto PassSharedPtr(TypeSharedPtrAnyClass ptr)
#endif
{
  cout << "In Function PassSharedPtr ... " << ptr->GetKey() << " ( " << ptr.use_count() << " ) " << '\n';
  return ptr;
}

int main()
{
  TypeWeakPtrAnyClass aWeakPtrAnyClass;
  {
    auto aSharedPtrAnyClass = make_shared<AnyClass>("AnyClass", 10);
    cout << "1. " << boost::core::demangle(typeid(aSharedPtrAnyClass).name()) << " ( " << aSharedPtrAnyClass.use_count() << " ) " << '\n';
    aWeakPtrAnyClass = aSharedPtrAnyClass;
    cout << "2. " << boost::core::demangle(typeid(aWeakPtrAnyClass).name()) << " ( " << aWeakPtrAnyClass.use_count() << " ) " << '\n';
    cout << "3. " << boost::core::demangle(typeid(aSharedPtrAnyClass).name()) << " ( " << aSharedPtrAnyClass.use_count() << " ) " << '\n';
    // aWeakPtrAnyClass = aSharedPtrAnyClass;
    // cout << "2. " << cxx::demangle(typeid(aWeakPtrAnyClass).name()) << " ( " << aWeakPtrAnyClass.use_count() << " ) " << '\n';
    // cout << "3. " << cxx::demangle(typeid(aSharedPtrAnyClass).name()) << " ( " << aSharedPtrAnyClass.use_count() << " ) " << '\n';

    {
      auto newSharedPointerAnyClass = PassSharedPtr(aSharedPtrAnyClass);
      cout << "4. " << boost::core::demangle(typeid(newSharedPointerAnyClass).name()) << " ( " << newSharedPointerAnyClass.use_count() << " ) " << '\n';
      // cout << "4. " << cxx::demangle(typeid(newSharedPointerAnyClass).name()) << " ( " << newSharedPointerAnyClass.use_count() << " ) " << '\n';
      if (aSharedPtrAnyClass)
      {
        cout << "5. " << boost::core::demangle(typeid(aSharedPtrAnyClass).name()) << " ( " << aSharedPtrAnyClass.use_count() << " ) " << '\n';
        // cout << "5. " << cxx::demangle(typeid(aSharedPtrAnyClass).name()) << " ( " << aSharedPtrAnyClass.use_count() << " ) " << '\n';
      }
      cout << "6. " << boost::core::demangle(typeid(newSharedPointerAnyClass).name()) << " ( " << newSharedPointerAnyClass.use_count() << " ) " << '\n';
      // cout << "6. " << cxx::demangle(typeid(newSharedPointerAnyClass).name()) << " ( " << newSharedPointerAnyClass.use_count() << " ) " << '\n';

      auto sharedFromWeak1 = aWeakPtrAnyClass.lock();
      cout << "boost::core::demangle ( typeid ( sharedFromWeak1 ) .name () ) ... " << boost::core::demangle(typeid(sharedFromWeak1).name()) << '\n';
      cout << "7. " << boost::core::demangle(typeid(sharedFromWeak1).name()) << " ( " << sharedFromWeak1.use_count() << " ) " << '\n';
      // cout << "cxx::demangle ( typeid ( sharedFromWeak1 ) .name () ) ... " << cxx::demangle(typeid(sharedFromWeak1).name()) << '\n';
      // cout << "7. " << cxx::demangle(typeid(sharedFromWeak1).name()) << " ( " << sharedFromWeak1.use_count() << " ) " << '\n';
      // std::shared_ptr<AnyClass>
      if (sharedFromWeak1)
      {
        cout << "8. Key Of Weak1: " << sharedFromWeak1->GetKey() << " ( " << sharedFromWeak1.use_count() << " ) " << '\n';
      }
    } // aSharedPtrAnyClass, newSharedPointerAnyClass, sharedFromWeak1 all gone
  }

  auto sharedFromWeak2 = aWeakPtrAnyClass.lock();
  cout << "boost::core::demangle ( typeid ( sharedFromWeak2 ) .name () ) ... " << boost::core::demangle(typeid(sharedFromWeak2).name()) << '\n';
  cout << "9. " << boost::core::demangle(typeid(sharedFromWeak2).name()) << " ( " << sharedFromWeak2.use_count() << " ) " << '\n';
  // cout << "cxx::demangle ( typeid ( sharedFromWeak2 ) .name () ) ... " << cxx::demangle(typeid(sharedFromWeak2).name()) << '\n';
  // cout << "9. " << cxx::demangle(typeid(sharedFromWeak2).name()) << " ( " << sharedFromWeak2.use_count() << " ) " << '\n';
  // std::shared_ptr<AnyClass>
  if (!sharedFromWeak2)
  {
    cout << "Shared Pointer Out Of Scope!" << '\n';
  }

  cout << endl;

  return 0;
}

/*

Using a --- weak pointer ---

Modern C++ also allows you to hold --- weak references --- to smart pointers.

This allows you to get a reference to a pointer to a shared object temporarily
while you need it for as long as the shared object exists.

This Listing 2-36 shows how you can achieve this using a weak_ptr.

The shared_ptr in Listing 2-35 is different to the unique_ptr 
that you have seen before. 


*/
