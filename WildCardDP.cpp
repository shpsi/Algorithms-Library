// ? >> One Character
// * >> AnyString (Empty Too)
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string txt,pat;
    cin>>txt>>pat;
    int n=txt.length()+1;
    int m=pat.length()+1;
    int dp[100][100];
    dp[0][0]=1;
    int i,j,k;
    int flg=1;
    for(i=1;i<m;i++)
    {
        if(pat[i-1]!='*')
            flg=0;
        if(flg==1&& pat[i-1]=='*')
            dp[0][i]=1;
        else
            dp[0][i]=0;
    }
    for(i=1;i<n;i++)
        dp[i][0]=0;
    for(i=1;i<n;i++)
    {
        for(j=1;j<m;j++)
        {
            if(pat[j-1]=='*')
            {
                dp[i][j]=dp[i][j-1]||dp[i-1][j];
            }
            else if(pat[j-1]==txt[i-1]||pat[j-1]=='?')
            {
                dp[i][j]=dp[i-1][j-1];
            }
            else
                dp[i][j]=0;
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
         {
             if(dp[i][j]==1)
                cout<<'T'<<" ";
             else
                cout<<"F ";
         }
        cout<<endl;
    }
    i=n-1;
    j=m-1;
    int prevj=10000;
    while(1)
    {
        if(i==0 ||j==0)
            break;
        if(prevj==j)
            cout<<txt[i-1];
        else
            {if(prevj==10000)cout<<pat[j-1]<<" "<<txt[i-1];else cout<<endl<<pat[j-1]<<" "<<txt[i-1];
            prevj=j;}
        if(dp[i][j]==dp[i-1][j-1])
        {
            i--;
            j--;
        }
        else if(dp[i][j]==dp[i][j-1])
            j--;
        else if(dp[i][j]==dp[i-1][j])
            i--;
    }
    return 0;
}
