#include<bits/stdc++.h>
using namespace std;
int n;
int seg[100005];
int lazy[10005];
void create(int a[],int curri,int l,int r)
{
    if(l>r)
        return ;
    if(l==r)
    {
        seg[curri]=a[l];
        return ;
    }
    int mid=(l+r)/2;
    create(a,2*curri+1,l,mid);
    create(a,2*curri+2,mid+1,r);
    seg[curri]=seg[2*curri+1]+seg[2*curri+2];
}
void pup(int curri,int index,int val,int l,int r)
{
    if(l==r &&r==index)
    {
        seg[curri]+=val;
        return ;
    }
    int mid=(l+r)/2;
    if(l<= index && index<=mid)
    {
        pup(2*curri+1,index,val,l,mid);
    }
    else
    {
        pup(2*curri+2,index,val,mid+1,r);
    }
    seg[curri]=seg[2*curri+1]+seg[2*curri+2];
}
int sumq(int curri,int qs,int qe,int l,int r)
{
    if(qs<=l && r<=qe)
        return seg[curri];
    if(qs>r || qe<l)
        return 0;
    int mid=(l+r)/2;
    return sumq(2*curri+1,qs,qe,l,mid)+sumq(2*curri+2,qs,qe,mid+1,r);
}
void rup(int curri,int qs,int qe,int val,int l ,int r)
{
    if(qs>r || qe<l)
        return ;
    if(l==r)
    {
        seg[curri]+=val;
        return ;
    }
    int mid=(l+r)/2;
    rup(2*curri+1,qs,qe,val,l,mid);
    rup(2*curri+2,qs,qe,val,mid+1,r);
    seg[curri]=seg[2*curri+1]+seg[2*curri+2];;
}
void propagate(int i,int l,int r)
{
    if(lazy[i]==0)
        return ;
    if(l==r)
    {
        seg[i]+=lazy[i];
        lazy[i]=0;
        return ;
    }
    else
    {
        seg[i]+=(lazy[i]*(r-l+1));
        lazy[2*i+1]+=lazy[i];
        lazy[2*i+2]+=lazy[i];
        lazy[i]=0;
        return ;
    }
}
void lazyup(int curri,int qs,int qe,int val,int l,int r)
{
    if(qs>r || qe<l)
        return ;
    propagate(curri,l,r);
    if(l==r)
    {
        seg[curri]+=val;
        return ;
    }
    if(qs<=l && r<= qe)
    {
        seg[curri]+=(r-l+1)*val;
        lazy[2*curri+1]+=val;
        lazy[2*curri+2]+=val;
        return ;
    }
    int mid=(l+r)/2;
    lazyup(2*curri+1,qs,qe,val,l,mid);
    lazyup(2*curri+2,qs,qe,val,mid+1,r);
    seg[curri]=seg[2*curri+1]+seg[2*curri+2];
    return ;
}
int  lazyq(int curri,int qs,int qe,int l,int r)
{
    if(qs>r || qe<l)
        return 0;
    propagate(curri,l,r);
    if(l==r)
    {
        return seg[curri];
    }
    if(qs<=l && r<= qe)
    {
        return seg[curri];
    }
    int mid=(l+r)/2;
    return lazyq(2*curri+1,qs,qe,l,mid)+lazyq(2*curri+2,qs,qe,mid+1,r);
}
int main()
{
    int a[]={1,2,3,4,5,6,7};
    int n=sizeof(a)/sizeof(a[0]);
    create(a,0,0,n-1);
    lazyup(0,1,3,7,0,n-1);
    cout<<lazyq(0,1,4,0,n-1)<<endl;
    return 0;
}
