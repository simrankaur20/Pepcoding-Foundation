#include<bits/stdc++.h>
using namespace std;
int knapsack_dp(vector<int> &wts, vector<int> &prft, int tar)
{
    vector<vector<int>> dp(wts.size()+1, vector<int>(tar + 1, 0));
    for(int i=1;i<=wts.size();i++)
    {
        for(int j=1;j<tar+1 ; j++)
        {
            dp[i][j] = dp[i-1][j];
            if(j - wts[i-1]>=0)
            {
                dp[i][j] = max(dp[i][j] , dp[i-1][j-wts[i-1]] + prft[i-1]);
            } 
        }
    }

    return dp[wts.size()][tar];
}
int main()
{
    vector<int> wts{1,3,4,5} , prfts{10,40,50,70};
    cout<<knapsack_dp(wts, prfts, 8);
}