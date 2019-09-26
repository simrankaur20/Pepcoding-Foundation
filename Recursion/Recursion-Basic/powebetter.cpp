#include<iostream>
using namespace std;
int powerbetter(int a , int b)
{
    if(b == 1)
    {
        return a;
    }

    int x = powerbetter(a , b/2);

    if(b % 2 == 0)
    {
        return x * x;
    }
    else
    {
        return x* x* a;
    }
    

}
int main()
{
    cout<<powerbetter(3,3);
}