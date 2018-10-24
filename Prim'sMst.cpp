#include<bits/stdc++.h>
using namespace std;
#define NIL -1
#define INF 0x3f3f3f3f
#define blck cout<<"----------------------\n";
#define dtype priority_queue<  pair< int ,int > , vector < pair< int ,int > > , greater< pair< int ,int > > >
vector<pair<int,int> >mst;
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
    void prim(int src);
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
void Graph::prim(int src)
{
    dtype pq;
    pq.push(make_pair(0,src));
    for(int i=1;i<V;i++)
        pq.push(make_pair(INF,i));
    int cnt=0;
    int edist[V];
    for(int i=1;i<V;i++)
        edist[i]=INF;
    while(!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();
        if(ext[u]==true)
            continue;
        ext[u]=true;
        mst.push_back(make_pair(u,par[u]));
        for(list<pair<int,int> >::iterator it=adj[u].begin();it!=adj[u].end();it++)
        {
            pair<int,int> v=(*it);
            if(v.second<edist[v.first])
            {
                edist[v.first]=v.second;
                par[v.first]=u;
                pq.push(make_pair(v.second,v.first));
            }
        }
    }
    vector<pair<int,int> >::iterator it;
    mst.erase(mst.begin());
    for(it=mst.begin();it!=mst.end();it++)
        cout<<char(it->first+'A')<<" "<<char(it->second+'A')<<endl;
}
void Graph::addedge(int v,int w,int hk)
{
    adj[v].push_back(make_pair(w,hk));
    adj[w].push_back(make_pair(v,hk));
}
int main()
{
    Graph g1(6);
    g1.addedge(0,3,1);
    g1.addedge(3,4,6);
    g1.addedge(0,1,3);
    g1.addedge(3,1,3);
    g1.addedge(2,3,1);
    g1.addedge(2,4,5);
    g1.addedge(4,5,2);
    g1.addedge(1,2,1);
    g1.addedge(2,5,4);
    g1.prim(0);
    return 0;
}

