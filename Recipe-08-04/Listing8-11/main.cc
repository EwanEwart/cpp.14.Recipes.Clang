#include <iostream>
#include <iomanip>
#include <algorithm> // count
#include <vector>
#include <typeinfo> // typeid

using namespace std;

// sum: recursion terminator
template <typename T>
T sum(T const& t1)
{
    return t1;
}
// sum: recursion, chosen for more than one arg
template<typename T1, typename ... TN>
auto sum(T1 const& t1, TN ... tn)
{
    return t1 + sum(tn...);
}

int main(int argc, char* argv[])
{
    vector<int> container{ 3, 2, 3, 7, 3, 8, 9, 3 };

    // found how often
    auto cnt =
        count
        (
            /* from:            */ container.begin() + 1,
            /* to:              */ container.end(),
            /* value to find    */ 3
        ); // count algorithm

    cout << "The number of 3s in " << typeid(container).name() << " is: " << cnt << endl;

    cout << "sum ->" << sum(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) << endl;

    int true_bool{ 1 };
    int false_bool{ 0 };
    cout << boolalpha << true_bool << ' ' << false_bool << endl;
    cout << boolalpha << true_bool << ' ' << false_bool << endl;
    cout << boolalpha << static_cast<bool>(true_bool) << ' ' << static_cast<bool>(false_bool) << endl;
    cout << boolalpha << static_cast<bool>(true_bool) << ' ' << static_cast<bool>(false_bool) << endl;

    return 0;
}
