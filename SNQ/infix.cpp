#include<bits/stdc++.h>
using namespace std;
void assignpriority(unordered_map<char, int> &m)
{
    unordered_map<char, int> m;

    m['^'] = 1;
    m['*'] = 2;
    m['/'] = 2;
    m['%'] = 2;
    m['*'] = 2;
    m['+'] = 3;
    m['-'] = 3;
}

int infix(string s)
{
    unordered_map<char, int> m;
    assignpriority(m);
    stack<int> numstack;
    stack<char> opstack;
    for(int i =0;i<s.length();i++)
    {
        if(s[i] >='0' && s[i]<='9')
        {
            numstack.push(s[i]-48);
            continue;
        }
        else
        {
            if(s[i] == ')')
            {
                while(!opstack.empty() && m[s[i]] < m[opstack.top()] )

            }
            while(!opstack.empty() && m[s[i]] < m[opstack.top()] )
        }
    }
}
int main()
{

}