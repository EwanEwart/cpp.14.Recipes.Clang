#include <iostream>
#include <vector>
#include <algorithm> // sort

using namespace std;

int main(int argc, char* argv[])
{
    vector<int> vector_Int{ 10, 6, 4, 7, 8, 3, 9 };

    // sort in ascending order
    sort
    (
        vector_Int.begin(), 
        vector_Int.end()
    );
    // universal / forwarding reference
    for (auto&& element : vector_Int)
    {
        cout << element << ", ";
    }

    cout << endl;

    return 0;
}
