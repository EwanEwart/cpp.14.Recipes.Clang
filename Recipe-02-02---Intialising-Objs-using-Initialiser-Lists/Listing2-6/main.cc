/*
Using Uniform Initialisation to Construct a vector
*/
#include <iostream>
#include <vector>

using namespace std ;

int main ()
 {
    using XVector = vector<int> ;

    // using ctor
    XVector vectorA ( /*no. of values*/  1  ) ;
    cout << "size ... " << vectorA.size () << ", value ... " << vectorA [ 0 ] << endl ;

    // using ctor
    XVector vectorB ( /*no. of values*/ 5, /*value no. 1*/ 10  ) ;
    cout << "size ... " << vectorB.size () << ", value ... " << vectorB [ 0 ] << endl ;

    // using uniform initialisation
    // specifying values, implicitly specfies size
    //
    XVector vectorC { /*value no. 1*/ 1, /*value no. 2*/ 10  } ;

    cout
      << "size ... "
      << vectorC.size ()
      << ", 1. value ... " << vectorC [ 0 ]
      << ", 2. value ... " << vectorC [ 1 ]
      << endl ;

    for ( auto value : vectorC )
      cout << "size ... " << vectorC.size () << ", value ... " << value << endl ;

    return 0 ;
 }
