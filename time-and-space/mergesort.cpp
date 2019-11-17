#include<bits/stdc++.h>
using namespace std;
vector<int> merge(vector<int> &ar1, vector<int> &ar2)
{
    int m = ar1.size() , n = ar2.size();
    int i = 0 , j  = 0 ;
    vector<int> ans;
    while( i < m && j < n )
    {
        if(ar1[i] < ar2[j])
        {
            ans.push_back(ar1[i++]);
        }
        else
        {
            ans.push_back(ar2[j++]);
        } 
    }  
    while(i < m)
    {
        ans.push_back(ar1[i++]);
    }
    while(j<n)
    {
        ans.push_back(ar2[j++]);
    }
    return ans;
} 

vector<int> mergesort(vector<int> ar, int si , int ei)
{
    if(si == ei)
    {
        vector<int> v{ar[si]};
        return v;
    }
    int mid = (si + ei)/2;
    vector<int> l = mergesort(ar, si,mid);
    vector<int> r =  mergesort(ar,mid+1, ei);
    return merge(l,r);
}

void sort_01(vector<int> &a)
{
    int zp = 0,  tp = a.size() -1 ;
    while(zp < tp)
    {
        if(a[zp] == 0)
        {
            zp++;
        }
        else if(a[tp] == 1)
        {
            tp--;
        }
        else
        {
            swap(a[zp] , a[tp] );
            zp++;
            tp--;
        }
    }

}
int main()
{
    vector<int> v1{1,9,8,6,4,8,6,0,3} , v2{1,1,0,0,0,1};
    //vector<int> r = mergesort(v1,0,v1.size()-1);
    sort_01(v2);
    for(int i : v2)
    {
        cout<< i<<" ";
    }
}