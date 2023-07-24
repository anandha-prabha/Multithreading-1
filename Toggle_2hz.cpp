#include<iostream>
#include<thread>
#include<bits/stdc++.h>
#include<future>
#include<mutex>
#include<chrono>
using namespace std;
mutex m;
future<bool>f;
//function to toggle between 0 and 1 at frequency of 2Hz.
bool fun(int c)
{
     //lock_guard<mutex>lock(m);
     this_thread::sleep_for(chrono::milliseconds(500));        //delay of 500 milliseconds is created
     if(c%2!=0)                                                //if count c is odd in number true is returned 
     {
        return true;
     }
     if(c%2==0)                                                 //if count c is even in number false is returned 
     {
        return false;
     }
}
int main()
{
    int n=0,c=0;
    cout<<"Enter the number of times to toggle between 0 and 1:";
    cin>>n;
    bool x;
    while(n)                                                    //loop executes for n times and gets the future f value and diaplays 0 and 1 alternatively.
    {
        future<bool>f=async(fun,c++);
        x=f.get();                                              //gets true or false values from fun()
        cout<<x;
        n--;
    }
    return 0;
}