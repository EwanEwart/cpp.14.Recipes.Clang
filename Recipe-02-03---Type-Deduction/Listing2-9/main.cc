/*
Using auto with a class
*/
#include <iostream>
#include <typeinfo>
#include <vector>
#include <boost/core/demangle.hpp>

using namespace std ;

using boost::core::demangle ;

class XClassA {} ;
class XClassB {} ;
class XClassC {} ;
class XClassD {} ;

int main ()
{
  auto var1 = XClassA () ;
  cout << "1. -> Type of variable: " << demangle ( typeid ( var1 ) .name () ) << endl ;

  auto var2 { XClassB {} } ;
  cout << "2. -> Type of variable: " << demangle ( typeid ( var2 ) .name () ) << endl ;

  vector<XClassC> var3 { XClassC {}, XClassC {}, XClassC {} } ;
  cout << "3. -> Type of variable: " << demangle ( typeid ( var3 ) .name () ) << endl ;

  initializer_list<XClassD> il { XClassD {}, XClassD {}, XClassD {} } ;
  cout << "4. -> Type of variable: " << demangle ( typeid ( il ) .name () ) << endl ;

  vector<XClassD> var4 { il } ;
  cout << "5. -> Type of variable: " << demangle ( typeid ( var4 ) .name () ) << endl ;

  return 0 ;
}
