/*
Return Type Deduction in C++11
*/
#include <iostream>
#include <typeinfo>
#include <boost/core/demangle.hpp>

using namespace std ;
using boost::core::demangle ;

auto AutoFunctionFromReturn ( float parameter ) -> float // c++11
{
    return parameter ;
}

int main ()
{
    auto value = AutoFunctionFromReturn ( 1001.4711 ) ;
    cout << "typeid ( value ) .name () ... " << demangle ( typeid ( value ) .name () ) << '\n' ;
    cout << "value ... " << value << '\n' ;

    cout << endl ;

    return 0 ;
}
