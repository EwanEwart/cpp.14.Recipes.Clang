#include <iostream>
#include <iomanip>
#include <thread>

using namespace std;

void ThreadTask(int cycles = 20)
{
    for (unsigned int i = 0; i < 20; ++i)
    {
        cout << "Output from thread ( " << setw(3) << i << " )" << endl;
    }
}

int main(int argc, char* argv[])
{
    const unsigned int numberOfProcessors{ thread::hardware_concurrency() };

    cout << "This system can run " << numberOfProcessors << " concurrent tasks" << endl;

    if (numberOfProcessors > 1)
    {
        auto cycles {25};

        thread anAdditionalThread{ ThreadTask, cycles };

        cout << "Output from main" << endl;

        ////////////////////////////
        anAdditionalThread.detach();
        ////////////////////////////
    }
    else
    {
        cout << "CPU does not have multiple cores." << endl;
    }

    return 0;
}

/*
Using the detach Method:

One approach is to use the join method
to make the program wait for threads to finish
before closing them down.

C++ also provides a second option:
the detach method.

Listing 11-4 shows the detach method in use.

Listing 11-4 shows
that the detach method can be used in place of join.

The join method causes the program to wait
for a running thread to complete before continuing,
but the detach method doesn’t.

The detach method allows you to create threads
that outlive the execution of your program.

These may be useful for system tasks
that need to track time over long periods;

however, I’m skeptical about
whether many day-to-day programs
will find a use for this method.

There’s also a risk
that your program will leak threads
that have been detached and have no way
to get those tasks back.

Once an execution context in a thread has been detached,
you can never reattach it.

*/
