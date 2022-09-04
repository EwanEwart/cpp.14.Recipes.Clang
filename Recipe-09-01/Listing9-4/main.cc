#include <iostream>

using namespace std;

template <typename T>
T Div(T const& a, T const& b)
{
    return a / b;
}

template <typename T>
void Print
(
    T const& value1,
    T const& value2,
    T const& result
)
{
    cout << value1 << " / " << value2 << " = " << result << endl;
}

int main(int argc, char* argv[])
{
    auto const int1{ 1 };
    auto const int2{ 2 };
    auto const resultInts{ Div(int1, int2) };
    Print(int1, int2, resultInts);

    auto const resultFloat{ Div(static_cast<float>(int1), static_cast<float>(int2)) };
    // Print(int1, int2, resultFloat); // signature mismatch: won't compile
    Print<float>(int1, int2, resultFloat);

    return 0;
}
