#include<bits/stdc++.h>
using namespace std;
class Edge{
    public:
    int u,wt;
    Edge(int u, int wt)
    {
        this->u = u;
        this->wt = wt;
    }
};
vector<vector<Edge*>> graph(7,vector<Edge*>());

void addEdge(int u, int v, int w)
{
    if(u<0 || v<0 || u>=graph.size() || v>= graph.size())
    {
        return;
    }
    graph[u].push_back(new Edge(v,w));
}

void display()
{
    for(int i = 0 ; i < graph.size() ; i++)
    {
        for(int j = 0 ; j < graph[i].size();j++)
        {
            cout<< i<< "-> " << graph[i][j]->u <<" @ "<< graph[i][j]->wt<<endl;
        }
    }
}

void tsort_dfs(int src, vector<bool> &visited, stack<int> &s)
{
    visited[src] = true;
    for(Edge * e: graph[src])
    {
        if(!visited[e->u])
        {
            tsort_dfs(e->u, visited,s);
        }
    }
    s.push(src);
}
void topologicalsort()
{
    vector<bool> visited(7,false);
    stack<int> ans;
    for(int i = 0 ; i < 7 ; i++)
    {
        if(!visited[i])
        tsort_dfs(i,visited,ans);
    }

    while(!ans.empty())
    {
        cout<<ans.top()<<" ";
        ans.pop();
    }
}


//Khan's Algorithm for Topological Sort
void tsort_khan()
{
    vector<int> inedges(graph.size(),0);

    for(int i = 0 ; i < graph.size() ; i++)
    {
        for(int j = 0 ; j < graph[i].size() ; j++)
        {
            inedges[graph[i][j]->u]++;
        }
    }
    queue<int> q;
    int counter =0;
    for(int i = 0; i < inedges.size() ; i++)
    {
        if(inedges[i] == 0)
        {
            q.push(i);
        }
       // cout<<i<<" "<<inedges[i]<<endl;
    }

    
    while(!q.empty())
    {
        int currv = q.front();
        q.pop();
        counter++;
        cout<<currv<<" ";
        for(int i = 0 ; i < graph[currv].size() ; i++)
        {
            int x = --inedges[graph[currv][i]->u];
            if(x == 0)
            {
                q.push(graph[currv][i]->u);
            }
        }
    }

    if(counter < graph.size())
    {
        cout<<"Cycle Present";
    }

}


int main()
{
        addEdge(0,3,10);
        addEdge(0,1,10);
        addEdge(1,2,10);
        addEdge(2,3,40);
        addEdge(3,4,2);
        addEdge(4,5,2);
        addEdge(4,6,3);
        addEdge(5,6,8);
        addEdge(0,6,10);
        display();
      //  topologicalsort();
        tsort_khan();
}