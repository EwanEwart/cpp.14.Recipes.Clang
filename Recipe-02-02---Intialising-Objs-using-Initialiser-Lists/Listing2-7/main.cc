#include <iostream>
#include <vector>

using namespace std ;

int main ()
{
  using XVector = vector<int> ;

  // one-element vector, default-initialised to 0
  cout << "\n1. ..." << endl ;
  XVector vectorA (  1  ) ;
  cout << vectorA.size () << ", " << vectorA [ 0 ] << endl ;

  // one-element vector, initialised to 10
  cout << "\n2. ..." << endl ;
  XVector vectorB (  1, 10  ) ;
  cout << vectorB.size () << ", " << vectorB [ 0 ] << endl ;

  // initialiser list initialisation
  cout << "\n3. ..." << endl ;
  initializer_list<int> initList { 1, 10 } ;
  XVector vectorC ( initList ) ;
  cout << vectorC.size () << ", " ;
  for ( auto item : vectorC )
    cout << '\t' << item << '\n' ;
  cout << endl ;

  // playing whith il
  cout << "\n4. ..." << endl ;
  initializer_list<int> ott { 1,2,3,4,5,6,7,8,9,10 } ;
  for ( auto k : ott )
    cout << k*7 << ", " ;
  cout << endl ;

  // playing with ii
  cout << "\n5. ..." << endl ;
  for ( auto k : { 1,2,3,4,5,6,7,8,9,10,11 })
    cout << k*49 << ", " ;
  cout << endl ;

  // filling a vector
  cout << "\n6. ..." << endl ;;
  std::vector<long> v;
  for ( auto k : { 1,2,3,4,5,6,7,8,9,10,11 } )
    v.push_back (k*13) ;
  for ( auto k : v)
    cout << k << ", " ;
  cout << endl ;

  return 0 ;
}
