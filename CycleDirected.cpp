#include<bits/stdc++.h>
using namespace std;
#define NIL -1
#define white 1
#define gray 1
#define black 2
int flag;
bool vis[10000];
class Graph
{
    int V;
    list<int> *adj;
public:
    Graph(int V);
    void addedge(int v,int w);
    void dfs(int src);
};
Graph::Graph(int V)
{
    this->V=V;
    adj= new list<int>[V];
}
void Graph::addedge(int v,int w)
{
    adj[v].push_back(w);
}
void Graph::dfs(int src)
{
    vis[src]=gray;
    list<int>::iterator it;
    for(it=adj[src].begin();it!=adj[src].end();it++)
    {
        if(vis[*it]==gray)
            flag=1;
        else if(vis[*it]==white)
        {
            dfs(*it);
        }
    }
    vis[src]=black;
}
int main()
{
    Graph g1(6);
    g1.addedge(0,1);
    g1.addedge(1,2);
    g1.addedge(0,2);
    g1.addedge(3,0);
    g1.addedge(3,4);
    g1.addedge(4,5);
    g1.addedge(5,3);
    int i;
    for(i=0;i<6;i++)
        vis[i]=white;
    for(i=0;i<6;i++)
    {
        if(vis[i]==white)
          g1.dfs(i);
    }
    if(flag)
        cout<<"cycle\n";
    else
        cout<<"nothing\n";
    return 0;
}
