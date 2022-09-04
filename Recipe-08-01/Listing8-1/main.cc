#include <cinttypes>
#include <iostream>
#include <vector>

using namespace std;

// use of the standard forward iterator

int main(int arcg, char* argv[])
{
    // type alias
    using IntVector = vector<int32_t>;
    using IntVectorIterator = IntVector::iterator;

    IntVector intVector{ 0, 1, 2, 3, 4 }; // initialisation list {}
    for (IntVectorIterator iter{ intVector.begin() }; iter != intVector.end(); ++iter)
    {
        cout << *iter << ' ';
    }   cout << endl;

    // range-based-for
    for(auto item : intVector)
    {
        // item is a copy; 
        // changing item is therefore useless
        cout << item << ' ';
    }   cout << endl;
    return 0;
}
