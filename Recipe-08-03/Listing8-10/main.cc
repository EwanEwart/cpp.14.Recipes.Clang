#include <iostream>

#include <vector>
#include <algorithm> // max_element

using std::cout;
using std::endl;
using std::vector;
using std::max_element;


class XClass
{
private:
  int m_Value;

public:
  XClass(int const value)
    : m_Value{ value }
  {
  }

  int getValue() const
  {
    return m_Value;
  }

  // binary predicate
  bool operator< (XClass const& rhv) const
  {
    return m_Value < rhv.m_Value;
  }
};

// binary predicate
bool compareXClasses(XClass const& lhs, XClass const& rhs)
{
  return lhs.getValue() < rhs.getValue();
}

int main(int ac, char* av[])
{
  // .. v integers
  //
  vector<int> intVector{ 4, 10, 6, 9, 1 };

  auto int_maximum = max_element(intVector.begin(), intVector.end());
  if (int_maximum != intVector.end())
  {
    cout << "1. Maximum value ... " << *int_maximum << "\n\n";
  }

  // ... v XClass
  //
  vector<XClass> vector_XClass{ 4, 10, 6, 9, 1 };

  auto overwrite_operator_maximum = max_element(vector_XClass.begin(), vector_XClass.end());
  if (overwrite_operator_maximum != vector_XClass.end())
  {
    cout << "2. Maximum value ... " << (*overwrite_operator_maximum).getValue() << "\n\n";
  }

  auto function_comparison_maximum = max_element(vector_XClass.begin(), vector_XClass.end(), compareXClasses);
  if (function_comparison_maximum != vector_XClass.end())
  {
    cout << "3. Maximum value ... " << (*function_comparison_maximum).getValue() << "\n\n";
  }

  return 0;
}
