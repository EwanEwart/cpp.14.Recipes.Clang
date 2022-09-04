#include <iostream>

using namespace std;

template <typename T>
T Add(T const& a, T const& b)
{
    return a + b; // operator+(...) needed
}

template <typename T>
void Print
(
    T const& value1,
    T const& value2,
    T const& result
)
{
    cout << value1 << " + " << value2 << " = " << result << endl; // operator<< needed
}

struct Point
{
    int x, y, z;
    Point() :x{}, y{}, z{} {}
    Point(int x, int y, int z) :x{ x }, y{ y }, z{ z } {}

    /*
    compound assignment
    does not need to be a member,
    but often is,
    to modify the private members
    */
    Point& operator+=(Point const& rhs) // operator+(...) assumed for Add template
    {
        /* addition of rhs to *this takes place here */
        this->x += rhs.x;
        this->y += rhs.y;
        this->z += rhs.z;
        return *this; // return the result by reference
    }
    /*
    passing lhs by value helps optimize chained a+b+c
    otherwise, both parameters may be const references
    */
    friend Point operator+(Point lhs, Point const& rhs) // operator+(...) assumed for Add template
    {
        lhs += rhs; // reuse compound assignment
        return lhs; // return the result by value (uses move constructor)
    }
    friend ostream& operator<<(ostream& os, Point const& point) // operator<<(...) assumed for Print template
    {
        os << "(" << point.x << ", " << point.y << ", " << point.z << ")" << endl;
        return os;
    }
};


// #define INTS
// #define FLOATS
#define POINTS

int main(int argc, char* argv[])
{
#if defined(INTS)
    auto const data1{ 3 };
    auto const data2{ 2 };
#elif defined(FLOATS)
    auto const data1{ 1.2f };
    auto const data2{ 1.2f };
#elif defined(POINTS)
    auto const data1{ Point{1,2,3} };
    auto const data2{ Point{6,5,4} };
#endif
    auto const intResult{ Add(data1, data2) };
    Print(data1, data2, intResult);

    Point p1{ 7,8,9 };
    Point p2{};
    p2 = p1;
    cout << "p1 == " << p1;
    cout << "p2 == " << p2;

    return 0;
}
