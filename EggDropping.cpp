#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
int main()
{
    int floor,eggs;
    cin>>floor>>eggs;
    int dp[eggs+1][floor+1];
    int i,j;
    for(i=0;i<=eggs;i++)
        for(j=0;j<=floor;j++)
        dp[i][j]=INF;
    i=0;
    for(j=0;j<=floor;j++)
        dp[i][j]=0;
    for(j=0;j<=eggs;j++)
        dp[i][j]=0;
    i=1;
    for(j=1;j<=floor;j++)
        dp[i][j]=j;
    for(i=2;i<=eggs;i++)
    {
        for(j=1;j<=floor;j++)
        {
            if(i>j)
            {
                dp[i][j]=dp[i-1][j];
            }
            else
            {
                int k;
                for(k=2;k<j;k++)
                {
                    dp[i][j]=min(dp[i][j],1+max(dp[i-1][k-1],dp[i][j-k]));
                }
                dp[i][j]=min(dp[i][j],1+max(dp[i][j-1],0));
                dp[i][j]=min(dp[i][j],1+max(dp[i-1][j-1],0));
            }
        }
    }
    for(i=1;i<=eggs;i++)
    {
        for(j=1;j<=floor;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
