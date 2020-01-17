#include<bits/stdc++.h>
using namespace std;
int mcm_rec( vector<int> &row, vector<int> &col, vector<vector<int>> dp)
{
    for(int gap = 0; gap < col.size(); gap++)
    {
        for(int st = 0, end = gap; end < row.size() ; st++, end++)
        {
            if(gap == 0)
                continue;
            
            int min_ = 1e8;
            for(int cut = st; cut<end;cut++)
            {
                int left = dp[st][cut];
                int right = dp[cut + 1][end];

                int cost = left + row[st]* col[cut] * col[end] + right;
                min_ = min(cost, min_);
            }
            dp[st][end] = min_;
        }
    }

    for(int i=0;i<=3;i++)
    {
        for(int j=0;j<=3;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[0][col.size()-1];
}
int main()
{
    vector<vector<int>> dp(4,vector<int>(4,0));

    vector<int> row{2,3,6,4};
    vector<int> col{3,6,4,5};

    cout<<mcm_rec(row,col,dp);
}