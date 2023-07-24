
#include<iostream>
#include<thread>
#include<mutex>
#include<vector>
using namespace std;
vector<int>a{10,20,40,30,15};
mutex m;
void sorting(int c)                                         //function to sort the vector in ascending and descending order
{

    lock_guard<mutex>guard(m);                              //lock guard is used to lock the critical section and it unlocks itself when thread is executed
    //m.lock();
    if(c==0)
    {
        for(int i=0;i<a.size();i++)
    {
        for(int j=i+1;j<a.size();j++)
        {
            if(a[i]>a[j])
            {
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
        //display();
    }
    cout<<"Ascending order: "<<endl;                        //prints the vector in ascending order
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<endl;
    }
    }
    if(c==1)                                                //if c is 1 thread 2 gets executed
    {
        for(int i=0;i<a.size();i++)                         //sorts the vector in descending order
    {
        for(int j=i+1;j<a.size();j++)
        {
            if(a[i]<a[j])
            {
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
       // display();
    }
    cout<<"Descending order: "<<endl;                       //prints the vector in descending order
     for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<endl;
    }
    }
    //m.unlock();
}

int main()
{
    thread t1(sorting,0);                                  //t1 and t2 threads are created and sorting function is called with arguments
    thread t2(sorting,1);

    t1.join();
    t2.join();

    return 0;
}