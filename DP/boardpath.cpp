#include<bits/stdc++.h>
using namespace std;

//memoisation
int boardpath(int tar,vector<int> &dp)
{
    if(tar == 0)
    {
        return 1;
    }
    if(dp[tar] != -1)
    {
       // cout<<"h"<<endl;
        return dp[tar];
    }
    int count = 0;
    for(int i = 1 ; i<=6;i++)
    {
        if(tar-i >= 0)
        {
            count += boardpath(tar-i,dp);
        }
    }

    dp[tar] = count;
  //  cout<<dp[tar]<<endl;
    return dp[tar];

}

int boardpath_tabulation(int tar)
{
    vector<int> dp(tar+1,0);
    dp[0] = 1;
    for(int i = 1;i < tar + 1; i++)
    {
        for(int c = 1; c<= 6; c++)
        {
            if(i-c >= 0 )
            {
                dp[i] += dp[i-c];
            }
        }
    }
    return dp[tar];
}

int mazepath(int x,int y, int tr,int tc, vector<vector<int>> &dp)
{
    if(x <0 || y < 0 || x >= tr || y >=tc)
    {
        return 0;
    }
    if(x == tr-1 && y == tc-1)
    {
        return 1;
    }
    if(dp[x][y]!=-1)
    {
        return dp[x][y];
    }
    int count = mazepath(x+1,y,tr,tc,dp) + mazepath(x,y+1,tr,tc,dp);
    dp[x][y] = count;
    return count;
}

int mazepath_tabulation(int x, int y, int tr, int tc)
{
    vector<vector<int>> dp(tr, vector<int>(tc,0));
    for(int i = 0; i < tc; i++)
    {
        dp[tr-1][i] = 1;;
    }
    for(int i = 0; i < tr; i++)
    {
        dp[i][tc-1] = 1;;
    }
    for(int i = tr-2; i >=0 ; i--)
    {
        for(int j = tc-2 ; j>=0; j--)
        {
            dp[i][j] = dp[i+1][j] + dp[i][j+1];
        }
    }
    return dp[0][0];
}
int main()
{

    vector<vector<int>> dp(3,vector<int>(3,-1));
    cout<<mazepath_tabulation(0,0,3,3);
}