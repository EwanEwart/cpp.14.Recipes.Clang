#include <iostream>

using namespace std;

namespace
{
    auto EXCEPTION_FALSE{ "-- no exception has occurred --"s };
    auto EXCEPTION_TRUE{ "-- an unexpected exception has occurred --"s };
    char const* const STRING{ "This is a string" };
    // char* EDIT_STRING{ "Attempt to Edit" }; // old style literal non const
    char const* const EDIT_STRING{ "Attempt to Edit" }; // old style literal : const
    // char const* const EDIT_STRING{ "Attempt to Edit" };
}

int main()
{
    cout << STRING << endl;
    cout << EDIT_STRING << endl;

    /*
    ...updating 2 targets...
clang-linux.compile.c++.without-pth /tmp/development/bin/c++14-recipes-clang/Recipe-03-01/Listing3-2/clang-linux-3.8.0/debug/threading-multi/Listing3-2.o
Listing3-2.cc:11:24:
warning: ISO C++11 does not allow conversion from string literal to 'char *' [-Wwritable-strings]
    char* EDIT_STRING{ "Attempt to Edit" };
                       ^
1 warning generated.
clang-linux.link /tmp/development/bin/c++14-recipes-clang/Recipe-03-01/Listing3-2/clang-linux-3.8.0/debug/threading-multi/Listing3-2
...updated 2 targets...
When run will lead to a segmentation fault.
Use c++14 string literals !!!
    */
    try // doesn't catch the editing
    {
        cout << EDIT_STRING[0] << endl;
        EDIT_STRING[8] = 'X'; // TRIGGERS exception // Microsoft treat warnings as errors /WX : doesn't stop compiler with errors, but "char const * const" does && Intellisense notifies you in the editor
        EDIT_STRING[9] = 'Y'; // TRIGGERS exception // Microsoft treat warnings as errors /WX : doesn't stop compiler with errors, but "char const * const" does && Intellisense notifies you in the editor
        std::cout << EXCEPTION_FALSE << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n'; // doesn't get here: catch signal & throw
    }
    catch (...)
    {
        std::cerr << EXCEPTION_TRUE << std::endl; // doesn't get here: catch signal & throw
    }


    cout << EDIT_STRING << endl;

    return 0;
}
/*
Editing a string literal

Listing 3-2 adds a new string literal,
which is assigned to a non-const pointer.

The main function also has code,
which tries to edit the first character in the string
to be a lower case a.

This code will compile without error.

However you should receive a warning from a C++11/C++14 compiler,
as it is perfectly valid to attempt to alter a strings
using the array operator.

However it is a runtime exception
to try to alter data contained within string literals.

Trying to run this program results in the error shown in Figure 3-2.

You can catch these errors at compile time
rather than runtime
by following a very simple piece of advice.

Always assign old-style string literals to variables
of type const char* const.

You can use the makefile from Listing 3-3 if you want to enforce this
in a very straight forward fashion

*/
