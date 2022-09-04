#include <cinttypes>
#include <iostream>
#include <vector>

using namespace std;

int main(int arcg, char* argv[])
{
    using IntVector = vector<int32_t>;

    using IntVectorIterator = IntVector::iterator;
    using IntVectorConstIterator = IntVector::const_iterator;

    using IntVectorReverseIterator = IntVector::reverse_iterator;
    using IntVectorConstReverseIterator = IntVector::const_reverse_iterator;

    // reverse Iterator

    IntVector intVector(5, 0); // ctor initialisation : 5 zeros : 0 0 0 0 0
    int32_t zero{ 0 };

    // reverse iterator
    for (IntVectorReverseIterator iter = intVector.rbegin(); iter != intVector.rend(); ++iter)
    {
        *iter = ++zero;
    }

    // forward iterator
    for (IntVectorConstIterator iter = intVector.cbegin(); iter != intVector.cend(); ++iter)
    {
        cout << *iter << ' ';
    }   cout << endl;

    return 0;
}
