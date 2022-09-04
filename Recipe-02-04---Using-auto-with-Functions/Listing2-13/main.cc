/*
Deducing return types for C++11 template functions
*/
#include <iostream>
#include <typeinfo>
#include <boost/core/demangle.hpp>

using namespace std ;
using boost::core::demangle ;

template <typename T>
auto AutoFunctionFromParameter ( T parameter ) -> decltype ( parameter )
{
    return parameter ;
}

int main ()
{
    auto value = AutoFunctionFromParameter ( 2002.2345f ) ;
    cout << "typeid (value) .name() ... " << demangle ( typeid (value) .name() ) << '\n' ;
    cout << "value ... " << value << '\n' ;

    cout << endl ;

    return 0 ;
}
