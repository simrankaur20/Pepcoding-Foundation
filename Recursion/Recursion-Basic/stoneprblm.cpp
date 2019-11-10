#include<bits/stdc++.h>
using namespace std;
long long findcost(vector<int> &arr,int idx, int n,int c, long * qb)
{
    
    if(idx>=n)
    {
        return 0;
    }
    long long cost = 9999999;
    if(qb[idx] != -1)
    {
        return qb[idx];
    }
    for(int i = 1; idx + i < n; i++)
    {
        long long currcost = findcost(arr, idx+i,n,c,qb);
        
        long long f1 = arr[idx+i];
        long long f2 = arr[idx];
        long long addcost = pow(f1-f2,2) + c;
       // cout<<"idx = " << idx << " currcost = "<< currcost << " tot cost = " << addcost<<endl;
        cost = min(cost, currcost + addcost);
        
    }
    if(cost != 9999999)
    {
        qb[idx] = cost;
    }
    return cost == 9999999 ? 0 : cost;
}
int main()
{
    long n,c;
    cin>>n>>c;
    vector<int> v(n);
    for(int i = 0; i < n ; i++)
    {
        cin>>v[i];
    }
    long * qb = new long[n+1];
    for(int i = 0 ; i < n+1;i++)
    {
        qb[i] = -1;
    }
    cout<<findcost(v,0,n,c,qb);
}