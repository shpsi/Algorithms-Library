#include<bits/stdc++.h>
using namespace std;
#define NIL -1
#define INF 0x3f3f3f3f
class Graph
{
    int V;
    list<pair<int ,int > > *adj;
    int *par;
    int *dist;
public:
    Graph(int V);
    void addedge(int v,int w,int hk);
    void djkstra(int src);
};
Graph::Graph(int V)
{
    this->V=V;
    par=new int[V];
    dist=new int[V];
    memset(par,NIL,sizeof(int)*V);
    memset(dist,INF,sizeof(int)*V);
    adj= new list<pair<int ,int > >[V];
}
void Graph::djkstra(int src)
{
    set<pair<int,int> > sd;
    dist[src]=0;
    sd.insert(make_pair(0,src));
    dist[src]=0;
    while(!sd.empty())
    {
        pair< int, int > tmp = *(sd.begin());
        sd.erase(sd.begin());
        int u=tmp.second;
        list< pair<int, int> >::iterator i;
        for(i=adj[u].begin(); i != adj[u].end(); ++i)
        {
            int v=(*i).first;
            int wht=(*i).second;
            if(dist[v]>dist[u]+wht)
            {
                if(dist[v]==INF)
                  par[v]=u,dist[v]=dist[u]+wht,sd.insert(make_pair(dist[v],v));
                else
                  sd.erase(sd.find(make_pair(dist[v],v))),sd.insert(make_pair(dist[u]+wht,v)),par[v]=u,dist[v]=dist[u]+wht;
            }
        }
    }
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}
void Graph::addedge(int v,int w,int hk)
{
    adj[v].push_back(make_pair(w,hk));
    adj[w].push_back(make_pair(v,hk));
}
int main()
{
    Graph g1(6);
    g1.addedge(0,1,5);
    g1.addedge(1,2,2);
    g1.addedge(2,3,3);
    g1.addedge(3,0,9);
    g1.addedge(3,5,2);
    g1.addedge(4,5,3);
    g1.addedge(4,0,2);
    g1.djkstra(0);
    return 0;
}
