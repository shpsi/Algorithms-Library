#include<bits/stdc++.h>
using namespace std;
int bls,n,a[1000],i,j,k,t;
int ty,timer=0;
vector<pair<int,int> >u(100);
int cnts,cntu;
struct query
{
    int l;
    int r;
    int time;
    int ind;
};
struct query q[100];
int comp(query a,query b)
{
    if(a.l/bls!=b.l/bls)
        return a.l<b.l;
    else
    {
        if(a.time!=b.time)
            return a.time<b.time;
        else
            return a.r<b.r;
    }
}
int main()
{
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    bls=pow(n,2/3);
    cin>>t;
    while(t--)
    {
        cin>>ty;
        if(ty==1)
        {
            int ql,qr;
            cin>>ql>>qr;
            q[cnts].l=ql;
            q[cnts].r=qr;
            q[cnts].time=timer;
            q[cnts].ind=cnts;
            cnts++;
        }
        else
        {
            int in;int va;
            cin>>in>>va;
            u[cntu].first=in;
            u[cntu].second=va;
            timer++;
        }
    }
    sort(q,q+cnts,comp);
    return 0;
}
