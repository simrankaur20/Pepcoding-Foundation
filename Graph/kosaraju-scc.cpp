#include<bits/stdc++.h>
using namespace std;
void top_sort(int src,vector<int> adj[],vector<bool> &vis, stack<int> &st)
{
    vis[src] = true;
    for(int i =0 ; i < adj[src].size();i++)
    {
        if(!vis[adj[src][i]])
         top_sort(adj[src][i] , adj,vis,st);
    }
    st.push(src);
}

void top_sort_main(vector<int> adj[],int V, stack<int> &st)
{
    vector<bool> vis(V, false);
    for( int i = 0 ; i  <V; i++)
    {
        if(!vis[i])
        {
            top_sort(i,adj,vis,st);
        }
    }
}
void dfs(int src,vector<int> adj[],vector<bool> &vis)
{
    vis[src] = true;
    for(int i =0 ; i < adj[src].size();i++)
    {
        if(!vis[adj[src][i]])
         dfs(adj[src][i] , adj,vis);
    }
}

int dfs_trans(vector<int> tgraph[], stack<int> &st,int V)
{
    vector<bool> vis(V,false);
    int c =0;
    while(!st.empty())
    {
        int x = st.top();
        st.pop();
        if(!vis[x])
        {
            dfs(x,tgraph,vis);
            c++;
        }
    }
    return c;
}
void compute_transpose(int V, vector<int> adj[],vector<int> tgraph[])
{
    for(int i =0;i<V;i++)
    {
        for(int j = 0 ; j < adj[i].size() ; j++)
        {
            int u = i;
            int v = adj[i][j];
            tgraph[v].push_back(u);
        }
    }
}

void display(vector<int> adj[], int V)
{
    for(int i = 0 ; i  <V;i++)
    {
        cout<<i<<" ";
        for(int j = 0 ; j < adj[i].size() ; j++)
        {
            cout<<"( " << adj[i][j]<<" ) ";
        }
        cout<<endl;
    }
}
int kosaraju(int V, vector<int> adj[])
{
    stack<int> st;
    top_sort_main(adj,V,st);
    vector<int> tadj[V];
    compute_transpose(V, adj, tadj);
   // display(tadj, V);
    return dfs_trans(tadj,st,V);
}

int main()
{
    
}
