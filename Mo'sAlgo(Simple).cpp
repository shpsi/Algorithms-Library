#include<bits/stdc++.h>
using namespace std;
int BLS ;
int hash[1000];
int ans=0;
struct query
{
    int l;
    int r;
    int ind;
};
int comp(query a,query b)
{
    if(a.l/BLS!=b.l/BLS)
        return a.l<b.l;
    return (a.l/BLS)&1?(a.r<b.r):(a.r>b.r);
}
void add(int i,int a[])
{
    if(hash[a[i]]==0)
        ans++;
    hash[a[i]]++;
}
void rem(int i,int a[])
{
    if(hash[a[i]]==1)
        ans--;
    hash[a[i]]--;
}
int fd(int l,int r,int a[],int n)
{
    int i,j,k;
    int hv[1000]={0};
    for(i=l;i<=r;i++)
        hv[a[i]]=1;
    int cnt=0;
    for(i=0;i<1000;i++)
    {
        if(hv[i])
            cnt++;
    }
    return cnt;
}
int main()
{
    int n;
    cin>>n;
    int i,j,k;
    int a[1000];
    for(i=0;i<n;i++)
        cin>>a[i];
    BLS=sqrt(n);
    int t=(n*(n+1))/2;
    i=0;
    query q[t];
    int ql,qr;
    for(ql=0;ql<n;ql++)
    {
        for(qr=ql;qr<n;qr++)
        {
           q[i].l=ql;
           q[i].r=qr;
           q[i].ind=i;
           i++;
        }
    }
    sort(q,q+t,comp);
    int res[t];
    i=0;
    j=-1;
    for(k=0;k<t;k++)
    {
        while(j<q[k].r)
        {
            add(j+1,a);
            j++;
        }
        while(j>q[k].r)
        {
            rem(j,a);
            j--;
        }
        while(i<q[k].l)
        {
            rem(i,a);
            i++;
        }
        while(i>q[k].l)
        {
            add(i-1,a);
            i--;
        }
        res[q[k].ind]=ans;
    }
    int dt=0;
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            int sum=fd(i,j,a,n);
            if(res[dt]!=sum)
            {
                cout<<res[dt]<<" "<<sum<<" "<<i<<" "<<j<<" "<<"Wrong Answer\n";
                return 0;
            }
            dt++;
        }
    }
    cout<<"Accepted!!!\n";
    return 0;
}
