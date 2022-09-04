#include <iostream>
#include <string>
#include <algorithm> // find

using namespace std;

int main(int argc, char* argv[])
{
    string name_String{ "Bruce Sutherland" };
    char const char_to_be_found {'e'};

    // algorithm find kick-off
    auto itr_found =
        find
        (
            name_String.begin(),
            name_String.end(),
            char_to_be_found
        );
    // find further seeks
    for (;itr_found != name_String.end();)
    {
        cout << "Found: " << *itr_found << endl;

        itr_found = find(itr_found + 1, name_String.end(), char_to_be_found);
    }

    return 0;
}
