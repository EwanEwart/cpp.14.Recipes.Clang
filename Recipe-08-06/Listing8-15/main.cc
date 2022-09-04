#include <iostream>
#include <vector>
#include <algorithm> // sort

using namespace std;

bool isGreater(int lhs, int rhs)
{
    return lhs > rhs;
}

int main(int argc, char* argv[])
{
    vector<int> container_int{ -1, 0, 1, 2, 3, 4, 5 };

    // sort in descending order
    sort
    (
        container_int.begin(),
        container_int.end(),
        isGreater
    );

    // forward / universal reference
    for (auto&& element : container_int)
    {
        cout << element << ", ";
    }   cout << endl;

    return 0;
}
