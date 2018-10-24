#include<bits/stdc++.h>
using namespace std;
#define INF 10000
int n;
int dp[6][1<<6];
int par[6][1<<6];
bool vis[6][1<<6];
int src;
void print_sub(int mask)
{
    for(int i=0;i<mask && i<n-1;i++)
    {
        if((mask &(1<<i))!=0)
            cout<<i+1<<" ";
    }
    cout<<endl;
}
int solve(int at,int mask,int adj[100][100])
{
    if(vis[at][mask]==true)
        return dp[at][mask];
    int cost,ans=INF;
    vis[at][mask]=true;
   // cout<<mask<<endl;
    for(int i=0;i<n-1;i++)
    {
        if( ( mask & (1<<i) ) !=0 )
        {
            cost=adj[i+1][at]+solve( i+1 , mask & ( ~(1<<i) ) , adj );
           // cout<<i+1<<" "<<(mask & ( ~(1<<i) ))<<" "<<solve( i+1 , mask & ( ~(1<<i) ) , adj )<<endl;
            if(ans>cost)
            {
              par[at][mask]=i+1;
              ans=cost;
            }
        }
    }
    return dp[at][mask]=ans;
}
int main()
{
    cin>>n;
    int adj[100][100];
    memset(adj,0,sizeof(adj));
    memset(vis,false,sizeof(vis));
    int i,j,k;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            cin>>adj[i][j];
    }
    cin>>src;
    for(i=0;i<n;i++)
    {
        if(i==src)
            continue;
        dp[i][0]=adj[src][i];
        par[i][0]=src;
        vis[i][0]=true;
    }
   cout<<solve(src,(1<<(n-1))-1,adj)<<endl;;
   int at=src,flg=0,mask=(1<<(n-1))-1;
   while(1)
   {
       if(at==src && flg==1)
        break;
        cout<<dp[at][mask]<<" ";
       flg=1;
       at=par[at][mask];
       mask = mask &( ~( 1<<(at-1) ) );
   }
    return 0;
}
