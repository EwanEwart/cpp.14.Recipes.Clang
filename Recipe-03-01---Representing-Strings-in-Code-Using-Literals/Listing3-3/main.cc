#include <iostream>

using namespace std;

namespace
{
    const char* const STRING{ "This is a string" };
    char const * const EDIT_STRING{ "Attempt to Edit" }; // get pre-compile warnings
    // char* EDIT_STRING{ "Attempt to Edit" };
}

int main()
{
    cout << STRING << endl;

    cout << EDIT_STRING << endl;

    try // exception won't be caught
    {
        EDIT_STRING[0] = 'a';
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    cout << EDIT_STRING << endl;

    return 0;
}
