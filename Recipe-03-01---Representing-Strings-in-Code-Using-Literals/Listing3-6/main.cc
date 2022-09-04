#include <iostream>
#include <string>

using namespace std;

#define NDEBUG 1 // release
// #define NDEBUG 0 // debug

#if NDEBUG
    // release build
#else
    // debug build
#endif

#define DEBUG_STRING_LITERALS !NDEBUG

namespace
{
#if DEBUG_STRING_LITERALS
    using DebugStringLiteral = string;
#endif

#if DEBUG_STRING_LITERALS
    DebugStringLiteral STRING{ "This is a String for debugging purposes only!"s };
#endif
}

int main()
{
#if DEBUG_STRING_LITERALS
    cout << STRING << endl;
#endif

    return 0;
}
