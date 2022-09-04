#include <iostream>
#include <vector>
#include <memory>
#include <iomanip>
#include <type_traits>

using namespace std;

// Calc overloads: type dependent operations
int Calc(int a, int b) { return a + b; } // addition
float Calc(float a, float b) { return a*b; } // multiplication
double Calc(double a, double b) { return a/b; } // division


// Any type that works for cout
template<typename T>
void print(int id,  std::vector<T> const& container)
{
    std::cout << id << ". ";
    for ( T const x : container) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}

int main(int argc, char* argv[])
{
    // data addition
    auto const int1{ 1 };
    auto const int2{ 2 };
    auto const resultAdd{ Calc(int1, int2) };
    // data division
    auto double1(3.1415);
    auto double2{2.17};
    auto const resultDiv{ Calc(double1, double2) };
    // data multiplication
    auto float1(3.1415f);
    auto float2{2.17f};
    auto const resultMul{ Calc(float1, float2) };

    // using Calc int
    cout << "ints ... " << int1 << " + " << int2 << " = " << resultAdd  << endl;
    // using Calc double
    cout << "doubles ... " << double1 << " / " << double2 << " = " << resultDiv  << endl;
    // using Calc float
    cout << "floats ... " << float1 << " * " << float2 << " = " << resultMul  << endl;

    // lambdas
    auto la = [](auto n1, auto n2) {return n1 + n2;}; // EE
    // lambda variable
    cout << "la1: " << la(int1, int2) << endl;
    // lambda on the fly
    cout << "la2: " << ([](auto n1, auto n2) {return n1 + n2;})(int1, int2) << endl;

    // union
    vector <int>v1{ 1,2,3,4 };
    vector <int>v2{ 1,2,3,4 };
    vector <int>v3{ 5,6,7,8 };
    vector <int>v4{ 9,10,11,12 };
    vector <string>vs1{ "a","b","c" };
    vector <string>vs2{ "d","e","f" };
    vector <string>vs3{ "g","h","i" };
    vector <int> v10{};
    vector <shared_ptr<int>> vip01(3, nullptr);
    vector <shared_ptr<int>> vip02(3, nullptr);

    cout << "v1 empty -> " << boolalpha << v1.empty() << endl;
    ///////////////
    v10 = move(v1);
    ///////////////
    cout << "v1 empty -> " << boolalpha << v1.empty() << endl;
    cout << "len v10 == " << v10.size() << endl;
    cout << "len v1  == " << v10.size() << endl;
    print(1, v10);
    print(2, v1);

    // append w/o move
    v2.insert(v2.end(), v3.begin(), v3.end());
    print(3, v2);
    print(4, v3);

    // won't move integral types: int etc ...
    // v2.insert(v2.end(), move(v3[0]));
    // v2.emplace(v2.end(), move(v3[0]));
    v2.emplace(v2.end(), v3[0]);
    print(5, v2);
    print(6, v3);

    // will move other types: string etc ...
    for (size_t i = 0; i < vs2.size(); ++i)
    {
        // vs1.insert(vs1.end(), move(vs2[i]));
        vs1.emplace(vs1.end(), move(vs2[i]));
        // vs1.emplace(vs1.end(), vs2[i]);
    }
    print(7, vs1);
    print(8, vs2);

    // string: moved
    vs1.insert
    (
        vs1.end()
        , std::make_move_iterator(vs3.begin())
        , std::make_move_iterator(vs3.end())
    );
    print(9, vs1);
    print(10, vs3);

    // integral: not moved
    v3.insert
    (
        v3.end()
        , std::make_move_iterator(v4.begin())
        , std::make_move_iterator(v4.end())
    );
    print(11, v3);
    print(12, v4);

    print(13, vip01);
    for (size_t i = 0; i < vip01.size(); ++i)
    {
        vip01[i] = make_shared<int>(i + 1);
        vip02[i] = make_shared<int>(i + 1 + 3);
    }
    print(14, vip01);
    for (auto p : vip01) {
        cout << *p << ' ';
    }cout << '\n';
    for (auto p : vip02) {
        cout << *p << ' ';
    }cout << '\n';

    // integral ptr: moved
    print(15, vip02);
    vip01.insert
    (
        vip01.end()
        , std::make_move_iterator(vip02.begin())
        , std::make_move_iterator(vip02.end())
    );
    print(16, vip01);
    print(17, vip02);

    wstring X{ L"abc" };
    wstring Y{ L"def" };
    X = Y;
    wcout << L"X: " << X << endl;

    // loops
    for 
    (
        size_t i = 0, j = 0, q = 0; 
        i < 3 && j < 10 && q < 15; 
        q++, j++, i++
    )
    {
        cout << i << ' ' << j << ' ' << q << endl;
    }

    cout << "is_move_assignable<int>::value ->" <<  is_move_assignable<int>::value << endl;
    cout << "is_nothrow_move_assignable<std::int>::value ->" <<  is_nothrow_move_assignable<int>::value << endl;
    cout << "is_trivially_move_assignable<int>::value ->" <<  is_trivially_move_assignable<int>::value << endl;
    
    cout << "is_move_assignable<string>::value ->" <<  is_move_assignable<string>::value << endl;
    cout << "is_nothrow_move_assignable<std::string>::value ->" <<  is_nothrow_move_assignable<std::string>::value << endl;
    cout << "is_trivially_move_assignable<string>::value ->" <<  is_trivially_move_assignable<string>::value << endl;

    return 0;
}
