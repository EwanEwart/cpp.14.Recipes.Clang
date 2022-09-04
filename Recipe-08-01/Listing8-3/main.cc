#include <cinttypes>
#include <iostream>
#include <vector>

using namespace std;

// forward iterators

int main(int arcg, char* argv[])
{
    using IntVector = vector<int32_t>;
    using IntVectorIterator = IntVector::iterator;
    using IntVectorConstIterator = IntVector::const_iterator;

    IntVector intVector(5, 0); // ctor intialisation : 5 zeros : 0 0 0 0 0
    int32_t zero{ 0 };

    // .cbegin() .cend()
    for (IntVectorConstIterator iter{ intVector.cbegin() }; iter != intVector.cend(); ++iter)
    {
        cout << *iter << ' ';
    }   cout << endl;
    
    // .begin() .end()
    for (IntVectorIterator iter{ intVector.begin() }; iter != intVector.end(); ++iter)
    {
        *iter = ++zero; // 1 2 3 4 5
    }

    // .cbegin() .cend()
    for (IntVectorConstIterator iter{ intVector.cbegin() }; iter != intVector.cend(); ++iter)
    {
        cout << *iter << ' ';
    }   cout << endl;
    
    // .begin() .end() but IntVectorConstIterator
    for (IntVectorConstIterator iter{ intVector.begin() }; iter != intVector.end(); ++iter)
    {
        // v--- expression must be a modifiable l-value
        // *iter = ++zero; // 6 7 8 9 10
        cout << '-' << ' ';
    }   cout << endl;

    for (IntVectorConstIterator iter{ intVector.cbegin() }; iter != intVector.cend(); ++iter)
    {
        cout << *iter << ' ';
    }   cout << endl;

    return 0;
}
