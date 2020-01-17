#include<bits/stdc++.h>
using namespace std;
int countdistinct(string str)
{
    str = string(1,'$') + str;

    vector<int> dp(str.length(),0);
    dp[0] = 1;
    for(int i = 1;i < str.length() ; i++)
    { 
        dp[i] = 2 * dp[i-1];
        
    }
}
int main()
{
    
}