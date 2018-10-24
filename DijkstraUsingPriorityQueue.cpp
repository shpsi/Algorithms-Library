#include<bits/stdc++.h>
using namespace std;
#define NIL -1
#define INF 0x3f3f3f3f
#define blck cout<<"----------------------\n";
#define dtype priority_queue<  pair< int ,int > , vector < pair< int ,int > > , greater< pair< int ,int > > >
class Graph
{
    int V;
    list<pair<int ,int > > *adj;
    int *par;
    int *dist;
    bool *ext;
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
    ext=new bool[V];
    memset(par,NIL,sizeof(int)*V);
    memset(dist,INF,sizeof(int)*V);
    memset(ext,false,sizeof(bool)*V);
    adj= new list<pair<int ,int > >[V];
}
void print()
{
    dtype a;
    a.push(make_pair(4,0));
    a.push(make_pair(3,0));
    a.push(make_pair(2,1));
    a.push(make_pair(1,1));
    a.push(make_pair(4,2));
    a.push(make_pair(1,3));
    while(!a.empty())
    {
        pair<int ,int >x=a.top();
        cout<<x.first<<" "<<x.second<<endl;
        a.pop();
    }
}
void Graph::djkstra(int src)
{
    dtype pq;
    pq.push(make_pair(0,src));
    dist[src] = 0;
    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        if(ext[u]==true)
            continue;
        ext[u]=true;
        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            int v = (*i).first;
            int weight = (*i).second;
            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                par[v]=u;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
    int pri=5;
    while(par[pri]!=NIL)
    {
        cout<<pri<<" ";
        pri=par[pri];
    }
    cout<<src<<endl;
    print();
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
