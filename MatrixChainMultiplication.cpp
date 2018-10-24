#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
int main()
{
    vector<pair<int ,int> >mt(4);
    mt[0]=make_pair(2,3);
    mt[1]=make_pair(3,6);
    mt[2]=make_pair(6,4);
    mt[3]=make_pair(4,5);
    int i,j,n=mt.size();
    pair<int,pair<int,int> > dp[n][n];
    for(i=0;i<n;i++)
        dp[i][i]=make_pair(0,make_pair(mt[i].ff,mt[i].ss));
    int len;
    for(len=2;len<=n;len++)
    {
        for(i=0;i<n-len+1;i++)
        {
            j=i+len-1;
            if(len==2)
            {
                dp[i][j]=make_pair(mt[i].ff*mt[i].ss*mt[j].ss,make_pair(mt[i].ff,mt[j].ss));
            }
            else
            {
                int k;
                dp[i][j].ff=INT_MAX;
                for(k=i+1;k<=j;k++)
                {
                    dp[i][j].ff=min(dp[i][j].ff,dp[i][k-1].ff+dp[k][j].ff+(dp[i][k-1].ss.ff*dp[i][k-1].ss.ss*dp[k][j].ss.ss));
                    if(dp[i][j].ff==dp[i][k-1].ff+dp[k][j].ff+(dp[i][k-1].ss.ff*dp[i][k-1].ss.ss*dp[k][j].ss.ss))
                    {
                        dp[i][j].ss.ff=dp[i][k-1].ss.ff;
                        dp[i][j].ss.ss=dp[k][j].ss.ss;
                    }
                }
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            cout<<dp[i][j].ff<<"    ";
        cout<<endl;
    }
    return 0;
}
