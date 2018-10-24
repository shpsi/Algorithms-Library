#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n;
    m=n;
    int i,a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    int dp[n][m];
    int last[n][m];
    for(int l=0;l<n;l++)
        for(int p=0;p<m;p++)
          {dp[l][p]=0;last[l][p]=-1;}
    int len;
    for(len=0;len<n;len++)
    {
        for(i=0;i<n-len;i++)
        {
            int j=i+len;
            int k;
            for(k=i;k<=j;k++)
            {
                int lv=1,rv=1;
                if(i!=0)
                    lv=a[i-1];
                if(j!=n-1)
                    rv=a[j+1];
                int before=0,after=0;
                if(i!=k)
                    before=dp[i][k-1];
                if(j!=k)
                    after=dp[k+1][j];
                if(dp[i][j]<lv*rv*a[k]+before+after)
                {
                    last[i][j]=k;
                    dp[i][j]=lv*rv*a[k]+before+after;
                }
            }
        }
    }
    for(int l=0;l<n;l++)
    {
        for(int p=0;p<m;p++)
          {cout<<dp[l][p]<<" ";}
        cout<<endl;
    }
        for(int l=0;l<n;l++)
    {
    for(int p=0;p<m;p++)
          {cout<<last[l][p]<<" ";}
        cout<<endl;
    }
}
