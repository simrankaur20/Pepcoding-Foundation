#include<bits/stdc++.h>
using namespace std;
bool isrowsafe(vector<vector<int>> &boxes,int x ,int y , int num)
{
    for(int i = 0 ; i < 9 ; i++)
    {
        if(boxes[x][i] == num)
        {
            return false;
        }
    }
    return true;
}

bool iscolsafe(vector<vector<int>> &boxes,int x ,int y , int num)
{
    for(int i = 0 ; i <  9 ; i++)
    {
        if(boxes[i][y] == num)
        {
            return false;
        }
    }
    return true;
}

bool isboxsafe(vector<vector<int>> &boxes,int x ,int y , int num)
{
        int rs = x / 3 * 3;
        int cs = y/3 * 3;
        int re = rs +2;
        int ce = cs + 1;

    for(int i = rs; i<=re;i++)
    {
        for(int j = cs; j<= ce; j++)
        {
            if(boxes[i][j] == num)
            {
                return false;
            }
        }
    }
    return true;
}

//bits
bool bits_populate(vector<vector<int>> &boxes, int row, int col ,int mat[][3])
{
    for(int i = 0 ; i < 9; i++)
    {
        for(int j = 0 ; j < 9 ; j++)
        {
            if(boxes[i][j] == 0)
            {
                
            }
            
            int mask = 1 << boxes[i][j];
            
        }
    }
}
bool issafe(vector<vector<int>> & boxes , int x,int y, int num)
{
    return  isrowsafe(boxes, x , y , num) && iscolsafe(boxes , x , y, num) && isboxsafe(boxes, x, y, num);
}

void display(vector<vector<int>> & boxes)
{
    for(int i = 0 ; i <  9 ; i ++)
    {
        for(int j = 0 ; j  < 9 ; j++)
        {
            cout<<boxes[i][j] << " ";
        }
        cout<<endl;
    }
    cout << endl;
}
int sudoku( vector<vector<int>> &boxes , int vidx)
{
    if(vidx == 81)
    {
        display(boxes);
        return 1;
    }

    int r = vidx / 9;
    int c = vidx % 9;
    int count = 0;
     
    if(boxes[r][c] == 0)
    {
        for(int i = 1 ; i <= 9 ; i++)
        {
            if(issafe(boxes,r,c, i))
            {
                boxes[r][c] = i;
                count += sudoku(boxes, vidx + 1);
                boxes[r][c] = 0;
            }
        }
    }
    else
    {
        count += sudoku(boxes, vidx + 1);
    }
    return count;

}

int main()
{
    vector<vector<int>> boxes = {{3,0,6,5,0,8,4,0,0},
                                {5,2,0,0,0,0,0,0,0},
                                {0,8,7,0,0,0,0,3, 1},
                                {0,0,3,0,1,0,0,8,0},
                                {9,0,0,8,6,3,0,0,5},
                                {0,5,0,0,9,0,6,0,0},
                                {1,3,0,0,0,0,2,5,0},
                                {0,0,0,0,0,0,0,7,4},
                                {0,0,5,2,0,6,3,0,0}};
    cout << sudoku(boxes,0);
}