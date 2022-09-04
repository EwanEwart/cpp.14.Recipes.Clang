/*
clang++ -g -std=c++17 main.cpp -o delete_me
*/
#include <iostream>
#include <cstdio>

using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
  cout << "Hi!" << endl;
  cout << "What's your name? ";
  
  char input[256];
  scanf("%s", input);
  cout << "Your name is " << input << '.' << endl;

  return 0;
}
