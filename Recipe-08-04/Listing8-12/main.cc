#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cctype>

using namespace std;

// Five examples of count algorithm semantics

int main(int argc, char* argv[])
{
    string name_String{ "Bruce Sutherland!" }; // len == 17

    auto numberOfCapitals =
        count_if
        (
            name_String.begin(),
            name_String.end(),
            [](auto&& character)
            {
                return static_cast<bool>(isupper(character));
            }
    );
    cout << "1. The number of capitals: " << numberOfCapitals << endl; // 2

    auto numberOfLowerCase =
        count_if
        (
            name_String.begin(),
            name_String.end(),
            [](auto&& character)
            {
                return static_cast<bool>(islower(character)); // 13
            }
    );
    cout << "2. The number of lower case letters: " << numberOfLowerCase << endl;

    auto numberOfAlphaNumerics =
        count_if
        (
            name_String.begin(),
            name_String.end(),
            [](auto&& character)
            {
                return static_cast<bool>(isalpha(character)); // 15
            }
    );
    cout << "3. The number of alpha numeric characters: " << numberOfAlphaNumerics << endl;

    auto numberOfPunctuationMarks = count_if(
        name_String.begin(),
        name_String.end(),
        [](auto&& character)
        {
            return static_cast<bool>(ispunct(character)); // 1
        });
    cout << "4. The number of punctuation marks: " << numberOfPunctuationMarks << endl;

    auto numberOfWhiteSpaceCharacters = count_if(
        name_String.begin(),
        name_String.end(),
        [](auto&& character)
        {
            return static_cast<bool>(isspace(character)); // 1
        });
    cout << "5. The number of white space characters: " << numberOfWhiteSpaceCharacters << endl;

    return 0;
}
