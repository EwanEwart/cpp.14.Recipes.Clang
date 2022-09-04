#!/bin/sh

md5=$( (md5 -q || md5sum -b) < $0 2>/dev/null | cut -d ' ' -f1)
script="/tmp/`uuid`"
script="/tmp/$(basename $0).${md5}"
cxx="g++ -std=c++17 -pipe -Wall"
cxx="clang++ -std=c++17 -pipe -Wall"
more_sources=""
linker="-lpthread"
include="$BOOST_ROOT"
[ -e "${script}" ] || ${cxx} -x c++ -I${include} -o ${script} - <<INLINE ${more_sources} ${linker} && exec ${script} $@

/*
First test C++XX compatibility

    g++ -std=c++17 -pipe -O2 -Wall -W -fPIC  -I. -I$BOOST_ROOT Listing1-1.cc

clang++ -std=c++17 -pipe -O2 -Wall -W -fPIC  -I. -I$BOOST_ROOT Listing1-1.cc

*/

#include <iostream>
using std::cout ;
using std::endl ;

#include <typeinfo> // typeid
#include <boost/core/demangle.hpp>
using boost::core::demangle ;

/*
  Does the compiler support c++11 ?
  Does the compiler support c++14 ?
  Does the compiler support c++17 ?
*/

/*
http://en.cppreference.com/w/cpp/string/basic_string/operator%22%22s
*/
using std::literals::string_literals::operator"" s ; // since c++14, <string>

/*
  string literals namespace access possibilities ...
*/
// using namespace std::literals ;
// using namespace std::literals::string_literals ;
// using namespace std::string_literals ; // since c++14

int main(void) {

#if 200400L < __cplusplus && __cplusplus < 201200L
  cout << "c++11 !" << '\n';
#elif 201400L <= __cplusplus && __cplusplus < 201700L
  cout << "c++14 !" << '\n';
#elif 201700L <= __cplusplus && __cplusplus < 202000L
  cout << "c++17 !" << '\n';
#else
  cout << "__cplusplus ... " << __cplusplus << endl;
#endif

  auto output = "Greetings, Rachel !"s; // since c++14, <string>
  cout << "demangle(typeid ( output ) .name ()) ... \n"
    << demangle(typeid(output).name())
    << endl;
  /* output ...
  auto -> std::__cxx11::basic_string<char, std::char_traits<char>,
  std::allocator<char> >
  */

  cout << output << endl;


  cout << 0b101101101 << endl;
  return 0;
}

INLINE
