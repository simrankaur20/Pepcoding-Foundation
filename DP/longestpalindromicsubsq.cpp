#include<bits/stdc++.h>
using namespace std;
int count_longestpalinsubsq(string s)
{
    vector<vector<int>> dp(s.length(), vector<int>(s.length(), 0));

    for(int gap = 0; gap<s.length(); gap++)
    {
        for(int i=0, j= gap; j<s.length() ; j++,i++)
        {
            if(gap == 0)
            {
                dp[i][j] = 1;
            }
            else if(s[i] == s[j])
            {
                dp[i][j] = dp[i+1][j] + dp[i][j-1] + 1;
            }
            else if(s[i] !=s[j])
            {
                dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
            }
        }
    }
    for(int i=0;i<s.length();i++)
    {
        for(int j=0;j<s.length();j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[0][s.length()-1];
}
int main()
{
    cout<<"execute"<<endl;
    cout<<count_longestpalinsubsq("babad");

}