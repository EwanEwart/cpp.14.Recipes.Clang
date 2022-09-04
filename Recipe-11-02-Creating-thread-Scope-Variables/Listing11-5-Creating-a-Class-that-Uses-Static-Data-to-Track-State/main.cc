#include <cstdlib>
#include <iostream>
#include <stack>
#include <thread>
#include <vector>

using namespace std;

/*
Listing 11-5
contains a class
that uses a static vector of objects
to prevent many calls to new and delete.
*/

using FreeList = stack<unsigned int>;

class ManagedObject
{
private:
    static unsigned int const MAX_OBJECTS{ 4 };

    using ManagedObjectsCollection = vector < ManagedObject >;
    static ManagedObjectsCollection s_ManagedObjectsCollection; // class variable

    static FreeList s_FreeList; // class variable

    unsigned int m_Value{ 0xFFFFFFFF }; // instance variable

public:
    /* Defaulted default constructor:
    the compiler will define the implicit default constructor
    even if other constructors are present.
    */
    ManagedObject() = default;
    ManagedObject(unsigned int value)
        : m_Value{ value }
    {

    }

    void* operator new(size_t numBytes)
    {
        void* objectMemory{};
        // capacity: The total amount of allocated memory
        if (s_ManagedObjectsCollection.capacity() < MAX_OBJECTS)
        {
            /* Reallocations are usually costly operations
            in terms of performance.
            The reserve() function can be used
            to eliminate reallocations
            if the number of elements is known beforehand.
            */
            s_ManagedObjectsCollection.reserve(MAX_OBJECTS);
        }

        if (
            numBytes == sizeof(ManagedObject)
            &&
            s_ManagedObjectsCollection.size() < s_ManagedObjectsCollection.capacity()
            )
        {
            unsigned int index{ 0xFFFFFFFF };
            if (s_FreeList.size() > 0)
            {
                index = s_FreeList.top();
                s_FreeList.pop();
            }

            if (index == 0xFFFFFFFF)
            {
                s_ManagedObjectsCollection.push_back({});
                index = s_ManagedObjectsCollection.size() - 1;
            }

            objectMemory = s_ManagedObjectsCollection.data() + index;
        }
        else
        {
            objectMemory = malloc(numBytes);
        }

        return objectMemory;
    }

    void operator delete(void* pMem)
    {
        intptr_t const index
        {
            (
                static_cast<ManagedObject*>(pMem)
                -
                s_ManagedObjectsCollection.data()
            )
            /
            static_cast<intptr_t>(sizeof(ManagedObject))
        };
        if (0 <= index && index < static_cast<intptr_t>(s_ManagedObjectsCollection.size()))
        {
            /*
            constructs element in-place at the top; no copy, no move
            */
            s_FreeList.emplace(static_cast<unsigned int>(index));
        }
        else
        {
            free(pMem);
        }
    }
};  // ManagedObject



ManagedObject::ManagedObjectsCollection ManagedObject::s_ManagedObjectsCollection{};
FreeList ManagedObject::s_FreeList{};
int main(int argc, char* argv[])
{
    cout << hex << showbase;

    ManagedObject* pManagedObject1{ new ManagedObject(1) }; cout << "pManagedObject1: " << pManagedObject1 << endl;

    ManagedObject* pManagedObject2{ new ManagedObject(2) }; cout << "pManagedObject2: " << pManagedObject2 << endl;

    if (pManagedObject1)
    {
        delete pManagedObject1; pManagedObject1 = nullptr;
    }

    ManagedObject* pManagedObject3{ new ManagedObject(3) }; cout << "pManagedObject3: " << pManagedObject3 << endl;

    pManagedObject1 = new ManagedObject(4); cout << "pManagedObject1: " << pManagedObject1 << endl;

    ManagedObject* pManagedObject4 = new ManagedObject(4); cout << "pManagedObject4: " << pManagedObject4 << endl;
    
    ManagedObject* pManagedObject5 = new ManagedObject(5); cout << "pManagedObject5: " << pManagedObject5 << endl;

    if (pManagedObject1)
    {
        delete pManagedObject1; pManagedObject1 = nullptr;
    }

    if (pManagedObject2) 
    {
        delete pManagedObject2; pManagedObject2 = nullptr;
    }

    if (pManagedObject3)
    {
        delete pManagedObject3; pManagedObject3 = nullptr;
    }

    if (pManagedObject4)
    {
        delete pManagedObject4; pManagedObject4 = nullptr;
    }

    if (pManagedObject5)
    {
        delete pManagedObject5; pManagedObject5 = nullptr;
    }

    return 0;
}

/* output

pManagedObject1: 00ECB9D8
pManagedObject2: 00ECB9DC
pManagedObject3: 00ECB9D8
pManagedObject1: 00ECB9E0
Press any key to continue . . .

*/

/*
11-2. Creating thread Scope Variables:

Problem:
You have objects of classes
that use static data in their implementations,
and you’d like to use them with threads.

Solution:
C++ provides the thread_local specifier
to allow the computer
to create an instance of the static data
on a per-thread basis.

How It Works:
Before I cover how to use thread_local,
let’s step through a scenario
where this problem can occur
so you can clearly see the issue
and the problem
the solution itself can cause.

Listing 11-5 contains a class
that uses a static vector of objects
to prevent many calls to new and delete.

*/
