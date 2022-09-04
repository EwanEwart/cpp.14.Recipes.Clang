#include <iostream>
#include <vector>
#include <algorithm> // min_element
#include <cstdio>

using std::cout;
using std::endl;
using std::vector;
using std::min_element;

class XClass
{
private:
  int m_Value;

public:
  XClass(int const value)
    : m_Value{ value }
  {
  }

  int getValue()  const
  {
    return m_Value;
  }
};

// binary predicate
bool compareXClasses(XClass const& lhs, XClass const& rhs)
{
  return lhs.getValue() < rhs.getValue();
}

int main(int argc, char* argv[])
{
  vector<XClass> vXclass{ 4, 10, 6, -9, 1 };

  auto minimum = min_element(vXclass.begin(), vXclass.end(), compareXClasses);
  if (minimum != vXclass.end())
  {
    cout << "1. Minimum value: " << (*minimum).getValue() << endl;
  }

  // a lambda predicate
  auto minimum2 = min_element
  (
    vXclass.begin(),
    vXclass.end(),
    [](XClass const& lhs, XClass const& rhs) {return lhs.getValue() < rhs.getValue();} // lambda
  );
  if (minimum != vXclass.end())
  {
    cout << "2. Minimum value: " << (*minimum2).getValue() << endl;
  }

  return 0;
}
