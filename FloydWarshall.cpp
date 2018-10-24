#include<bits/stdc++.h>
using namespace std;
#define NIL -1
#define INF 0x3f3f3f3f
#define blck cout<<"----------------------\n";
class Graph
{
    int V;
public:
    Graph(int V);
    void floyd(int adj[100][100]);
};
Graph::Graph(int V)
{
    this->V=V;
}
void Graph::floyd(int adj[100][100])
{
    int i,j,k;
    int par[100][100];
    int dist[100][100];
    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
        {
            if(i==j)
            {
                dist[i][j]=0;
                par[i][j]=-1;
                continue;
            }
            else if(adj[i][j]!=NIL)
            {
                dist[i][j]=adj[i][j];
                par[i][j]=i;
            }
            else
            {
                dist[i][j]=INF;
                par[i][j]=-1;
            }
        }
    }
    for(k=0;k<V;k++)
    {
        for(i=0;i<V;i++)
        {
            for(j=0;j<V;j++)
            {
                if(dist[i][j]>dist[i][k]+dist[k][j])
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                    par[i][j]=k;
                }
            }
        }
    }
    for(i=0;i<V;i++)
    {
        if(dist[i][i]<0)
        {
            cout<<"negetive cycle\n";
            return ;
        }
    }
    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
            cout<<dist[i][j]<<" ";
        cout<<endl;
    }
    blck;
    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
            cout<<par[i][j]<<" ";
        cout<<endl;
    }
    blck;
    int ds=2,sc=3;
    int indi=sc;
    while(par[indi][ds]!=indi)
    {
        cout<<ds<<" ";
        ds=par[indi][ds];
    }
    cout<<ds<<" "<<indi<<endl;
}
int main()
{
    Graph g1(4);
    int adj[100][100];
    int i,j;
    for(i=0;i<100;i++)
    {
        for(j=0;j<100;j++)
            adj[i][j]=NIL;
    }
    adj[0][3]=15;
    adj[3][0]=1;
    adj[2][3]=2;
    adj[0][1]=3;
    adj[1][2]=-2;
    adj[0][2]=6;
    g1.floyd(adj);
    return 0;
}
