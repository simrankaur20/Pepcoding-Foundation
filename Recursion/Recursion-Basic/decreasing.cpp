#include<iostream>
using namespace std;
void printdecr(int a , int b)
{
    if(a > b)
    {
        return ;
    }
    cout<<b<<endl;
    printdecr(a , b-1);
}
int main()
{
    printdecr(5,10);
}