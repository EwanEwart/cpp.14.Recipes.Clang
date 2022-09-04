#include <iostream>

using namespace std;

class IntClass
{
    friend ostream& operator <<(ostream& os, const IntClass& intClass);

private:
    int m_Int{ 0 };

public:
    IntClass() = default;
    IntClass(int int1) : m_Int{ int1 } { }
    IntClass(int int1, int int2) : m_Int{ int1 + int2 } { }

    // for completness
    IntClass operator+(IntClass const& other) const
    {
        return m_Int + other.m_Int;
    }
};

// for completness
ostream& operator <<(ostream& os, IntClass const& intClass)
{
    os << intClass.m_Int;
    return os;
}

template <typename T>
T Add(T const& a, T const& b)
{
    return a + b;
}

template <typename T>
void Print
(
    T const& value1,
    T const& value2,
    T const& result
)
{
    cout << value1 << " + " << value2 << " = " << result << endl; // operator<< for completness
}

int main(int argc, char* argv[])
{
    IntClass const intClass1{ 1 };
    IntClass const intClass2{ 2 };
    IntClass const intClassResult{ Add(intClass1, intClass2) };
    Print(intClass1, intClass2, intClassResult);

    return 0;
}
