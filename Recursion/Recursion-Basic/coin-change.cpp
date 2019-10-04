#include<bits/stdc++.h>
using namespace std;
int combination_with_repition(vector<int> & arr, int target , int idx, string ans )
{
    if(idx == arr.size() || target == 0)
    {
        if(target == 0)
        {
            cout<<ans<<endl;
            return 1;
        }
        return 0;
    }
    int count = 0;
    for(int i = idx ; i < arr.size() ; i++)
    {
       if(target - arr[i] >= 0)
        count += combination_with_repition(arr , target - arr[i] , i , ans + to_string(arr[i]) + " ");
    }
    return count;
}



int permutation_with_repition(vector<int> & arr, int target , int idx, string ans )
{
    if(idx == arr.size() || target == 0)
    {
        if(target == 0)
        {
            cout<<ans<<endl;
            return 1;
        }
        return 0;
    }
    int count = 0;
    for(int i = 0 ; i < arr.size() ; i++)
    {
       if(target - arr[i] >= 0)
        count += permutation_with_repition(arr , target - arr[i] , i , ans + to_string(arr[i]) + " ");
    }
    return count;
}




int combination_without_repition(vector<int> & arr, int target , int idx, string ans )
{
    if(idx == arr.size() || target == 0)
    {
        if(target == 0)
        {
            cout<<ans<<endl;
            return 1;
        }
        return 0;
    }
    int count = 0;
    for(int i = idx ; i < arr.size() ; i++)
    {
       if(target - arr[i] >= 0)
        count += combination_without_repition(arr , target - arr[i] , i + 1 , ans + to_string(arr[i]) + " ");
    }
    return count;
}


int permutation_without_repition(vector<int> & arr, int target , string ans , vector<bool> & isdone)
{
    if(target == 0)
    {
    
        cout<<ans<<endl;
        return 1;
        
    }
    int count = 0;
    for(int i = 0 ; i < arr.size() ; i++)
    {
      
       if(target - arr[i] >= 0 && !isdone[i])
        {
           isdone[i] = true; 
            count += permutation_without_repition(arr , target - arr[i] , ans + to_string(arr[i]) + " " , isdone);
            isdone[i] =false;
        }
    }
    return count;
}

//subsequence method
int subsq_comb_with_repition(vector<int> & arr , int idx , int tar , string ans)
{
    if(idx == arr.size() || tar == 0)
    {
        if(tar == 0)
        {
            cout<<ans<<endl;
            return 1;
        }
        return 0;
    }   
    
    int count = 0;
    if(tar - arr[idx] >=0)
    {
        count += subsq_comb_with_repition(arr , idx  , tar - arr[idx] , ans + to_string(arr[idx]) + " ");
    }
    count += subsq_comb_with_repition(arr , idx + 1 , tar , ans);

    return count;
}


int subsq_permu_with_repition(vector<int> & arr , int idx , int tar , string ans)
{
    if(idx == arr.size() || tar == 0)
    {
        if(tar == 0)
        {
            cout<<ans<<endl;
            return 1;
        }
        return 0;
    }   
    
    int count = 0;
    if(tar - arr[idx] >=0)
    {
        count += subsq_permu_with_repition(arr , 0  , tar - arr[idx] , ans + to_string(arr[idx]) + " ");
    }
    count += subsq_permu_with_repition(arr , idx + 1 , tar , ans);

    return count;
}

int subsq_comb_without_repition(vector<int> & arr , int idx , int tar , string ans)
{
    if(idx == arr.size() || tar == 0)
    {
        if(tar == 0)
        {
            cout<<ans<<endl;
            return 1;
        }
        return 0;
    }   
    
    int count = 0;
    if(tar - arr[idx] >=0)
    {
        count += subsq_comb_without_repition(arr , idx + 1 , tar - arr[idx] , ans + to_string(arr[idx]) + " ");
    }
    count += subsq_comb_without_repition(arr , idx + 1 , tar , ans);

    return count;
}


int subsq_permu_without_repition(vector<int> & arr , int idx , int tar , string ans , vector<bool> & isdone)
{
    if(idx == arr.size() || tar == 0)
    {
        if(tar == 0)
        {
            cout<<ans<<endl;
            return 1;
        }
        return 0;
    }   
    
    int count = 0;
    if(tar - arr[idx] >=0 && !isdone[idx])
    {
        isdone[idx] = true;
        count += subsq_permu_without_repition(arr , 0 , tar - arr[idx] , ans + to_string(arr[idx]) + " ", isdone);
        isdone[idx] = false;
    }
    count += subsq_permu_without_repition(arr , idx + 1 , tar , ans, isdone);

    return count;
}




void coinchange()
{
    vector<int> arr { 2,3,5,7};
    vector<bool> isdone(4,false);
    int t  = 10;
    cout << subsq_permu_without_repition(arr , 0 , t , "" , isdone);
    //cout<<combination_with_repition(arr,10,0,"");
}
int main()
{
    coinchange();
}