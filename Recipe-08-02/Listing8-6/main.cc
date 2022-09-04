#include <iostream>
#include <cinttypes>
#include <vector>
#include <algorithm> // for_each 

using namespace std;

int main(int argc, char* argv[])
{
    vector<int32_t> intVector_1{ 1, 2, 3, 4, 5,6,7,8,9,10 };
    vector<int32_t> intVector_2{ 11,12, 13, 14,15,16,17,18,19 };
    for (auto i : intVector_2)
    {
        for_each
        (
            intVector_1.begin(), 
            intVector_1.end(), 
            [i](int32_t value) { cout << value * i << ' '; }
        ); 
        cout << endl;
    }
    return 0;
}
