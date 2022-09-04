/*
Using the std::min_element algorithm
*/

#include <iostream>
#include <vector>
#include <algorithm> // min_element
#include <typeinfo> // typeid

using std::cout;
using std::endl;
using std::vector;
using std::min_element;
using std::max_element;

// The std::min_element algorithm

int main(int ac, char* av[])
{
  vector<int> int_vector{ 4, 10, 6, 9, 1 };

  // the returned integer pointer - iterator - will point to the minimum
  auto minimum = min_element(int_vector.begin(), int_vector.end()); // 1
  cout << "1. The minimum value of the integers is ... " << *minimum << endl;
  cout << "2. typeid (minimum).name () ) ... " << typeid (minimum).name() << endl;


  // another go at the algorithm using floats
  //
  vector<float> float_vector{ 1.1f, 2.2f, 3.3f, 4.4f, 5.5f, -1.1 }; // -1.1
  auto min_floats = min_element(float_vector.begin(), float_vector.end());
  cout << "3. The minimum value of the floats is ... " << *min_floats << endl;

  return 0;
}
