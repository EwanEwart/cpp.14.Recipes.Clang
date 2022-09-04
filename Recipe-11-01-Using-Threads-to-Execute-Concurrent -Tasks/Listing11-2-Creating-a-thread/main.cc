#include <iostream>
#include <thread>

using namespace std;

// a function object
class ThreadTask
{
  unsigned k;
public:
  ThreadTask(unsigned k) : k(k) {}
  void operator() ()
  {
    for (unsigned int i{ 1 }; i < k + 1; ++i)
    {
      cout << "Output no. " << i << endl;
    }
  }

};

// int main(int argc, char const * argv[])
int main()
{
  const unsigned int numberOfProcessors{ thread::hardware_concurrency() };

  cout
    << "This system can run "
    << numberOfProcessors
    << " concurrent tasks"
    << endl;

  if (numberOfProcessors > 1)
  {
    ThreadTask tt(2 * numberOfProcessors);
    
    thread aThread(tt);

    cout << "Output from main" << endl;

    aThread.join();
  }
  else
  {
    cout << "CPU does not have multiple cores." << endl;
  }

  return 0;
}
/*
Creating Threads:

Once you know the system you’re running on 
might benefit from the use of concurrent execution, 
you can use the C++ thread class 
to create tasks 
to be run on multiple processor cores. 

The thread class is a portable, built-in type 
that allows you to write multithreaded code 
for any operating system.

■ Note the thread class is a recent addition 
to the C++ programming language. 
It was added in the C++11 language spec, 
so you may need to check the documentation 
of the Standard Llibrary you’re using 
to ensure that it supports this feature.

The thread constructor is simple to use 
and takes a function to execute on another CPU core. 

Listing 11-2 shows a simple thread 
that outputs to the console.

Listing 11-2 determines whether to create a thread 
based on the number of logical cores on the computer 
executing the program.

■ Note Most operating systems allow you 
to run more threads than there are processors, 
but you might find that doing so slows your program 
due to the overhead of managing multiple threads.

If the CPU has more than one logical core, 
the program creates a thread object called aThread. 
The aThread variable is initialised 
with a pointer to a function. 

This function will be executed in the thread context and, 
more likely than not, on a different CPU thread 
than the main function.

The ThreadTask function consists of a for loop 
that simply outputs to the console multiple times.

The main function also outputs to the console. 
The intent is to show that both functions are running concurrently. 

You can see that this is true in Figure 11-3, 
where the output from main occurs in the middle of
the output from ThreadTask.
*/
