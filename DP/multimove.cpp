#include<bits/stdc++.h>
using namespace std;
int multimove_rec(int sr, int sc, int er, int ec)
{
    if(sr == er && sc == ec)
    {
        return 1;
    }
    int count = 0;
    for(int jump = 1; sr + jump <= er;jump++ )
    {
        count += multimove_rec(sr + jump , sc, er,ec);
    }
    
    for(int jump = 1; sc + jump <= ec;jump++ )
    {
        count += multimove_rec(sr , sc +jump, er,ec);
    }
    
    for(int jump = 1; sr + jump <= er && sc + jump <=ec ;jump++ )
    {
        count += multimove_rec(sr + jump , sc + jump, er,ec);
    }
    return count;
}


int multimove_mem(int sr, int sc, int er, int ec, vector<vector<int>> & dp)
{
    if(sr == er && sc == ec)
    {
        return 1;
    }
    if(dp[sr][sc] != -1)
    {
        return dp[sr][sc];
    }
    int count = 0;
    for(int jump = 1; sr + jump <= er;jump++ )
    {
        count += multimove_mem(sr + jump , sc, er,ec,dp);
    }
    
    for(int jump = 1; sc + jump <= ec;jump++ )
    {
        count += multimove_mem(sr , sc +jump, er,ec,dp);
    }
    
    for(int jump = 1; sr + jump <= er && sc + jump <=ec ;jump++ )
    {
        count += multimove_mem(sr + jump , sc + jump, er,ec,dp);
    }
    dp[sr][sc] = count;
    return count;
}

int multimove_tab(int sr, int sc, int er, int ec)
{   
    vector<vector<int>> dp(4, vector<int>(4,0));

    dp[er][ec] = 1;
    for(int i = er;i>=0;i--)
    {
        for(int j = ec; j >=0;j--)
        {
            for(int jumps = 1; jumps + i <=er ; jumps++)
            {
                dp[i][j] += dp[i+jumps][j];
            }
            for(int jumps = 1; jumps + j <=ec ; jumps++)
            {
                dp[i][j] += dp[i][j + jumps];
            }
            for(int jumps = 1; jumps + i <=er && jumps+j<=ec ; jumps++)
            {
                dp[i][j] += dp[i+jumps][j+jumps];
            }
        }
    }
    return dp[0][0];
    
}
int main()
{
    vector<vector<int>> dp(4, vector<int>(4,-1));
    cout<< multimove_tab(0,0,3,3);
}
