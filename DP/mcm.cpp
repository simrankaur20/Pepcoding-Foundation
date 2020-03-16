#include<bits/stdc++.h>
using namespace std;

int mcm_rec(vector<int> &row, vector<int> &col, int start, int end)
{
    if(start == end){
        return 0;
    }
    int min_ = 1e8;
    for(int cut = start;cut<end;cut++)
    {
        int l = mcm_rec(row,col,start,cut);
        int r = mcm_rec(row,col,cut+1,end);

        int cost = l + r + row[start]*col[cut] * col[end];
        min_ = min(cost,min_);
    }
    return min_;
}
int mcm_dp( vector<int> &row, vector<int> &col, vector<vector<int>> dp , vector<vector<string>> ans)
{
    for(int gap = 0; gap < col.size(); gap++)
    {
        for(int st = 0, end = gap; end < row.size() ; st++, end++)
        {
            if(gap == 0){
                ans[st][end] = string(1, (char)'A' + st );
                continue;
            }
            
            int min_ = 1e8;
            for(int cut = st; cut<end;cut++)
            {
                int left = dp[st][cut];
                int right = dp[cut + 1][end];

                int cost = left + row[st]* col[cut] * col[end] + right;
                if(cost < min_)
                {
                    min_ = cost;
                    ans[st][end] = "(" + ans[st][cut] + ans[cut+1][end] + ")"; 
                }
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
    cout<<ans[0][col.size()-1];
    return dp[0][col.size()-1];
}
int main()
{
    vector<vector<int>> dp(4,vector<int>(4,0));
    vector<vector<string>> ans(4,vector<string>(4,""));
    vector<int> row{40,20,30,10};
    vector<int> col{20,30,10,30};

    cout<<mcm_rec(row,col,0,3);
}