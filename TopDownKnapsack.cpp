#include<bits/stdc++.h>
using namespace std;
#define blocking cout<<"----------------------------\n"<<endl;
#define INF -999999
int knapweight;
int dp[1000][1000];
int solver(int cweight,int weight[],int value[],int index,int n,int dp[1000][1000])
{
    if(index==n)
        return 0;
    if(dp[cweight][index]!=INF)
        return dp[cweight][index];
    if(cweight<weight[index])
    {
        dp[cweight][index]=0;
        return solver(cweight,weight,value,index+1,n,dp);
    }
    if(index==n-1)
    {
        if(cweight<weight[index])
        {
          dp[cweight][index]=0;
          return 0;
        }
        dp[cweight][index]=value[index];
        return value[index];
    }
    dp[cweight][index]=max(value[index]+solver(cweight-weight[index],weight,value,index+1,n,dp),solver(cweight,weight,value,index+1,n,dp));
    return dp[cweight][index];
}
int solve(int weight[],int value[],int knapweight,int n)
{
    int i,j;
    for(i=0;i<knapweight+1;i++)
        for(j=0;j<n;j++)
          dp[i][j]=INF;
    int soln=solver(knapweight,weight,value,0,n,dp);
    i=knapweight;
    j=0;
    int res[1000],resi=0;
    blocking;
    while(1)
    {
        cout<<"i= "<<i<<" j= "<<j<<endl;
        if(j==n-1)
        {
            if(i<weight[j])
                break;
            else
            {
                res[resi]=j;
                resi++;
                break;
            }
        }
        else if(dp[i][j]==dp[i][j+1])
        {
            j++;
        }
        else if(dp[i][j]==value[j]+dp[i-weight[j]][j+1])
        {
            res[resi]=j;
            resi++;
            i-=weight[j];
            j++;
        }
    }
    blocking;
    blocking;
    for(int k=0;k<resi;k++)
        cout<<res[k]<<" "<<weight[res[k]]<<" "<<value[res[k]]<<endl;
    blocking;
    return soln;
}
int main()
{
    cin>>knapweight;
    int n;
    cin>>n;
    int weight[n],value[n];
    int i,j;
    for(i=0;i<n;i++)
        cin >>weight[i]>>value[i];
    cout<<solve(weight,value,knapweight,n);
    return 0;
}
