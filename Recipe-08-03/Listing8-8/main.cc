/*
Using std::min_element in conjunction with a class that contains an operato<()
*/

#include <iostream>

#include <vector>
#include <algorithm> // min_element, max_element

using std::cout;
using std::endl;
using std::vector;
using std::min_element;
using std::max_element;

// the min_element algorithm

class ComparableClass
{
private:
  int m_Value;

public:
  ComparableClass(int const value)
    : m_Value{ value }
  {

  }

  int getValue() const
  {
    return m_Value;
  }

  // binary predicate
  bool operator< (ComparableClass const& rhs) const
  {
    return m_Value < rhs.m_Value;
  }
};

int main(int ac, char* av[])
{
  vector<ComparableClass> vectorComparableClass{ -44, -10, 6, 7, -9, 17, 1 };

  auto minimum_range_01 = min_element(vectorComparableClass.begin()+0, vectorComparableClass.end());
  auto minimum_range_02 = min_element(vectorComparableClass.begin()+1, vectorComparableClass.end());
  auto minimum_range_03 = min_element(vectorComparableClass.begin()+2, vectorComparableClass.end());

  if 
  (
    (minimum_range_01 != vectorComparableClass.end())
    &&
    (minimum_range_02 != vectorComparableClass.end())
    &&
    (minimum_range_03 != vectorComparableClass.end())
  )
  {
    cout << "Minimum value: " << (*minimum_range_01).getValue() << endl;
    cout << "Minimum value: " << (*minimum_range_02).getValue() << endl;
    cout << "Minimum value: " << (*minimum_range_03).getValue() << endl;
  }

  return 0;
}
