#include <iostream>
#include<thread>
#include<mutex>
using namespace std;
mutex m;
//function to print the even and odd numbers between 1 to 20
void print(int i,int a,int b)
{
    lock_guard<mutex>lock(m);               //lock guard is used to lock the critical section and it unlocks itself when thread is executed
    if(i==2)                                //if i==2 it prints all the even numbers between a and b
    {
         for(int j=a;j<=b;j++)
        {
            if(j%2==0)                      //checks if j is even and prints j
            {
                cout<<j<<" ";
            }
        }
    }
    else
    {
         for(int j=a;j<=b;j++)              //if i!=2 it prints all the odd numbers between a and b
        {
            if(j%2!=0)                      //checks if j is odd and prints j
            {
                cout<<j<<" ";
            }
        }
    }
   // m.unlock();
}
int main()
{
    thread t1(print,2,1,20);                //t1 and t2 threads are created and print function is called with arguments to display odd and even numbers.
    thread t2(print,1,1,20);

    t1.join();
    t2.join();
    return 0;
}
