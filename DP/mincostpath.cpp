#include<bits/stdc++.h>
using namespace std;
int mincost_rec(vector<vector<int>> &cost, int sr, int sc, int er, int ec)
{
    if(sr == er && sc == ec)
    {
        return cost[sr][sc];
    }
    int c = INT_MAX;
    if(sr + 1 <= er)
    {
        c = min(c, mincost_rec(cost,sr+1,sc,er,ec)) ;
    }
    if(sc + 1 <= ec)
    {
       c = min(c, mincost_rec(cost,sr,sc+1,er,ec)); 
    }
    return c + cost[sr][sc];
}

int mincost_mem(vector<vector<int>> &cost, int sr, int sc, int er, int ec,vector<vector<int>> &dp)
{
    if(sr == er && sc == ec)
    {
        return cost[sr][sc];
    }
    if(dp[sr][sc] != -1)
    {
        return dp[sr][sc];
    }
    int c = INT_MAX;
    if(sr + 1 <= er)
    {
        c = min(c, mincost_rec(cost,sr+1,sc,er,ec)) ;
    }
    if(sc + 1 <= ec)
    {
       c = min(c, mincost_rec(cost,sr,sc+1,er,ec)); 
    }
    dp[sr][sc] =  c + cost[sr][sc];
    return dp[sr][sc];
}

int mincost_tab(vector<vector<int>> &cost,int sr, int sc, int er, int ec)
{
    vector<vector<int>> dp(4,vector<int>(4,0));
    dp[er][ec] = 0;
    for(int i = er; i>=0 ; i--)
    {
        for(int j = ec; j>=0; j--)
        {
            if(i == er && j == ec)
            {
                
            }
            else if(i == er)
            {
                dp[i][j] += dp[i][j+1];
            }
            else if(j == ec)
            {
                dp[i][j] += dp[i+1][j];
            }
            else
            {
                dp[i][j] += min(dp[i+1][j],dp[i][j+1]);
            }
            dp[i][j] += cost[i][j];
        }
    }
    return dp[0][0];
}
int main()
{
    vector<vector<int>> cost{{2,3,0,4}, {0,6,5,2},{8,0,3,7},{2,0,4,2}};
    vector<vector<int>> dp(4,vector<int>(4,-1));
    cout<<mincost_tab(cost,0,0,3,3);
}