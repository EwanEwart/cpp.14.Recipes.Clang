#include <iostream>

using namespace std;

class IntClass
{
private:
    int m_int{ 0 };

public:
    IntClass() = default;

    IntClass(int value)
        : m_int{ value }
    {

    }

    IntClass(int number1, int number2)
        : m_int{ number1 + number2 }
    {

    }

    int GetValue() const
    {
        return m_int;
    }
};

template <typename T>
T Add( T const& a,  T const& b)
{
    return a + b; // operator+(...) needed for SampleClass
}

template <typename T>
void Print
( 
    T const& value1,
    T const& value2,
    T const& result
)
{
    cout << value1 << " + " << value2 << " = " << result << endl; // operator<< needed for SampleClass
}

int main(int argc, char* argv[])
{
    IntClass const sampleClass1{ 1 };
    IntClass const sampleClass2{ 2 };
    IntClass const sampleClass{ Add(sampleClass1, sampleClass2) };
    Print(sampleClass1, sampleClass2, sampleClass);

    return 0;
}
