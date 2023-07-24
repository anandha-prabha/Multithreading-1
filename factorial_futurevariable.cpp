#include<iostream>
#include<vector>
#include<mutex>
#include<future>
using namespace std;
int factorial(int n)                   //calculates the factorial of n     
{
    int result=1;
    for(int i=1;i<=n;i++)
    {
        result*=i;
    }
    return result;
}
int main()
{
    int x,y;
    future<int>f=async(factorial,4);                             //f and f1 future variables are declared
    future<int>f1=async(factorial,5);
    int a[2][2]={1,2,3,4},b[2][2]={1,2,3,4},c[2][2]={0,0,0,0};   //matrix a,b,c are initialised
    for(int i=0;i<2;i++)                                         //performs matrix multiplication with a,b and stores in c matrix
    {
        for(int j=0;j<2;j++)
        {
            for(int k=0;k<2;k++)
            {
                c[i][j]+=a[i][k]*b[k][j];
            }

        }
    }
    for(int i=0;i<2;i++)                                         //displays the resultant matrix
    {
        for(int j=0;j<2;j++)
        {
            cout<<c[i][j]<<" ";
        }cout<<endl;

    }

    x=f.get();                                                   //gets the future variables values stores it in x and y and prints the value.
    y=f1.get();                                                  
    cout<<x<<y;
    return 0;
}