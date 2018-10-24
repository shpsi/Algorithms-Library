#include<bits/stdc++.h>
using namespace std;
#define self 9
set<string> dict;
int n;
void print(int l,int r,int tr[100][100],string s)
{
    int i,j,k;
    if(tr[l][r]==self)
    {
        for(k=l;k<=r;k++)
            cout<<s[k];
        cout<<endl;
        return ;
    }
    print(l,tr[l][r],tr,s);
    print(tr[l][r]+1,r,tr,s);
}
int main()
{
    dict.insert("i");
    dict.insert("a");
    dict.insert("am");
    dict.insert("ace");
    string s;
    cin>>s;
    n=s.length();
    int dp[n][n],tr[100][100];
    int i,j,k;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        dp[i][j]=0;
    for(i=0;i<n;i++)
    {
        char myc[3];
        myc[0]=s[i];
        myc[1]='\0';
        if(dict.find(myc)!=dict.end())
        {
            dp[i][i]=1;
            if(dp[i][i]==1)
                tr[i][i]=self;
        }
        else
            dp[i][i]=0;
    }
    for(int len=2;len<=n;len++)
    {
        for(i=0;i<=n-len;i++)
        {
            j=i+len-1;
            char myc[1000];
            int my_i=0;
            k=i;
            while(k<=j)
            {
                myc[my_i]=s[k];
                k++;
                my_i++;
            }
            myc[my_i]='\0';
            if(dict.find(myc)!=dict.end())
            {
                dp[i][j]=1;
                tr[i][j]=self;
                continue;
            }
            if(j==i+1)
            {
                dp[i][j]=dp[i][i]&&dp[j][j];
                tr[i][j]=i;
                continue;
            }
            else
            {
                k=i+1;
                dp[i][j]=0;
                for(;k<=j;k++)
                {
                    int flg=1;
                    if(dp[i][j]==0)
                        flg=0;
                    dp[i][j]=dp[i][j]||(dp[i][k-1]&&dp[k][j]);
                    if(dp[i][j]==1 && flg==0)
                    {
                        flg=1;
                        tr[i][j]=k-1;
                    }
                }
            }
        }
    }
    print(0,n-1,tr,s);
  /*  for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
          {if(i>j)cout<<"  ";else if(dp[i][j])cout<<"T"<<" ";else cout<<"F"<<" ";}
        cout<<endl;
    }*/
    return 0;
}
