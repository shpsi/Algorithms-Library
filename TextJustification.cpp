#include<bits/stdc++.h>
using namespace std;
#define inf 999999
int main()
{
    string word[]={"tushar","roy","likes","to","code"};
    int wlen[]={6,3,5,2,4};
    int prefix[5];
    int width=10;
    int n=5;
    int calc[n][n];
    int i,j,k;
    for(i=0;i<n;i++)
    {
        if(i==0)
            prefix[i]=wlen[i];
        else
            prefix[i]=prefix[i-1]+wlen[i];
    }
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            int space=width-((j-i)+prefix[j]-prefix[i]+wlen[i]);
            if(space<0)
                calc[i][j]=inf;
            else
                calc[i][j]=space*space;
        }
    }
    int dp[n],trace[n];
    dp[n-1]=calc[n-1][n-1];
    trace[n-1]=n-1;
    for(i=n-2;i>=0;i--)
    {
        dp[i]=calc[i][n-1];
        for(j=i+1;j<n;j++)
        {
            if(calc[i][j-1]==inf)
                continue;
            dp[i]=min(dp[i],calc[i][j-1]+dp[j]);
            if(dp[i]==calc[i][j-1]+dp[j])
                trace[i]=j-1;
        }
        if(dp[i]==calc[i][n-1])
            trace[i]=n-1;
    }
    i=0;
    while(1)
    {
        if(i>=n)
            break;
        j=trace[i];
        for(k=i;k<n && k<=j;k++)
            cout<<word[k]<<" ";
        cout<<endl;
        i=j+1;
    }
    for(int i=0;i<n;i++)
        cout<<dp[i]<<" "<<trace[i]<<endl;
    return 0;
}
