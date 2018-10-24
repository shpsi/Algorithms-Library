#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n=5;
    char mat[n][n];
    int i,j,k;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        cin>>mat[i][j];
    pair<int,int> dp[n][n];
    if(mat[0][0]=='X')
    {
        dp[0][0].first=1;
        dp[0][0].second=1;
    }
    else
    {
        dp[0][0].first=0;
        dp[0][0].second=0;
    }
    for(i=1;i<n;i++)
    {
        if(mat[0][i]=='X')
        {
            dp[0][i].first=1+dp[0][i-1].first;
            dp[0][i].second=1;
        }
        else
        {
            dp[0][i].first=0;
            dp[0][i].second=0;
        }
    }
    for(i=1;i<n;i++)
    {
        if(mat[i][0]=='X')
        {
            dp[i][0].first=1;
            dp[i][0].second=1+dp[i-1][0].second;
        }
        else
        {
            dp[i][0].first=0;
            dp[i][0].second=0;
        }
    }
    for(i=1;i<n;i++)
    {
        for(j=1;j<n;j++)
        {
            if(mat[i][j]=='X')
            {
                dp[i][j].first=1+dp[i][j-1].first;
                dp[i][j].second=1+dp[i-1][j].second;
            }
            else
            {
                dp[i][j]=make_pair(0,0);
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<dp[i][j].second<<"'"<<dp[i][j].first<<"  ";
        }
        cout<<endl;
    }
}
