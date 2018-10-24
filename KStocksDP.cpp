#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[]={2,5,7,1,4,3,1,3};
    int n=sizeof(a)/sizeof(a[0]);
    int k=3;
    int  dp[k+1][n];
    int i,j;
    for(i=0;i<k+1;i++)
        dp[i][0]=0;
    for(i=0;i<n;i++)
        dp[0][i]=0;
    for(i=1;i<k+1;i++)
    {
        int ma=-a[0];
        for(j=1;j<n;j++)
        {
            dp[i][j]=max(dp[i][j-1],a[j]+ma);
            ma=max(ma,dp[i-1][j]-a[j]);
        }
    }
    for(i=0;i<k+1;i++)
    {
        for(j=0;j<n;j++)
           {cout<<dp[i][j]<<" ";}
        cout<<endl;
    }
    i=k;
    j=n-1;
    stack <pair<int,int> > st;
    while(1)
    {
        int it;
        if(i==0 ||j==0)
            break;
        if(dp[i][j]==dp[i][j-1])
        {
            j-=1;
        }
        else
        {
            int maxdiff=dp[i][j]-a[j];
            for(it=j-1;it>=0;it--)
            {
                if(dp[i-1][it]-a[it]==maxdiff)
                {
                    st.push(make_pair(j,it));
                    i-=1;
                    j=it;
                    break;
                }
            }
        }
    }
    while(!st.empty())
    {
        pair<int,int > x=st.top();
        cout<<"sold at "<<a[x.first]<<" bought at "<<a[x.second]<<endl;
        st.pop();
    }
    return 0;
}

