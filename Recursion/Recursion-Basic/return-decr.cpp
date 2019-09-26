#include<iostream>
using namespace std;
int printdecr(int a , int b)
{
    if(a == b)
    { 
        cout<<a<<endl;
        return a;
    }

    int x = printdecr(a+1 , b);
    cout<<a-1<<endl;
    return a-1;
}
int main()
{
    printdecr(5,10);
}