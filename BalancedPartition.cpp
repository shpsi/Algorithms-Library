#include<bits/stdc++.h>
using namespace std;
int  main()
{
    int a[]={3,6,100,7,9};
    int n=sizeof(a)/sizeof(a[0]);
    int i,j,k;
    int tot=0;
    for(i=0;i<n;i++)
        tot+=a[i];
    int dp[n][tot+1];
    for(j=0;j<tot+1;j++)
    {
        if(j==0)
            dp[0][j]=1;
        else if(j==a[0])
            dp[0][j]=1;
        else
            dp[0][j]=0;
    }
    for(i=1;i<n;i++)
    {
        for(j=0;j<tot+1;j++)
        {
            if(j==a[i])
            {
                dp[i][j]=1;
                continue;
            }
            dp[i][j]=dp[i-1][j];
            if(j-a[i]>=0)
                dp[i][j]=dp[i][j]||dp[i-1][j-a[i]];
        }
    }
    int pret=tot;
    tot/=2;
    for(i=0;i<=tot;i++)
    {
        if(dp[n-1][tot-i]==1)
           {cout<<abs((pret-(tot-i))-(tot-i))<<endl;return 0;}
    }
    return 0;
}
