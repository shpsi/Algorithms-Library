#include<bits/stdc++.h>
using namespace std;
#define INF 999999
map <int ,int > mp;
int  ans(int total,int a[],int n)
{
    if(mp.find(total)!=mp.end())
        return mp[total];
    if(total==0)
    {
        mp[0]=0;
        return 0;
    }
    if(total<0)
    {
        mp[total]=0;
        return INF;
    }
    int mi=INF;
    for(int i=0;i<n;i++)
    {
        if(ans(total-a[i],a,n)+1<mi)
            mi=ans(total-a[i],a,n)+1;
    }
    mp[total]=mi;
    return mi;
}
int main()
{
    int a[]={1,2,3};
    int total=3;
    cout<<ans(total,a,3);
}
