#include<bits/stdc++.h>
using namespace std;
int n;
int in(int i)
{
    if(i>=0 && i<n)
        return 1;
    else
        return 0;
}
int main()
{
    n=4;
    int adj[n][n];
    int i,j,k;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        cin>>adj[i][j];
    int dp[n][n];
    dp[0][0]=adj[0][0];
    for(i=1;i<n;i++)
        dp[0][i]=dp[0][i-1]+adj[0][i];
    for(i=1;i<n;i++)
        dp[i][0]=dp[i-1][0]+adj[i][0];
    for(i=1;i<n;i++)
    {
        for(j=1;j<n;j++)
            dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+adj[i][j];
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
    {cout<<dp[i][j]<<" ";}
    cout<<endl;}
    int tc=10;
    while(tc--)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int sum=0;
        if(in(c)&&in(d))
            sum+=dp[c][d];
        if(in(a-1)&&in(d))
            sum-=dp[a-1][d];
        if(in(c)&&in(b-1))
            sum-=dp[c][b-1];
        if(in(a-1)&&in(b-1))
            sum+=dp[a-1][b-1];
        cout<<sum<<endl;
    }
}
