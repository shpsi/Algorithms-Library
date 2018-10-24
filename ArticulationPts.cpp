#include<bits/stdc++.h>
using namespace std;
#define NIL -1
int timer;
class Graph
{
    int V;
    list<int> *adj;
    void APUtil(int v,bool visited[],int disc[],int low[],int par[],bool ap[]);
public:
    Graph(int V);
    void addedge(int v,int w);
    void Ap();
};
Graph::Graph(int V)
{
    this->V=V;
    adj= new list<int>[V];
}
void Graph::addedge(int v,int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}
void Graph::APUtil(int v,bool visited[],int disc[],int low[],int par[],bool ap[])
{
    timer++;
    disc[v]=timer;
    visited[v]=true;
    int child=0;
    low[v]=timer;
    list<int>::iterator it;
    for(it=adj[v].begin();it!=adj[v].end();it++)
    {
        int u=*it;
        if(!visited[u])
        {
            child++;
            par[u]=v;
            APUtil(u,visited,disc,low,par,ap);
            low[v]=min(low[v],low[u]);
            if(par[v]==NIL && child>=2)
                ap[v]=true;
            if(par[v]!=NIL && disc[v]<=low[u])
                ap[v]=true;
        }
        else
        {low[v]=min(low[v],disc[u]);}
    }
}
void Graph::Ap()
{
    bool * visited;
    visited= new bool[V];
    int * disc;
    disc= new int[V];
    int * low;
    low= new int[V];
    int * par;
    par= new int[V];
    bool * ap;
    ap= new bool[V];
    for(int i=0;i<V;i++)
    {
        ap[i]=false;
        par[i]=NIL;
        visited[i]=false;
    }
    for(int i=0;i<V;i++)
    {
        if(visited[i]==false)
            APUtil(i,visited,disc,low,par,ap);
    }
    for(int i=0;i<V;i++)
    {
        if(ap[i]==true)
            cout<<i<<" ";
    }
    cout<<endl;
}
int main()
{
  cout << "\nArticulation points in first graph \n";
    Graph g1(5);
    g1.addedge(1, 0);
    g1.addedge(0, 2);
    g1.addedge(2, 1);
    g1.addedge(0, 3);
    g1.addedge(3, 4);
    g1.Ap();

    cout << "\nArticulation points in second graph \n";
    Graph g2(4);
    g2.addedge(0, 1);
    g2.addedge(1, 2);
    g2.addedge(2, 3);
    g2.Ap();

    cout << "\nArticulation points in third graph \n";
    Graph g3(7);
    g3.addedge(0, 1);
    g3.addedge(1, 2);
    g3.addedge(2, 0);
    g3.addedge(1, 3);
    g3.addedge(1, 4);
    g3.addedge(1, 6);
    g3.addedge(3, 5);
    g3.addedge(4, 5);
    g3.Ap();
    return 0;
}
