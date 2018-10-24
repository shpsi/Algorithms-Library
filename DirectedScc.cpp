#include<bits/stdc++.h>
using namespace std;
#define white 1
#define gray 2
#define black 3
#define NIL -1
stack<int>finish;
int vis[1000];
int comp[1000],compi=0;
class Graph
{
    int V;
    list<int> *adj;
public:
    Graph(int V);
    void addedge(int v,int w);
    void dfs(int u);
    void dfs1(int u);
    void printSCCs();
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
void Graph::dfs(int u)
{
    vis[u]=gray;
    for(list<int>::iterator it=adj[u].begin();it!=adj[u].end();it++)
    {
        if(vis[*it]==white)
            dfs(*it);
    }
   // cout<<u<<" ";
    vis[u]=black;
    finish.push(u);
}
void Graph::dfs1(int u)
{
    comp[u]=compi;
    vis[u]=gray;
    for(list<int>::iterator it=adj[u].begin();it!=adj[u].end();it++)
    {
        if(vis[*it]==white)
            dfs(*it);
    }
    vis[u]=black;
}
void Graph::printSCCs()
{
    for(int i=0;i<1000;i++)
        vis[i]=white;
    for(int i=0;i<V;i++)
    {
        if(vis[i]==white)
            this->dfs(i);
    }
    Graph t(V);
    for(int i=0;i<this->V;i++)
    {
        for(list<int>::iterator it=this->adj[i].begin();it!=this->adj[i].end();it++)
        {
            int v=*it;
            t.addedge(v,i);
        }
    }
    for(int i=0;i<1000;i++)
        vis[i]=white;
    while(!finish.empty())
    {
        int z=finish.top();
        finish.pop();
        if(vis[z]!=white)
            continue;
        t.dfs1(z);
        compi++;
        //cout<<"funny";
    }
    for(int i=0;i<compi;i++)
    {
        for(int ii=0;ii<V;ii++)
        {
            if(comp[ii]==i)
                cout<<ii<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    Graph g(5);
    g.addedge(1, 0);
    g.addedge(0, 2);
    g.addedge(2, 1);
    g.addedge(0, 3);
    g.addedge(3, 4);
    cout << "Following are strongly connected components in "
            "given graph \n";
    g.printSCCs();
    return 0;
}
