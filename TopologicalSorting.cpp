#include<bits/stdc++.h>
using namespace std;
#define white 1
#define gray 2
#define black 3
#define NIL -1
int vis[1000];
stack<int>res;
class Graph
{
    int V;
    list<int> *adj;
public:
    Graph(int V);
    void addedge(int v,int w);
    void topsort(int u);
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
void Graph::topsort(int u)
{
   //  cout<<u<<" ";
    vis[u]=gray;
    list<int>::iterator it;
    for(it=adj[u].begin();it!=adj[u].end();it++)
    {
        if(vis[*it]==white)
            topsort(*it);
    }
    vis[u]=black;
    res.push(u);
}
int main()
{
    Graph g1(8);
    g1.addedge(0,2);
    g1.addedge(1,2);
    g1.addedge(1,3);
    g1.addedge(2,4);
    g1.addedge(3,5);
    g1.addedge(4,5);
    g1.addedge(4,7);
    g1.addedge(5,6);
    for(int i=0;i<10;i++)
        vis[i]=white;
    for(int i=0;i<8;i++)
        if(vis[i]==white)
           g1.topsort(i);
    while(!res.empty())
    {
        cout<<res.top()<<" ";
        res.pop();
    }
    return 0;
}
