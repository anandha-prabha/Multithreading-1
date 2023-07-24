#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
using namespace std;
mutex m;
condition_variable cv;
bool state=false;
//function to print 1 to 100 and 100 to 1
void threads(int a,int b,int c)
{
    unique_lock<mutex>lock(m);                      //unique lock locks the critical section and unlocks itself
    cv.wait(lock,[](){return state;});              //after receiving notify signal the threads will be executed
    if(c==0)
    {
       for(int i=a;i<=b;i++)
        {
            cout<<i<<" ";
        }
    }
    if(c==1)
    {

       for(int i=a;i>=b;i--)
        {
            cout<<i<<" ";
        }
    }
}
int main()
{
    thread worker1(threads,1,100,0);               //worker threads are created and threads function is called with arguments
    thread worker2(threads,100,1,1);
    this_thread::sleep_for(chrono::seconds(2));    //sleep for delays for 2 seconds
    {
        lock_guard<mutex>lock(m);                  //lock guard is used to locks the state variable and it unlocks itself
        state = true;
    }
    cv.notify_all();                               //after the main thread execution cv.notify_all notify all threads to execute
    worker1.join();                                //join() executes after executing the threads and returns the threads.
    worker2.join();
    return 0;
}

