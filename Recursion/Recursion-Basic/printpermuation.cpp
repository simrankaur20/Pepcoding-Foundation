#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void printpermu(string str , string ans)
{
    if(str.length() == 0)
    {
        cout<<ans<<endl;
        return ;
    }
    
    for(int i = 0; i < ans.length() +1; i++)
    {
        string temp = ans.substr(0,i) + str[0] + ans.substr(i,ans.length()-i);
        //cout<<temp<<endl;
        printpermu(str.substr(1) , temp);
    }
}
int main()
{
    printpermu("ab","");
}