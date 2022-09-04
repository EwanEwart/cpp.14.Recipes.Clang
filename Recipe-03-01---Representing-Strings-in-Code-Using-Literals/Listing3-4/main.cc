#include <iostream>
#include <string>
#include <vector>

#include "../../../cplusplus.h"

using namespace std;

// #define NDEBUG // release build

#define square_area(x) (x*x)

namespace
{

/*
#if DEBUG_STRING_LITERALS
    using StringLiteral = string;
#endif
*/

#if !defined(NDEBUG) // if debug build: include string literals in executable, otherwise not
    std::string DBG_STRING_LITERAL{ "This is a String literal for debug purposes!"s };
#endif

} // end of anonymous ns / end of string table

int main()
{

#if !defined(NDEBUG) // if debug build: string literls table included into executable
    cout << DBG_STRING_LITERAL << endl;
#endif

    cout << "C++ version " << __cplusplus << endl;


    // a macro: square
    for (int const& i : { 1,2,3,4,5,6,7,8,9,10 })
    {
        cout << square_area(i) << endl;
    }

    // start block: range for loops
    {

        std::vector<int> v = { 0, 1, 2, 3, 4, 5 };

    // access by const reference
    for (int const& i : v)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n' << endl;


    // access by value, the type of i is int
    for (auto i : v)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n' << endl;


    // access by forwarding a reference; the type of i is int&
    for (auto&& i : v)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n' << endl;


    // access by f-d reference, the type of i is const int&
    const auto& cv = v;
    for (auto&& i : cv)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n' << endl;


    // the initialiser may be a braced-init-list
    for (int n : {0, 1, 2, 3, 4, 5})
    {
        std::cout << n << ' ';
    }
    std::cout << '\n' << endl;

    // the initialiser may be an array
    int a[] = { 0, 1, 2, 3, 4, 5 };
    for (int n : a)
    {
        std::cout << n << ' ';
    }
    std::cout << '\n' << endl;

#if _MSVC_LANG >= CPP_17 || __cplusplus >= CPP_17
        for ([[maybe_unused]] int n : a) // attribute 'maybe_unused' requires at least /stdc++17
        {
            std::cout << 1 << ' '; // the loop variable need not be used
        }
        std::cout << '\n' << endl;
#endif

#if _MSVC_LANG >= CPP_20_02 || __cplusplus >= CPP_20_02

        for (auto n = v.size(); auto i : v) // the init-statement (C++20); A RANGE-BASED FOR STATEMENT WITH AN INITILISER REQURES AT LEAST /std:c++20
        {
            std::cout << --n + i << ' ';
        }
        std::cout << '\n';

        for (typedef decltype(v)::value_type elem_t; elem_t i : v) // A RANGE-BASED FOR STATEMENT WITH AN INITIALISER REQUIRES AT LEAT /std:c++20
            // typedef declaration as init-statement (C++20)
        {
            std::cout << i << ' ';
        }
        std::cout << '\n' << endl;

#endif

#if _MSVC_LANG >= CPP_23 || __cplusplus >= CPP_23
        for (using elem_t = decltype(v)::value_type; elem_t i : v)
            // alias declaration as init-statement, same as above (C++23)
        {
            std::cout << i << ' ';
        }
        std::cout << '\n' << endl;
#endif


    } // end block: range for loops


    return 0;
}

/*

Listing 3-4 creates a preprocessor symbol DEBUG_STRING_LITERALS
using the NDEBUG symbol. (Modified !)

The NDEBUG preprocessor symbol stands for --- not debug ---
and therefore we can use it to determine
whether we would like to have debug string literals included in our program or not.

The definition of the type alias StringLiteral
is then wrapped in an #if...#endif block,
which ensures that StringLiteral only exists
when building debug builds.

The --- NDEBUG --- symbol is commonly used in IDEs 
when building --- release builds --- of your program. 

As the samples that accompany this book are built using make 
you will have to manually define this in your makefile. 

An example makefile is shown in Listing 3-5.

*/
