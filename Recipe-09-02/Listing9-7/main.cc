#include <iostream>

using namespace std;

/*
IntClass doesn't support: operator+(...) and operator<<
Therfore not suitable for template Add that expects these operators
Solution here: Template Specialisation
*/
class IntClass
{
private:
    int m_int{ 0 };

public:
    IntClass() = default;
    IntClass(int int1) : m_int{ int1 } { }
    IntClass(int int1, int int2) : m_int{ int1 + int2 } { }
    int GetValue() const { return m_int; }
};

// template function ADD
template <typename T>
T Add(T const& a, T const& b)
{
    return a + b;
}

template <>
IntClass Add(IntClass const& intClass1, IntClass const& intClass2)
{
    return IntClass(intClass1.GetValue(), intClass2.GetValue());
}

template <typename T>
void Print(T const& value1, T const& value2, T const& result)
{
    cout << value1 << " + " << value2 << " = " << result << endl; // operator<< needed
}

template <>
void Print(const IntClass& sampleClass1, const IntClass& sampleClass2, const IntClass& sampleClassResult)
{
    cout << "SampleClass: " << sampleClass1.GetValue() << " + " << sampleClass2.GetValue() << " = " << sampleClassResult.GetValue() << endl; // operator<< needed
}

int main(int argc, char* argv[])
{
    // SampleClass doesn't have: + <<
    IntClass const sampleClass1{ 1 };
    IntClass const sampleClass2{ 2 };
    IntClass const sampleClassResult{ Add(sampleClass1, sampleClass2) };
    Print(sampleClass1, sampleClass2, sampleClassResult);

    // int has: + <<
    auto const int1{ 3 };
    auto const int2{ 4 };
    auto const intResult{ Add(int1, int2) };
    Print(int1, int2, intResult);

    return 0;
}
