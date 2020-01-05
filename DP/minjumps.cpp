#include<bits/stdc++.h>
using namespace std;
#define def pow(10,6)
int minjumps_rec(int s, int d, vector<int> &arr)
{
    if(s == d){
        return 0;
    }
    int count = 1000;
    for(int i = 1; i <=arr[s]; i++)
    {
        count = min(count, minjumps_rec(s + i,d,arr));
    }
    return count + 1;
}

int minjumps_tab(int s, int d, vector<int> &arr)
{
    vector<int>dp(10);
    dp[d] = 0;
    for(int i = 8; i>=0; i--)
    {
        int min1 = def;
        for(int j = i+1, c= 1; j < arr.size() && c <= arr[i]; j++, c++)
        {
            min1 = min(min1, dp[j]) ;
          //  cout<<"ececuting";
        }
        dp[i] = min1 + 1;
    }
    for(int i : dp)
    {
        cout<<i<< " ";
    }
    return dp[0];
}

int main()
{
    vector<int> arr{1,3,0,4,0,0,2,1,1,0};
    cout<<minjumps_tab(0,9,arr);
}