#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

// using std::operator""s; // literal operator'
using namespace std::string_literals;

#include "../../../cplusplus.h"

#if _MSVC_LANG > CPP_17 || __cplusplus > CPP_17

// Observe first parameter: from > CPP_17
void print_with_zeros(auto const note, std::string const& s)
{
  std::cout << note;
  for (const char c : s) {
    (c ? std::cout << c : std::cout << "₀");
  }
  std::cout << " (size = " << s.size() << ")\n";
}

#endif

// anonymous namespace / global ns
namespace
{  // the table of strings holding these string literals
  string const STRING{ "(newline...)\n--- This is a string embedded in an executable (newline)...\nby the compiler (newline...)\nnamely the \"table of strings\".(newline...)\n"s };
  string const AUTHOR{ "--- (c) Ewan Ewart(newline...)\n"s };
  string const DATE{ "--- 2022.05.29.19.55(newline...)\n"s };
  auto sl1 {"string literal s1"s};
  auto sl2 {"string literal s2"s};
  auto sl3 {"string literal s3"s};
}

int main()
{
  cout << STRING << endl;
  cout << DATE << endl;
  cout << AUTHOR << endl;

// print_with_zeros > c++17
#if _MSVC_LANG > CPP_17 || __cplusplus > CPP_17

  std::string s1 = "abc\0\0def";
  std::string s2 = "abc\0\0def"s; // string literal; every char is a char, raw string
  print_with_zeros("s1: ", s1);
  print_with_zeros("s2: ", s2);

  std::cout << "abcdef"s.substr(1, 4) << '\n';

#endif
  // use string literals to initialise STL string objects
  // strings: look at main.exe using a hex editor of vsc (visual studio code)
  auto s11 {sl1};
  auto s12 {sl1};
  auto s13 {sl1};
  auto s21 {sl2};
  auto s22 {sl2};
  auto s23 {sl2};
  auto s31 {sl3};
  auto s32 {sl3};
  auto s33 {sl3};

  return 0;
}
/*
A string literal

The "string literal" in this example is the sentence,
which is included inside the quotation marks
and followed by the letter s.

The compiler will create "a table of strings"
during compilation
and place them all together.
You can see this string inside the executable created
from the source in Figure 3-1.

Console session ...

less /tmp/development/bin/c++14-recipes-clang/Recipe-03-01/Listing3-1/clang-linux-3.8.0/debug/threading-multi/Listing3-1

You can use --- string literals ---
to initialise STL string objects.

The compiler will find all of the strings
in your program and use the address from the string table
to initialise your string.

You can see this in Listing 3-1:
the pointer STRING is initialised
using the string literal,
in effect this code is actually telling the compiler
to add the literal to the string table
and get the address of this specific string
from the table to pass it to the string constructor.

The string literal in Listing 3-1 is a C++14 style string literal.

Older style string literals must be used with
care as they come with a few caveats. The first is that you should never try to alter the contents of a string
literal. Consider the code in Listing 3-2
*/
