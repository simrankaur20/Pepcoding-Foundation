#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> mult(vector<vector<int>> const &mat1, vector<vector<int>> const &mat2)
{
    vector<vector<int>> ans(2, vector<int>(2, 0));
    for(int i=0;i<mat1.size();i++)
    {
        for(int j=0;j<mat2[0].size();j++)
        {
            int cans = 0;
            for(int k=0;k<mat1[0].size();k++)
            {
                cans += mat1[i][k]*mat2[k][j];
            }
            ans[i][j] = cans;
        }
    }
    return ans;
}

vector<vector<int>> power(vector<vector<int>> &mat,int b)
{
    if(b < 0)
    {
      vector<vector<int>> v;
        return v;
    }
    if(b == 1)
    {
        return mat;
    }
    
    if(b%2 == 0)
    {
        return mult(power(mat,b/2), power(mat,b/2));
    }
    else
    {
        return mult(mult (power(mat,b/2), power(mat,b/2)), mat); 
    }
}
vector<vector<int>> linearrec(int b)
{
    vector<vector<int>> mat{{1,1},{1,0}};

   return power(mat,b);
    
}
int main()
{
    vector<vector<int>> ans = linearrec(5);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[0].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
   // cout<<ans[0][1];
}