#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int n=s.length();
    int palin[n][n];
    int i,j,k;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        palin[i][j]=9;
    for(i=0;i<n;i++)
        palin[i][i]=1;
    int len=2;
    for(i=0;i<=n-len;i++)
    {
        if(s[i]==s[i+len-1])
            palin[i][i+len-1]=1;
        else
            palin[i][i+len-1]=0;
    }
    for(len=3;len<=n;len++)
    {
        for(i=0;i<=n-len;i++)
        {
            j=i+len-1;
            if(s[i]==s[j])
            {
                palin[i][j]=palin[i+1][j-1];
                continue;
            }
            else
            {
                palin[i][j]=0;
            }
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
        {cout<<palin[i][j]<<" ";}
    cout<<endl;}
    int cut[n];
    cut[0]=0;
    for(int i=1;i<n;i++)
    {
        int mi=INT_MAX;
        int flg=0;
        for(j=0;j<i;j++)
        {
            if(j==0 && palin[j][i])
            {
                mi=0;
                flg=1;
                break;
            }
            if(palin[j][i] && mi>cut[j-1]+1)
            {
                mi=cut[j-1]+1;
                flg=1;
            }
        }
        if(flg)
        cut[i]=mi;
        else
            cut[i]=cut[i-1]+1;
    }
    for( i=0;i<n;i++)
        cout<<i<<" "<<cut[i]<<endl;
    cout<<cut[n-1]<<endl;
    return 0;
}
