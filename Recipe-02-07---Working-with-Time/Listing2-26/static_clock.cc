/*
 *
 * Getting the current Date and Time
 *
 */

#include <iostream>
#include <chrono>
#include <typeinfo> // typeid
#include <ctime>
#include <boost/core/demangle.hpp>

using namespace std ;
using namespace chrono ;
using boost::core::demangle ;

string pit_to_str
(
    system_clock::time_point const& pit
  , bool const local = true
)
{
  // pit to string
  time_t tt = system_clock::to_time_t ( pit ) ;  // seconds since epoch
  string st = asctime ( local ? localtime ( &tt ) : gmtime ( &tt ) ) ; // string st2 = ctime( &tt ) ;
  // pit to string

  return st ;
}

int main ()
{

  // epoch
  system_clock::time_point epoch ;
  // epoch

  // read the real-time clock
  // system_clock::time_point pit = system_clock::now() ; // point in time : pit
  auto pit { system_clock::now () } ; // point in time : pit
  cout << "typeid ( pit ) .name () ... \n" << demangle ( typeid ( pit ) .name () ) << endl ;
  // read the real-time clock


  // output clock characteristics
  cout << endl ;
  cout << "-----------   resolution  -----" << endl ;
  cout << "system-clock tick-period   ... " << double ( system_clock::period::num ) / system_clock::period::den << endl ;
  cout << "system-clock tick-period   ... " << "ratio ( " << system_clock::period::num << ", " << system_clock::period::den << " )" << endl ;

  cout << endl ;
  cout << "-----------   local    ---------" << endl ;
  cout << "system-clock epoch          ... " << pit_to_str ( epoch ) << endl ;
  cout << "point-in-time range minimum ... " << pit_to_str ( pit.min() ) << endl ;
  cout << "system-clock now            ... " << pit_to_str ( pit ) << endl ;
  cout << "point-in-time range maximum ... " << pit_to_str ( pit.max() ) << endl ;

  cout << endl ;
  cout << "-----------   GMT     ---------" << endl ;
  cout << "system-clock epoch          ... " << pit_to_str( epoch    , false ) << endl ;
  cout << "point-in-time range minimum ... " << pit_to_str( pit.min(), false ) << endl ;
  cout << "system-clock now            ... " << pit_to_str( pit      , false ) << endl ;
  cout << "point-in-time range maximum ... " << pit_to_str( pit.max(), false ) << endl ;
  cout << "-------------------------------" << endl ;
  cout << endl ;
  // output clock characteristics

  return 0 ;
}
