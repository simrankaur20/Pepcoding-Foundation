#include<bits/stdc++.h>
using namespace std;

void fmap(string s)
{
    unordered_map<char,int> fm;
    for(char c : s)
    {
        fm[c]++;
    }
}
void indexmap(string s)
{
    unordered_map<char,vector<int>> im;
    for(int i=0;i<s.length() ; i++)
    {
        im[s[i]].push_back(i);
    }

    unordered_map<char,vector<int>> :: iterator it;
    for( it = im.begin() ; it!= im.end() ; it++)
    {
        cout<< it->first << " : ";
        for(int i = 0 ; i < it->second.size() ; i++){
            cout<< it->second[i]<<" ";
        }
        cout<<endl;
    }
}

void longestsubseq(vector<int> &ar)
{
    unordered_map<int,bool> m;

    for(int el : ar) m[el] = true;

    int msize = -1, mnum = -1;
    
    for(int num : ar){
        if(m.count(num-1))
        {
            m[num] = false;
        }
    }

    for(auto it : m)
    {
        if(it.second)
        {
            int sz= 1, n = it.first;

            while(m.count(++n))
            {
                sz++;
            }
            if(sz > msize)
            {
                msize = sz;
                mnum = it.first;
            }
        }
    }
        for(int i = 0 ; i  < msize ; i++)
        {
            cout<<mnum + i << " ";
        }
}


int main()
{
    vector<int> ar{1,2,3,4,7,8,9,4,5,6,7,8};
    longestsubseq(ar);
}