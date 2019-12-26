#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Edge{
    public:
    int u ;
    int wt;
    Edge(int u, int wt)
    {
        this->u = u;
        this->wt = wt;
    }
};
vector<vector<Edge*>> graph(7,vector<Edge*>());

void addEdge(int u, int v,int wt)
{
    if(u < 0 || v < 0 || u >= graph.size() || v>= graph.size()) 
    {
        return ;
    }
    graph[u].push_back(new Edge(v,wt));
    graph[v].push_back(new Edge(u,wt));
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

void removeedge(int u , int v)
{
    for(int i = 0 ; i < graph[u].size() ; i++)
    {
        if(graph[u][i]->u == v)
        {
            graph[u].erase(graph[u].begin() + i);
        }
    }

    for(int i = 0 ; i  < graph[v].size() ; i++)
    {
        if(graph[v][i]->u == u)
        {
            graph[v].erase(graph[v].begin() + i);
        }
    }
}

void removevertex(int u)
{
    for(int i = 0 ; i < graph[u].size();i++)
    {
        removeedge(u,graph[u][i]->u);
    }
    graph.erase(graph.begin() + u);
}
void solve()
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
        //display();
}

bool haspath(int s, int d , vector<bool> &visited, vector<int> &path)
{
    if(s == d)
    {
        path.push_back(d);
        return true;
    }
    
            visited[s] = true;
            path.push_back(s);
    for(int i = 0; i < graph[s].size() ; i++)
    {
        if(!visited[graph[s][i]->u])
        {
            
            bool r = haspath(graph[s][i]->u,d,visited,path);
            if(r)
            {
                return true;
            }
           
        }
    }
    return false;
}
bool haspathmain(int d , int s = 0)
{
    vector<int> path;
    vector<bool> visited(6,false);
    
    bool ans = haspath(s,d,visited,path);

    for(int i : path)
    {
        cout<<i << " ";
    }
return ans;
}

void printvector(vector<int> &path)
{
    for(int i : path)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}

bool printallpath(int s, int d , vector<bool> &visited, vector<int> &path)
{
    if(s == d)
    {
        path.push_back(d);
        printvector(path);
        cout<<"base case"<<endl;
        path.pop_back();
        return true;
    }
    
    visited[s] = true;
    path.push_back(s);
    bool r = false;
    for(int i = 0; i < graph[s].size() ; i++)
    {
        if(!visited[graph[s][i]->u])
        {
            
            r =  printallpath(graph[s][i]->u,d,visited,path) || r;
        }
    }

    visited[s] = false;
    path.pop_back();
    return r;
}

void preorder(int s, int d, vector<bool> & visited, string ans)
{
    visited[s] = true;
    cout<< s <<" => "<< ans + to_string(s)<<endl;
    for(Edge * e : graph[s])
    {
        int nbr = e->u;
        if(!visited[nbr])
        {
            preorder(nbr,d,visited, ans + to_string(s));
        } 
    }
    visited[s] = false;
}

void postorder(int s, int d, vector<bool> & visited, string ans)
{
    visited[s] = true;
    for(Edge * e : graph[s])
    {
        int nbr = e->u;
        if(!visited[nbr])
        {
            postorder(nbr,d,visited, ans + to_string(s));
        } 
    }
    cout<< s <<" => "<< ans + to_string(s)<<endl;
    visited[s] = false;
}

void shortestpath(int s, int d , vector<bool> &visited, string psf, string &lpath, int wt, int &minwt)
{
    if(s == d)
    {
        string curp = psf + to_string(d);
        if(wt < minwt)
        {
            lpath = psf;
            minwt = wt;
        }
        return ;
    }
    
    visited[s] = true;
    for(int i = 0; i < graph[s].size() ; i++)
    {
        if(!visited[graph[s][i]->u])
        {
            
            shortestpath(graph[s][i]->u,d,visited, psf + to_string(s) , lpath , wt + graph[s][i]->wt , minwt) ;
        }
    }

    visited[s] = false;
}


void longestpath(int s, int d , vector<bool> &visited, string psf, string &lpath, int wt, int &maxwt)
{
    if(s == d)
    {
        string curp = psf + to_string(d);
        if(wt > maxwt)
        {
            lpath = psf;
            maxwt = wt;
        }
        return ;
    }
    
    visited[s] = true;
    for(int i = 0; i < graph[s].size() ; i++)
    {
        if(!visited[graph[s][i]->u])
        {
            
            longestpath(graph[s][i]->u,d,visited, psf + to_string(s) , lpath , wt + graph[s][i]->wt , maxwt) ;
        }
    }

    visited[s] = false;
}

bool hamiltonionpath(int s, string psf, vector<bool> &visited, int count)
{
    if(count == visited.size()-1)
    {
        cout<<psf <<s <<endl;
        return true;
    }
    bool r = false;
    visited[s] = true;
    for(int i = 0; i < graph[s].size() ; i++)
    {
        if(!visited[graph[s][i]->u])
        {
            
            r = hamiltonionpath(graph[s][i]->u,psf + to_string(s) ,visited, count+1) || r;
        }
    }
    visited[s] = false;
    return r;
}

bool hamiltonioncycle(int s,int osrc, vector<bool> &visited, string psf, int count)
{
    if(count == graph.size() - 1)
    {
        cout<<psf<<s <<" ";
        for(Edge* e : graph[s])
        {
            if(e->u == osrc)
            {
                cout<<"cycle ";
                cout<<endl;
                return true;
            }
        }
        cout<<endl;
        return false;
    }
    visited[s] = true;
    bool r = false;
    for(Edge * e : graph[s])
    {
        if((!visited[e->u] ))
        {
            r = hamiltonioncycle(e->u , osrc, visited, psf + to_string(s) , count+1) || r;
        }
    }
    visited[s] = false;
    return r;
}
int main()
{
    solve();
    //removevertex(2);
    display();
    cout<<endl;
    vector<bool> visited(graph.size(),false);
    string path;

    cout<<"printing path"<<endl;
    bool x = hamiltonioncycle(0,0,visited,"",0);
    cout<<x <<endl;
}