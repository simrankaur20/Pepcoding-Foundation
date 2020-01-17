#include<bits/stdc++.h>
using namespace std;
int goldmine(vector<vector<int>> &arr)
{
    vector<vector<int>> dp(arr.size(),vector<int>(arr[0].size(),0));
    int max_ = INT_MIN;
    for(int j =0;j<arr[0].size();j++)
    {
        for(int i =0;i<arr.size();i++)
        {
            
            if(j == 0)
            {
                dp[i][j] = arr[i][j];
            }
            else if(i == 0)
            {
              dp[i][j] = max(dp[i+1][j-1], dp[i][j-1]) + arr[i][j];  
            }
            else if(i == arr.size() -1)
            {
              dp[i][j] = max(dp[i][j-1], dp[i-1][j-1]) + arr[i][j];  
            }
            else 
            {
              dp[i][j] = max(dp[i+1][j-1],max( dp[i][j-1], dp[i-1][j-1])) + arr[i][j];  
            }
            max_ = max(max_,dp[i][j]);
            cout<<i<<" "<<j<<" " << dp[i][j]<<endl;
        }
    }
    cout<<"dp"<<endl;
    for(int i=0;i<dp.size();i++)
    {
        for(int j=0;j<dp[0].size();j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<max_;
    return max_;
}
int main()
{
    vector<vector<int>> v{{1,3,3},{2,1,4},{0,6,4}};
    cout<<"ece"<<v.size()<<" "<<v[0].size()<<endl;
    cout<<goldmine(v);
}