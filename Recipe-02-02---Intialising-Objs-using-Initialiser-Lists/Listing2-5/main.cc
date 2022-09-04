/*
Constructing vector Objects
*/
#include <iostream>
#include <vector>

using namespace std ;

int main ()
{
    using XVector = vector<int> ;

    // implicitly initialised vector
    XVector vectorA (  /*no. of elements*/ 1  ) ;
    cout
      << "size ... "
      << vectorA.size ()
      << ", capacity ... "
      << vectorA.capacity ()
      << ", value ... "
      << vectorA [0]
      << endl
    ;
    // explicitly initialised vector
    XVector vectorB ( /*no. of elements*/  5, /*value*/ 10  ) ;
    cout
      << "size ... "
      << vectorB.size ()
      << ", capacity ... "
      << vectorB.capacity ()
      << ", value ... "
      << vectorB [0]
      << endl ;

    cout << "values ... ";
    for ( auto item : vectorB )
      cout << item << ", " ;
    cout << endl ;

    return 0 ;
}
