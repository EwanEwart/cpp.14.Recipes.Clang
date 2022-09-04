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

    IntVector intVector(5, 0); // ctor initialisation : 0 0 0 0 0 
    int32_t zero{ 0 };
    for (IntVectorIterator iter = intVector.begin(); iter != intVector.end(); ++iter)
    {
        *iter = ++zero;
    }

    for (IntVectorConstReverseIterator iter = intVector.crbegin(); iter != intVector.crend(); ++iter)
    {
        cout << *iter << ' ';
    }   cout << endl;

    return 0;
}
