#include <locale>

#include <iostream>
#include <array>
#include <string>

#include <boost/locale.hpp>

using std::cout ;
using std::endl ;
using std::string ;
using std::array ;

unsigned int SDBMHash ( string const & key )
{
  unsigned int result { 0 } ;

  for  ( unsigned int character : key )
  {
    result = character +  ( result << 6 ) +  ( result << 16 ) - result ; // the SDBM algorithm
  }

  return result ;
}

int main ( int argc, char* argv[] )
{
  // group digits
  std::locale loc { std::locale("") } ;
  cout.imbue ( loc ) ;

  unsigned short const  l { 3 } ; // no. of array elements
  // A std::array is a container that encapsulates fixed size arrays.
  array < string      , l >   data       { { "Bruce Sutherland", "Rachel Ewart", "Ewan Ewart" } } ; // parallel array of names
  array < unsigned int, l >   sdbmHash   { } ; // parallel array of hashes

  // generate hashes
  unsigned short k { 0 } ;
  for ( auto name : data )
    sdbmHash [ k++ ] = SDBMHash ( name ) ;

  // display hashes
  k = 0;
  for ( auto name : data)
    cout << '\n' << "The hash of " << name << " is " << sdbmHash [ k++ ] << '\n' ;
  cout << endl ;

  // A C-array has an iterator !!!
  int a [] {1,2,3,4,5,6,7,8,9,10,11} ;
  for (auto v:a)
    cout << v << ", " ;
  cout << endl ;

  return 0 ;
}
