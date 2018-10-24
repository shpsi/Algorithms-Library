#include<bits/stdc++.h>
using namespace std;
#define NIL -1
int flag;
class Graph
{
    int V;
    bool *vis;
    list<int> *adj;
public:
    Graph(int V);
    void addedge(int v,int w);
    void dfs(int src);
};
Graph::Graph(int V)
{
    this->V=V;
    this->vis= new bool[V];
    memset(this->vis,false,sizeof(bool)*V);
    adj= new list<int>[V];
}
void Graph::addedge(int v,int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}
void Graph::dfs(int src)
{
    vis[src]=true;
    list<int>::iterator it;
    for(it=adj[src].begin();it!=adj[src].end();it++)
    {
        if(vis[*it])
            flag=1;
        else
        {
            dfs(*it);
        }
    }
}
int main()
{
    Graph g1(6);
    int m;
    cin>>m;
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        g1.addedge(a,b);
    }
    g1.dfs(0);
    if(flag)
        cout<<"cycle\n";
    else
        cout<<"nothing\n";
    return 0;
}
