#include <iostream>
#include <typeinfo>
#include <boost/core/demangle.hpp>

using namespace std ;

using boost::core::demangle ;

class XClass
{
} ;

int main()
{
    auto variable { 1 } ;
    cout << "Type of variable: " << demangle ( typeid ( variable ) .name () ) << endl ;

    auto variable2 { XClass {} } ;
    cout << "Type of variable: " << demangle ( typeid ( variable2 ) .name () ) << endl ;

    return 0 ;
}
