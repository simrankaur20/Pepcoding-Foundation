#include<bits/stdc++.h>
using namespace std;
bool isvalid(vector<vector<bool>> & boxes,int x , int y)
{

    int n = boxes.size();
    int m = boxes[0].size();

    if(x <0 || x >= n)
    {
        return false;
    }

    if(y < 0 || y >= m || boxes[x][y])
    {
        return false;
    }
    //row check
    for(int i = y-1; i >=0;i--)
    {
        if(boxes[x][i])
        {
            return false;
        }
    }

    for(int i =  x-1;i>=0;i--)
    {
        if(boxes[i][y])
        {
            return false;
        }
    }

    for(int i = x-1, j = y-1;i>=0 && j>=0;i--,j--)
    {
        if(boxes[i][j])
        {
            return false;
        }
    }

    for(int i = x-1,j = y+1 ;i>=0 && j<m ; i--,j++)
    {
        if(boxes[i][j])
        {
            return false;
        }
    }
    
    return true;
}
int queencomb(vector<vector<bool>> &boxes,int idx,int qpsf,int tq,string ans)
{
    
    int n = boxes.size();
    int m = boxes[0].size();
    if(qpsf == tq || idx == n*m)
    {
        if(qpsf == tq)
        {
            cout<<ans<<endl;
            return 1;
        }
        return 0;
    }
    
    int count = 0;

    for(int i = idx ; i < n * m ; i++)
    {
        int r  = i / m;
        int c = i % m;
        if(isvalid(boxes, r , c))
        {
            boxes[r][c] = true;
            count += queencomb(boxes,i+1,qpsf + 1,tq , ans + " b " + to_string(i+1) + " q " + to_string(qpsf));
            boxes[r][c] = false;
        }
    }
    return count;
}



// subsequence method -> box has option vo queen ko baithana chahta h ya nhi
int queen_comb_subsq(vector<vector<bool>> & boxes, int qpsf,int tq,int idx, string ans)
{
    int n = boxes.size();
    int m = boxes[0].size();
    if(qpsf == tq || idx == n*m)
    {
        if(qpsf == tq)
        {
            cout<< ans<<endl;
            return 1;
        }
        return 0;
    }

    int count = 0;
        int r = idx / m;
        int c = idx % m;
        if(isvalid(boxes, r, c))
        {
            boxes[r][c] = true;
            count += queen_comb_subsq(boxes, qpsf +1 , tq , idx+1 , ans + " q " + to_string(qpsf) + " b " + to_string(r) + " " + to_string(c) );
            boxes[r][c] = false;   
        }
         count += queen_comb_subsq(boxes, qpsf , tq, idx+1, ans);
    return count;
}

void queencombbase()
{
    vector<vector<bool>> boxes(4,vector<bool>(4,false));
    cout << queen_comb_subsq(boxes,0,4,0,"");
}
int main()
{
    queencombbase();
}