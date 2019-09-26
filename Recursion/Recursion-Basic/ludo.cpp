#include<bits/stdc++.h>
using namespace std;
vector<string> path(int n)
{
    if( n == 0)
    {
        vector<string> v ;
        v.push_back("");
        return v;
    }
    if(n<0)
    {
        vector<string> v ;
        return v;
    }
    
    vector<string> ans;
    for(int i = 1; i <= 6 ; i++)
    {
        vector<string> r = path(n - i);
        for(string s : r)
        {
            ans.push_back( to_string(i) + s);
        }
    }

    return ans;
}
int main()
{
    vector<string> r = path(10);
    for(string s : r)
    {
        cout<<s<<endl;
    }

    cout<<"size"<< r.size()<<endl;

}