#include<bits/stdc++.h>
using namespace std;
int main()
{
    int freq[]={4,2,6,3};
    int val[]={10,12,16,21};
    int n=4;
    int dp[n][n];
    int i,j,k;
    int prefix[n];
    prefix[0]=freq[0];
    for(i=1;i<n;i++)
        prefix[i]=prefix[i-1]+freq[i];
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        dp[i][j]=-1;
    for(i=0;i<n;i++)
        dp[i][i]=freq[i];
    for(i=0;i<n-1;i++)
        dp[i][i+1]=min(freq[i]+2*freq[i+1],freq[i+1]+2*freq[i]);
    int len;
    for(len=3;len<=n;len++)
    {
        int a,b,c,d;
        for(i=0;i<=n-len;i++)
        {
            j=i+len-1;
            int k;
            int mi=INT_MAX;
            for(k=i;k<=j;k++)
            {
                a=0;
                b=0;
                c=0;
                d=0;
                if(k-1>=i)
                {
                    a=dp[i][k-1];
                }
                if(k+1<=j)
                {
                    b=dp[k+1][j];
                }
                c=prefix[j]-prefix[i]+freq[i];
            //    cout<<"lol "<<i<<" "<<j<<" "<<k<<" "<<a<<" "<<b<<" "<<c<<endl;
                d=a+b+c;
                if(mi>d)
                    mi=d;
            }
            dp[i][j]=mi;
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
