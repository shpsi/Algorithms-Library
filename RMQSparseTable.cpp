#include<bits/stdc++.h>
using namespace std;
#define LOG(n) log(n)/log(2)
int query(int l,int r,int table[100][100],int a[])
{
        int k=LOG(r-l+1);
        int x=r-pow(2,k);
        int y=r-pow(2,k)+1;
        return min(a[table[l][k]],a[table[y][k]]);
}
int main()
{
    int a[]={4,6,1,5,7,3};
    int n=6;
    int m=LOG(n)+1;
    int table[100][100];
    int i,j,k;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        table[i][j]=-1;
    for(i=0;i<n;i++)
        table[i][0]=i;
    for(j=1;j<m;j++)
    {
        for(i=0;i+pow(2,j)-1<n;i++)
        {
            int x=pow(2,j-1);
            if(a[table[i][j-1]]<a[table[i+x][j-1]])
                table[i][j]=table[i][j-1];
            else
                table[i][j]=table[i+x][j-1];
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            int mi=INT_MAX;
            for(k=i;k<=j;k++)
                mi=min(mi,a[k]);
            if(mi!=query(i,j,table,a))
               {cout<<"Wrong Answer"<<i<<j<<endl;return 0;}
        }
    }
    cout<<"Accepted";
    return 0;
}
