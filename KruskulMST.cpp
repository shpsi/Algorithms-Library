#include<bits/stdc++.h>
using namespace std;
#define NIL -1
#define INF 99999999
int cont;
int flag;
class DSU
{
    int n;
    int * parent;
    int * sz;
public:
    int findset(int i);
    void unite(int a,int b);
    DSU(int V);
};
int DSU::findset(int i)
{
    int p=parent[i];
    if(p==i)
        return i;
    parent[i]=findset(parent[i]);  // path compression
    return parent[i];
}
DSU::DSU(int V)
{
    this->n=V;
    this->parent=new int[V];
    int i;
    for(i=0;i<n;i++)
        this->parent[i]=i;
    this->sz=new int[V];
    for(i=0;i<n;i++)
        this->sz[i]=1;
}
void DSU::unite(int a,int b)
{
    int r1=findset(a);
    int r2=findset(b);
    if(r1==r2)
    {
        flag=1;
        return ;
    }
    if(sz[r1]>=sz[r2])
    {
        parent[r2]=r1;
        sz[r1]=(sz[r1]==sz[r2])?sz[r1]+r1:sz[r1];
    }
    else
    {
        parent[r1]=r2;
    }
}
class Graph
{
    int V;
    vector <pair< int , pair<int ,int> > > adj;
public:
    Graph(int V);
    void addedge(int u,int v,int w);
    void kruskul();
};
Graph::Graph(int V)
{
    this->V=V;
}
void Graph::addedge(int u,int v,int w)
{
    adj.push_back(make_pair(w,make_pair(u,v)));
    cont++;
}
void Graph::kruskul()
{
    sort(adj.begin(),adj.end());
    DSU d1(V);
    int mz=0;
    int i=0;
    int res[1000],resi=0;
    for(i=0;i<9;i++)
    {
        if(mz==V)
            break;
        int u,v;
        u=adj[i].second.first;
        v=adj[i].second.second;
        int w;
        w=adj[i].first;
       if(d1.findset(v)==d1.findset(u))
        {
            continue;
        }
        d1.unite(u,v);
        res[resi]=w;
        resi++;
        mz++;
    }
    for(i=0;i<resi;i++)
        cout<<res[i]<<" ";
    cout<<endl;
}
int main()
{
    Graph g1(6);
    g1.addedge(0,3,1);
    g1.addedge(3,4,6);
    g1.addedge(0,1,3);
    g1.addedge(1,3,3);
    g1.addedge(1,3,1);
    g1.addedge(2,4,5);
    g1.addedge(4,5,2);
    g1.addedge(1,2,1);
    g1.addedge(2,5,4);
    g1.kruskul();
    return 0;
}
