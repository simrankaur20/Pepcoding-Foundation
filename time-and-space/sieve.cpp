#include<bits/stdc++.h>
using namespace std;

void computeprime(vector<bool> &s)
{
    s[0] = false;
    s[1] = false;
    for(int i = 2; i < s.size() ; i++)
    {
        if(!s[i])
        {
            continue;
        }
        for(int j = 2; j * i < s.size() ; j++)
        {
            s[j*i] = false;
        }
    }
}
int main()
{
    vector<bool> s(51,true);

    computeprime(s);

    for(int i = 0 ; i  < s.size() ; i++)
    {
        if(s[i])
        {
            cout<<i << " ";
        }
    }
}