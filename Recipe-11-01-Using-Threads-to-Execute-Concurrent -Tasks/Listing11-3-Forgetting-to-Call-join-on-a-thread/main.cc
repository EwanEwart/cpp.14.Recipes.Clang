#include <iostream>
#include <iomanip>
#include <thread>

using namespace std;

// a thread function
void ThreadTask(int cycles = 20)
{
    for (unsigned int i{ 0 }; i < cycles; ++i)
    {
        cout << "Output from thread ( " << setw(3) << i + 1 << " )" << endl;
    }
}

// auto l1 []{};

int main(int argc, char* argv[])
{
    const unsigned int numberOfProcessors{ thread::hardware_concurrency() };

    cout << "This system can run " << numberOfProcessors << " concurrent tasks" << endl;

    if (numberOfProcessors > 1)
    {
        auto cycles {25};

        thread aThread{ ThreadTask, cycles };

        cout << "Output from main (1)" << endl;

        ////////////////// 
        aThread.join();
        //////////////////
        
        cout << "Output from main (2)" << endl;

    }
    else
    {
        cout << "CPU does not have multiple cores." << endl;
    }

    return 0;
}

/*
Cleaning Up After Threads:

The main function in Listing 11-2 
immediately calls the join method on the thread. 

The join method is used to tell the current thread 
to wait for the additional thread to end execution 
before continuing. 

This is important, 
because C++ programs are required 
to destroy their own threads 
to prevent leaks.

Calling the destructor on a thread object 
doesn’t destroy the currently executing thread context. 

Listing 11-3 shows code 
that has been modified to not call join on aThread

This code causes the aThread object to go out of scope, 
before the ThreadTask function has completed execution. 

This can cause a thread leak in your program 
that may eventually cause the program or the operating system 
to become unstable. 

A program running on the Linux command line 
will fail with the error shown in Figure 11-4.

As you can see, 
this warning isn’t particularly descriptive, 
and there’s no guarantee 
that you’ll get any warning 
when using other operating systems and libraries. 

It’s therefore important to be aware of your threads' lifetimes 
and ensure that you’re dealing with them appropriately.

One approach is to use the join method 
to make the program wait for threads to finish 
before closing them down. 

C++ also provides a second option: 
the detach method. 

Listing 11-4 shows the detach method in use.
*/
