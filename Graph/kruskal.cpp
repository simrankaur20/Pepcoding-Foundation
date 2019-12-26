#include<bits/stdc++.h>
using namespace std;
vector<int> parent= {} , sze = {1};
class edge{
    public:
    int u ;
    int wt;
    edge(int u, int wt)
    {
        this->u = u;
        this->wt = wt;
    }
};
vector<vector<edge*>> graph(7,vector<edge*>());

void addEdge(int u, int v,int wt)
{
    if(u < 0 || v < 0 || u >= graph.size() || v>= graph.size()) 
    {
        return ;
    }
    graph[u].push_back(new edge(v,wt));
    graph[v].push_back(new edge(u,wt));
}

void display()
{
    for(int i = 0 ; i < graph.size() ; i++)
    {
        cout<< i << " => ";
        for(int j = 0 ; j  < graph[i].size() ; j++)
        {
            cout<<" ( " << graph[i][j]->u << " , " << graph[i][j]->wt << " ) ";
        }
        cout<<endl;
    }
}



class Edge{
    public:
    int u,v,w;
    Edge(int x , int y, int z)
    {
        u = x;
        v = y;
        w = z;
    }
};

class mycomp
{
    public:
    int operator() (const Edge e1, const Edge e2)
    {
        return e1.w > e2.w;
    }
};
int find(int vtx)
{
    if(parent[vtx] != vtx)
    {
        parent[vtx] = find(parent[vtx]);
        return parent[vtx];
    }
    else
    {
        return vtx;
    }
}

void Union(int pt1,int pt2)
{
    if(sze[pt1] <= sze[pt2])
    {
        parent[pt1] = pt2;
        sze[pt2] += sze[pt1];
    }
    else
    {
        parent[pt2] = pt1;
        sze[pt1] += sze[pt2];
    }
    
}
void kruskal(priority_queue<Edge,vector<Edge>,mycomp> &pq)
{
    while(!pq.empty())
    {
        Edge curr = pq.top();
        cout<<"Processing " << curr.u<<" " << curr.v<<" "<< curr.w<<endl;
        pq.pop();
        int pt1 = find(curr.u);
        int pt2 = find(curr.v);
        if(pt1 != pt2)
        {
            addEdge(curr.u,curr.v,curr.w);
            cout<<"edge added"<<endl;
            Union(pt1,pt2);
        } 
       // cout<<"end if"<<endl;
    }
    display(); 

}
int main()
{
    for(int i = 0 ; i < graph.size() ; i++)
    {
        parent.push_back(i);
    }

    int n;
    cin>>n;
    
    priority_queue<Edge,vector<Edge>, mycomp> pq;
    for(int i = 0 ; i < n ; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        pq.push(Edge(u,v,w));
    }

    kruskal(pq);
}
