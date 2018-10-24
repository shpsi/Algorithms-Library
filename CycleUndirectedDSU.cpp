#include<bits/stdc++.h>
using namespace std;
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
int main()
{
    int n=6;
    DSU d1(n);
    int m;
    cin>>m;
    while(m--)
    {
        int a;
        int b;
        cin>>a>>b;
        d1.unite(a,b);
    }
    if(flag)
        cout<<"cycle\n";
    else
        cout<<"nothing\n";
    return 0;
}
