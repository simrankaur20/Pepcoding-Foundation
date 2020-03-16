#include<bits/stdc++.h>
using namespace std;

int rod_cut_rec(vector<int> &len, vector<int> &price, int st, int end, int tar)
{
    if(st == end || tar == 0)
    {
        return 0;
    }
    int max_ = -1e8;
    for(int i= st ; i <= end; i++){
        int right = rod_cut_rec(len,price, i+1, end, tar - i);
        max_ = max(max_, right+ price[i]);
    }
    return max_;
}

int rod_cut_dp(vector<int> &len, vector<int> &price)
{
    vector<int> dp(len.size(),0);
    dp[0] = price[0];
    cout<<dp[0]<<" ";
    for(int i=1;i<len.size() ; i++)
    {
        int tar = i;
        dp[i]=price[i];
        for(int j =0;j<i;j++)
        {
            dp[i] = max(dp[i] , dp[j] + dp[tar - j-1]);
        }
        cout<<dp[i]<<" ";
    }
    return dp[len.size() -1];
}
int main()
{
    vector<int> len{1,2,3,4,5,6,7,8} , price{1,5,8,9,10,17,17,20};

    cout<<rod_cut_dp(len,price);
}