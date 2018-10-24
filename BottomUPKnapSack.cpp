
#include<bits/stdc++.h>
using namespace std;
#define blocking  cout<<"--------------------------\n";
int main()
{
    int knapwht;
    cin>>knapwht;
    int n;
    cin>>n;
    int weight[n],value[n];
    int i,j;
    for(i=0;i<n;i++)
    {
        cin>>weight[i]>>value[i];
    }
    int dp[n][knapwht+1];
    for(j=0;j<=n;j++)
        dp[j][0]=0;
    i=0;
    for(j=1;j<=knapwht;j++)
    {
        if(weight[i]>j)
            dp[i][j]=0;
        else
            dp[i][j]=max(0,value[i]);
    }
  /*  cout<<"first\n";
      for(i=0;i<n;i++)
    {
        for(j=0;j<knapwht;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    cout<<"--------------------------\n";*/
    for(i=1;i<n;i++)
    {
        for(j=1;j<=knapwht;j++)
        {
            if(weight[i]>j)
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=max(dp[i-1][j],value[i]+dp[i-1][j-weight[i]]);
        }
    }
    blocking;
    for(i=0;i<n;i++)
    {
        for(j=0;j<=knapwht;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    blocking;
    i=n-1;
    j=knapwht;
    int res[1000],resi=0,opt=0;
    blocking;
    while(1)
    {
        cout<< "i= "<<i<<" j= "<<j<<endl;
        if(i>0 && dp[i][j]==dp[i-1][j])
            i--;
        else if(i==0)
        {
            if(weight[i]>j)
                break;
            else
            {
                res[resi]=i;
                resi++;
                break;
            }
        }
        else
        {
            res[resi]=i;
            resi++;
            j-=weight[i];
            i--;
        }
    }
    blocking;
    blocking;
    for(i=0;i<resi;i++)
        cout<< res[i] <<" "<< weight[res[i]]<<" "<<value[res[i]]<<endl;
    blocking;
    blocking;
    for(i=0;i<resi;i++)
        opt+=value[res[i]];
    blocking;
    return 0;
}
