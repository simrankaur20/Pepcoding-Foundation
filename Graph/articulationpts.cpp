#include<bits/stdc++.h>
using namespace std;
class Edge{
    int u,wt;
    Edge(int u, int wt)
    {
        this->u = u;
        this->wt = wt;
    }
};

vector<vector<Edge*>> graph(7, vector<Edge*>());

void addEdge(int u, int v, int w)
{
    if(u <0 || v < 0 || u>= graph.size() || v>= graph.size())
    {
        return ;
    }
    graph[u].push_back(new Edge(v,w));
    graph[v].push_back(new Edge(u,w));
}

int articulationpoint(int vtx, int src, int &time, vector<bool> &pts, vector<int> &dis, vector<int> &par, vector<int> &low)
{
    int root = 0;
    dis[vtx] = time+1;
    low[vtx] = time + 1;
    time++;
    for(Edge * e : graph[vtx])
    {
        if(dis[e->u] == -1)
        {
            par[e->u] = vtx;
            if(par[vtx] == -1)
            {
                root++;
            }
            articulationpoint(e->u, src, time,pts,dis,par,low);
        }
    }   

}
int main()
{
    vector<bool> pts(graph.size() , false);
    vector<int> dis(graph.size(),-1), par(graph.size(), 0), low(graph.size(),0);
    int time = 0;
    par[0] = -1;
}