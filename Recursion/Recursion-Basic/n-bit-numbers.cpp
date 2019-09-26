#include<bits/stdc++.h>
using namespace std;
vector<string> numbers(int n)
{
    if(n == 1)
    {
        vector<string> a;
        a.push_back("0");
        a.push_back("1");
        return a;
    }

    vector<string> t = numbers(n-1) , ans;
    for(string s : t)
    {
        ans.push_back(s + "0");
        ans.push_back( s + "1");
    }
    return ans;
}

int main()
{
    vector<string> a = numbers(3);
    for(string temp : a)
    {
        cout<< temp<<endl;
    }
}