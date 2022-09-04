#include <iostream>

using namespace std;

// a templatised fixed sized array (with partially implemented iterator)

template <typename T, int numberOfElements>
class FixedSizedArray
{
private:
    T m_Array[numberOfElements];

public:
    FixedSizedArray() : m_Array{} { }

    T& operator[](unsigned const int index)
    {
        return m_Array[index];
    }
    // iterator
    using iterator = T*;
    iterator begin() { return &m_Array[0]; }
    iterator end() { return &m_Array[numberOfElements]; }
};

int main(int argc, char* argv[])
{
    unsigned int const ARRAY_SIZE{ 5 };
    FixedSizedArray<int, ARRAY_SIZE> fixedSizedArrayInt;
    for (unsigned int i{ 0 }; i < ARRAY_SIZE; ++i)
    {
        fixedSizedArrayInt[i] = i + 1;
    }
    // standard loop
    for (unsigned int i{ 0 }; i < ARRAY_SIZE; ++i)
    {
        cout << fixedSizedArrayInt[i] << ' ';
    }   cout << endl;
    // using custom iterator
    for (auto i : fixedSizedArrayInt)
    {
        cout << i << ' ';
    }   cout << endl;
    FixedSizedArray<float, ARRAY_SIZE> fixedSizedArrayFloat;
    for (unsigned int i{ 0 }; i < ARRAY_SIZE; ++i)
    {
        fixedSizedArrayFloat[i] = static_cast<float>(i) + 0.5f;
    }
    // standard loop
    for (unsigned int i{ 0 }; i < ARRAY_SIZE; ++i)
    {
        cout << fixedSizedArrayFloat[i] << ' ';
    }   cout << endl;
    // using custom iterator
    for (auto i : fixedSizedArrayFloat)
    {
        cout << i << ' ';
    }   cout << endl;

    return 0;
}
