#include <ctime>
#include <chrono>
#include <iostream>
#include <thread>

using namespace std ;
using namespace chrono ;
using namespace literals ;

int main ()
{
  auto startTimePoint = system_clock::now () ;

  this_thread::sleep_for ( 2s ) ;

  auto endTimePoint = system_clock::now () ;

  auto timeTaken_ms = duration_cast<milliseconds> ( endTimePoint - startTimePoint ) ;
  auto timeTaken_us = duration_cast<microseconds> ( endTimePoint - startTimePoint ) ;
  auto timeTaken_ns = duration_cast<nanoseconds> ( endTimePoint - startTimePoint ) ;

  cout << "Time taken should be 2s ... " << timeTaken_ms.count () << " ms."  << endl ;
  cout << "Time taken should be 2s ... " << timeTaken_us.count () << " us."  << endl ;
  cout << "Time taken should be 2s ... " << timeTaken_ns.count () << " ns."  << endl ;

  return 0 ;
}
