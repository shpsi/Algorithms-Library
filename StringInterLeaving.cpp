#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a,b;
    cin>>a>>b;
    int n=a.length();
    int m=b.length();
    n++;
    m++;
    int dp[n][m];
    int i,j,k;
    string res;
    cin>>res;
    dp[0][0]=1;
    for(i=1;i<m;i++)
    {
        if(b[i-1]==res[i-1])
            dp[0][i]=1;
        else
            dp[0][i]=0;
    }
    for(i=1;i<n;i++)
    {
        if(a[i-1]==res[i-1])
            dp[i][0]=1;
        else
            dp[i][0]=0;
    }
    for(i=1;i<n;i++)
    {
        for(j=1;j<m;j++)
        {
            if(res[i+j-1]==a[i-1])
                dp[i][j]=dp[i-1][j];
            else if(res[i+j-1]==b[j-1])
                dp[i][j]=dp[i][j-1];
            else
                dp[i][j]=0;
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++)
               {cout<<dp[i][j]<<" ";}
        cout<<endl;
    }
}
