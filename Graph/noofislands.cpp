#include <bits/stdc++.h>
using namespace std;

int findIslands(vector<int> A[], int N, int M);

int main() {

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<int> A[N];
        for (int i = 0; i < N; i++) {
            vector<int> temp(M);
            A[i] = temp;
            for (int j = 0; j < M; j++) {
                cin >> A[i][j];
            }
        }
        cout << findIslands(A, N, M) << endl;
    }
    return 0;
}


bool isvalid(int i, int j, int N, int M)
{
    if(i>=N || j >= M || i < 0 || j < 0)
    {
        return false;
    }
    return true;
}
void bfs(vector<int> A[] , vector<vector<bool>> &vis , int N, int M,int i, int j)
{
    queue<pair<int,int>> q;
    q.push(make_pair(i,j));
    vis[i][j] = true;
    int dirx[] = {-1,-1,-1,0,0,1,1,1};
    int diry[] = {-1,0,1,-1,1,-1,0,1};
    while(!q.empty())
    {
        pair<int,int> curr = q.front();
        q.pop();
        
        for(int i = 0 ; i < 8 ; i++)
        {
            int x = curr.first + dirx[i];
            int y = curr.second + diry[i];
            if(isvalid(x,y,N, M) && !vis[x][y] && A[x][y] == 1)
            {
                q.push(make_pair(x,y));
                vis[x][y] = true;
            }
        }
    }
    
}
int findIslands(vector<int> A[], int N, int M) {

    vector<vector<bool>> vis(N, vector<bool>(M,false));
    int cnt = 0;
    for(int i = 0 ; i <N; i++)
    {
        for(int j =0 ; j <M;j++)
        {
            if(!vis[i][j] && A[i][j] == 1)
            {
            
                bfs(A,vis,N,M,i,j);
                cnt++;
            }
        }
    }
    return cnt;
    
    
}