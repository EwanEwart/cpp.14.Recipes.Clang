#include <iostream>

using namespace std;

// the more types the template is used with, 
// the more overloads of Add will be generated
template <typename T>
T Div(T const& a, T const& b)
{
    return a + b;
}

int main(int argc, char* argv[])
{
    // generates int overload of Add
    auto const int1{ 1 };
    auto const int2{ 2 };
    auto const resultInt{ Div(int1, int2) };
    cout << "ints ... " << int1 << " + " << int2 << " = " << resultInt << endl;

    // generates float overload of Add
    auto const float1{ 1.15f };
    auto const float2{ 2.20f };
    auto const resultFloat{ Div(float1, float2) };
    cout << "floats ... " << float1 << " + " << float2 << " = " << resultFloat << endl;

    return 0;
}
