#include <cinttypes>
#include <iostream>
#include <vector>

using namespace std;

int main(int arcg, char* argv[])
{
    using IntVector = vector<int32_t>;
    using IntVectorIterator = IntVector::iterator;

    IntVector intVector(5, 0); // ctor initialisation : five zeros: 0 0 0 0 0
    int32_t zero{ 0 };

    for (IntVectorIterator iter{ intVector.begin() }; iter != intVector.end(); ++iter)
    {
        cout << *iter << ' ';
    }   cout << endl;

    for (IntVectorIterator iter{ intVector.begin() }; iter != intVector.end(); ++iter)
    {
        *iter = ++zero;
    }

    for (IntVectorIterator iter{ intVector.begin() }; iter != intVector.end(); ++iter)
    {
        cout << *iter << ' ';
    }   cout << endl;

    return 0;
}
