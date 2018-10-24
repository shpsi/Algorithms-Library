#include<bits/stdc++.h>
using namespace std;
int grundy[100];
int mex(int a,int b,int c)
{
    int i=0;
    while(1)
    {
        if(i==a||i==b||i==c)
            i++;
        else return i;
    }
}
int gr(int r)
{
   // cout<<r<<endl;
    if(grundy[r]!=-987)
        return grundy[r];
    return grundy[r]=mex(gr(r/2),gr(r/3),gr(r/6));
}
int spgrundy(int piles[])
{
    int n=sizeof(piles)/sizeof(piles[0]);
    int sum=gr(piles[0]);
   // cout<<sum<<endl;;
    for(int i=1;i<n;i++)
        sum=sum^gr(piles[i]);
}
int main()
{
    for(int i=0;i<100;i++)
        grundy[i]=-987;
    grundy[0]=0;
    grundy[1]=1;
    for(int i=0;i<100;i++)
        gr(i);
    int piles[]={4,6,8,2};
    cout<<spgrundy(piles)<<endl;
    for(int i=0;i<100;i++)
        if(grundy[i]!=-987)
        cout<<i<<" "<<grundy[i]<<endl;
    return 0;
}
