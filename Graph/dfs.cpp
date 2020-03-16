void dfs(int s, vector<int> g[], bool vis[])
{
    if(vis[s])
    {
        return;
    }
    
    cout<<s<< " ";
    vis[s] = true;
    for(int i = 0; i  < g[s].size(); i++)
    {
     if(!vis[g[s][i]])
     {
         dfs(g[s][i], g , vis);
         
     }
    }

}