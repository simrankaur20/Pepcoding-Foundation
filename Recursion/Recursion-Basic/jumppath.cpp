#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<string> jumpath(int sr, int sc,int er,int ec)
{
    if(sr>er || sc > ec)
    {
        return ;
    }
    if(sr == er && sc == ec)
    {
        vector<string> ans;
        string t;
        t = "( " + to_string(er) + to_string(ec) + ")" ;  
        ans.push_back(t);
        return ans;
    }
    vector<string> ans;
    for(int i = 1 ; i  < er; i++)
    {
        if(sr+i <= er)
        {
            vector<string> h = jumpath(sr+i , sc , er , ec);

            for(string s : h)
            {
                ans.push_back("( " + to_string(sr) + " , " + to_string(sc)+ ")"  + s);
            }
        }
    }
    for(int i = 1 ; i  < ec; i++)
    {
        if(sc+i <= ec)
        {
            vector<string> v = jumpath(sr , sc + i , er , ec);

            for(string s : v)
            {
                ans.push_back("( " + to_string(sr) + " , " + to_string(sc)+ ")"  + s);
            }
        }
    }
    for(int i = 1 ; i  < min(er,ec); i++)
    {
        if(sr+i <= er && sc+i <= ec)
        {
            vector<string> h = jumpath(sr+i , sc+1 , er , ec);

            for(string s : h)
            {
                ans.push_back("( " + to_string(sr) + " , " + to_string(sc)+ ")"  + s);
            }
        }
    }
}