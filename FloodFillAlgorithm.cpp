#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int > >res;
int vis[5][5];
int n;
int dfs(int mat[5][5],int i,int j)
{
   // cout<<i<<" "<<j<<endl;
    if(i==n-1 &&j==n-1)
        return true;
    if(i<0||j<0||i>=n||j>=n)
        return false;
    if(vis[i][j]==1)
        return false;
    vis[i][j]=1;
    if(mat[i][j]==0)
    {
        return false;
    }
    bool a,b,c,d;
    a=dfs(mat,i+1,j);
    b=dfs(mat,i,j+1);
    c=dfs(mat,i,j-1);
    d=dfs(mat,i-1,j);
    if(a||b||c||d)
    {
        res.push_back(make_pair(i,j));
        return true;
    }
    return false;
}
int main()
{
    int mat[5][5];
    n=5;
    int i,j,k;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            cin>>mat[i][j];
    if(!dfs(mat,0,0))
        cout<<"nothing\n";
    for(vector<pair<int,int> >::iterator it=res.begin();it!=res.end();it++)
        cout<<it->first<<" "<<it->second<<endl;
    return 0;
}
