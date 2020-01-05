#include<bits/stdc++.h>
using namespace std;
int partition(int n, int k)
{
    if(n == 0 && k == 0)
    {
        return 0;
    }
    if(k > n || n == 0){
        return 0;
    }
    if(k == 1|| n == k){
        return 1;
    }

    return partition(n-1,k-1) + k*partition(n-1,k);
}

int partition_tab(int n, int k)
{
    vector<vector<int>> dp(k+1,vector<int>(n+1,0));
    dp[0][0] = 1;
    for(int i =1;i<=k;i++)
    {
        for(int j=i;j<=n;j++)
        {
            dp[i][j] = dp[i-1][j-1] + i*dp[i][j-1];
        }
    }
    return dp[k][n];
}
int main()
{
    cout<<partition_tab(5,2);
}