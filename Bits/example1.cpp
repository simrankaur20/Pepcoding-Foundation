#include<bits/stdc++.h>
using namespace std;
int example1(int x , int k)
{
    //kth bit
    //off - on
    //on - on
    int mask = (1 << k);
    x = (x | mask);
    return x;
}

int example2(int x , int k)
{
    // on - off
    // off - off

    int mask = ~(1 << k);
    x = (x & mask);
    return x;
}
int main()
{
    int num , k;
    cin >> num >> k;
    cout<<example2(num , k);
}