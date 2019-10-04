#include<bits/stdc++.h>
using namespace std;

bool isvalid(vector<vector<bool>>& isdone , int x , int y)
{
    if(x < 0 || y < 0 || x >= isdone.size() || y >= isdone[0].size() || isdone[x][y])
    {
        return false;
    }
    return true;
}

int floodfill(vector<vector<bool>> &isdone , int sr , int sc , int er , int ec , string ans)
{
    if(sr == er && sc == ec)
    {
      //cout<<"base ";
        cout<<ans<<endl;
        return 1;
    }

    isdone[sr][sc] = true;
    int count = 0;
    if(isvalid(isdone , sr  +1 , sc ))
    {
        count += floodfill(isdone , sr+1, sc, er,ec, ans+ "D");
    }
    
    if(isvalid(isdone , sr-1 , sc ))
    {
        count += floodfill(isdone , sr-1, sc, er,ec, ans+ "U");
    }
    
    if(isvalid(isdone , sr , sc+1 ))
    {
        count += floodfill(isdone , sr, sc+1, er,ec, ans+ "R");
    }
    
    if(isvalid(isdone , sr , sc-1 ))
    {
        count += floodfill(isdone , sr, sc-1, er,ec, ans+ "L");
    }
    
    if(isvalid(isdone , sr-1 , sc-1 ))
    {
        count += floodfill(isdone , sr-1, sc-1, er,ec, ans+ "UL");
    }
    
    if(isvalid(isdone , sr+1 , sc-1 ))
    {
        count += floodfill(isdone , sr+1, sc-1, er,ec, ans+ "DL");
    }

    if(isvalid(isdone , sr+1 , sc+1 ))
    {
        count += floodfill(isdone , sr+1, sc+1, er,ec, ans+ "UR");
    }

    if(isvalid(isdone , sr-1 , sc+1 ))
    {
        count += floodfill(isdone , sr-1, sc+1, er,ec, ans+ "DR");
    }
    isdone[sr][sc] = false;
    return count;
}


//computing maximum height of the recursion tree

// int floodfill(vector<vector<bool>> &isdone , int sr , int sc , int er , int ec , string ans)
// {
//     if(sr == er && sc == ec)
//     {
//       //cout<<"base ";
//         cout<<ans<<endl;
//         return 0;
//     }

//     isdone[sr][sc] = true;
//     int max_ = 0;
//     if(isvalid(isdone , sr  +1 , sc ))
//     {
//         max_ = max(max_,floodfill(isdone , sr+1, sc, er,ec, ans+ "D"));
//     }
    
//     if(isvalid(isdone , sr-1 , sc ))
//     {
//          max_ = max(max_,floodfill(isdone , sr-1, sc, er,ec, ans+ "D"));
//     }
    
//     if(isvalid(isdone , sr , sc+1 ))
//     {
//          max_ = max(max_,floodfill(isdone , sr, sc+1, er,ec, ans+ "D"));
//     }
    
//     if(isvalid(isdone , sr , sc-1 ))
//     {
//          max_ = max(max_,floodfill(isdone , sr, sc-1, er,ec, ans+ "D"));
//     }
    
//     isdone[sr][sc] = false;
//     return max_ + 1;
// }

int floodfill_(vector<vector<bool>> & isdone,int sr, int sc,int er,int ec, string ans)
{
    if(sr == er && sc == ec)
    {
        cout<<ans<<endl;
        return 1;
    }

    int count = 0;
    isdone[sr][sc] = true;

    string dir[] = {"r" , "l" , "u" , "d" , "a" , "b" , "c" , "d"} ;
    int dim[][2] = {{0,1},{0,-1},{1,0}, {-1,0} , {-1,-1} , {1,-1} , {1,1} ,{-1,1}};

    for(int d = 0; d< 8; d++)
    {
        count += (isvalid(isdone,sr+dim[d][0] , sc+dim[d][1])
         ? floodfill_(isdone , sr + dim[d][0] , sc + dim[d][1] , er, ec , ans + dir[d]) 
         : 0);
    }

    isdone[sr][sc] = false;
    return count;
}
int main()
{
    vector<vector<bool>> v(3, vector<bool>(4,false));
    //cout<< " executing" <<endl;
    cout<< "Count : " << floodfill_(v , 0 , 0 , 2, 3, "");
}