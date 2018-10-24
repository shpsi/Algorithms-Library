#include<bits/stdc++.h>
using namespace std;
#define NIL -1
#define INF 99999999
int cont;
class Graph
{
    int V;
    vector <pair< int , pair<int ,int> > > adj;
public:
    Graph(int V);
    void addedge(int u,int v,int w);
    void bellman(int src);
};
Graph::Graph(int V)
{
    this->V=V;
}
void Graph::addedge(int u,int v,int w)
{
    adj.push_back(make_pair(u,make_pair(v,w)));
    cont++;
}
void Graph::bellman(int src)
{
    int * dist= new int[V];
    int * par=new int[V];
    for(int i=0;i<V;i++)
    {
        if(i==src) dist[i]=0;
        else   dist[i]=INF;
        if(i==src) par[i]=NIL;
    }
    for(int cnt=0;cnt<=V-1;cnt++)
    {
        for(int it=0;it<cont;it++)
        {
            int fir=adj[it].first;
            int sec=adj[it].second.first;
            int wht=adj[it].second.second;
            if(dist[sec]>dist[fir]+wht)
            {
                dist[sec]=dist[fir]+wht;
                par[sec]=fir;
            }
        }
    }
    for(int it=0;it<cont;it++)
    {
       int fir=adj[it].first;
       int sec=adj[it].second.first;
       int wht=adj[it].second.second;
       if(dist[sec]>dist[fir]+wht)
       {
          cout<<"negetive cycle\n";
          return ;
       }
    }
    for(int i=0;i<V;i++)
        cout<<i<<" "<<dist[i]<<" "<<par[i]<<endl;
    cout<<endl;
}
int main()
{
    Graph g1(5);
    g1.addedge(0,3,8);
    g1.addedge(3,4,2);
    g1.addedge(4,3,1);
    g1.addedge(2,4,4);
    g1.addedge(1,2,-3);
    g1.addedge(0,2,5);
    g1.addedge(0,1,4);
    g1.bellman(0);
    return 0;
}
