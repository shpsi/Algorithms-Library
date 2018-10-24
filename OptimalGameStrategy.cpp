#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[]={3,9,1,2};
    int n=4;
    pair<int,int>dp[n][n];
    int i,j,k;
    for(i=0;i<n;i++)
    {
        dp[i][i].first=a[i];
        dp[i][i].second=0;
    }
    for(i=0;i<n-1;i++)
    {
        j=i+1;
        dp[i][j].first=max(a[i],a[i+1]);
        dp[i][j].second=min(a[i],a[i+1]);
    }
    int len;
    for(len=3;len<=n;len++)
    {
        for(i=0;i<=n-len;i++)
        {
            j=i+len-1;
            dp[i][j].first=max(a[i]+dp[i+1][j].second,a[j]+dp[i][j-1].second);
            if(dp[i][j].first==a[i]+dp[i+1][j].second)
            {
                    dp[i][j].second=dp[i+1][j].first;
            }
            else
            {
                    dp[i][j].second=dp[i][j-1].first;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            cout<<dp[i][j].first<<"'"<<dp[i][j].second<<"  ";
        cout<<endl;
    }
    return 0;
}
