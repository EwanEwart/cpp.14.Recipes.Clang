// #!/bin/sh

// md5=$( (md5 -q || md5sum -b) < $0 2>/dev/null | cut -d ' ' -f1)
// script="/tmp/`uuid`"
// script="/tmp/$(basename $0).${md5}"
// cxx="g++ -std=c++17 -pipe -Wall"
// cxx="clang++ -std=c++17 -pipe -Wall"
// more_sources=""
// linker="-lpthread"
// include="$BOOST_ROOT"
// [ -e "${script}" ] || ${cxx} -x c++ -I${include} -o ${script} - <<INLINE ${more_sources} ${linker} && exec ${script} $@


#include <iostream>
#include <thread>

using namespace std;

int main(int argc, char* argv[])
{
  (void)argc; // not used
  (void)argv; // not used

  unsigned int const numberOfProcessors{ thread::hardware_concurrency() };

  cout
    << "This system can run "
    << numberOfProcessors
    << " concurrent tasks."
    << endl;

  return 0;
}

// INLINE

/*
11-1.

Using Threads to Execute Concurrent Tasks

Problem

You’re writing a program that is performing poorly,
and you’d like to speed up execution
by using multiple processors in a system.

Solution:

C++ provides the thread type,
which can be used to create a native operating system thread.

Program threads can be run on more than a single processor
and therefore allow you to write programs
that can use multiple CPUs and CPU cores.

How It Works:

Detecting the Number of Logical CPU Cores

The C++ thread library provides a feature set
that lets programs use all the cores and CPUs
available in a given computer system.

The first important function supplied by the C++ threading capabilities
that you should be aware of
allows you to query the number of execution units
the computer contains.

clear;     g++ -std=c++17 -pipe -O2 -Wall -W -fPIC  -I. -I$BOOST_ROOT main.cc
clear; clang++ -std=c++17 -pipe -O2 -Wall -W -fPIC  -I. -I$BOOST_ROOT main.cc

Listing 11-1
shows the C++ thread::hardware_concurrency method
*/

