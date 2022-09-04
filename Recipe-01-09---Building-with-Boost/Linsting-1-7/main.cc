/*
Using boost::format
*/
#include <iostream>
#include <boost/format.hpp>

using std::cout ;
using std::cin ;
using std::endl ;
using std::string ;
using std::literals::string_literals::operator"" s ; // the string literal since c++14
// using namespace std::string_literals ; // the string literal since c++14
using boost::format ;

int main(int argc, char const *argv[])
{
  cout << "Enter your first name ... " ;
  string christian_name ;
  cin >> christian_name ;

  cout << "Enter your surname ... " ;
  string surname ;
  cin >> surname ;

  format greetings { "Good morning %1% %2%, on this sunny Sunday morning !" } ;
  auto greetings2 = str ( format ( "%1% %2%"s ) % christian_name % surname ) ;

  greetings % christian_name % surname ;

  cout << greetings << '\n' ;
  cout << greetings2 << endl ;

  return 0 ;
}

/*
$ /tmp/development/bin/c++14-recipes-clang/Recipe-01-09-Building-with-Boost/Linsting-1-7/clang-linux-3.8.0/debug/threading-multi/Linsting-1-7
Enter your first name ... Rachel
Enter your surname ... Ewart
Good morning Rachel Ewart, on this sunny Sunday morning !
Rachel Ewart
$
*/
