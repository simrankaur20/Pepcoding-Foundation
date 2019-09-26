#include<iostream>
using namespace std;
void printincr(int a , int b)
{
    if(a == b)
    { 
        return ;
    }

    printincr(a,  b-1);
    cout<<b<<endl;
}
int main()
{
    printincr(5,10);
}