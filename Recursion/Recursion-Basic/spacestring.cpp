#include<iostream>
#include<vector>
using namespace std;

vector<string> spaccestring(string s )
{
    if(s.length() == 0)
    {
        vector<string> a;
        return a;
    }

    vector<string> ans = spaccestring(s.substr(0, s.length()-1));
    for(int i = 0 ; i  < ans.size() ; i++)
    {
        ans[i] = ans[i] + s[s.length()-1]];

        ans[i] = ans[i] + 
    }
    return v;

}
int main()
{

}