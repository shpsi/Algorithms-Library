#include<bits/stdc++.h>
using namespace std;
int mbit[10000],bit[10000];
#define block cout<<"----------------------\n"<<endl;
void update1(int i,int val,int n)
{
    i+=1;
    while(i<=n)
    {
        mbit[i]+=val;
        i+=(i&(-i));
    }
}
void update(int l,int r,int val,int n)
{
    update1(l,val,n);
    update1(r+1,-val,n);
}
int sum(int i)
{
    int res=0;
    i+=1;
    while(i>0)
    {
        res+=mbit[i];
        i-=(i&(-i));
    }
    return res;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        update1(i,arr[i],n);
        update1(i+1,-arr[i],n);
    }
    block;
    for(int j=1;j<=n;j++)
        cout<<mbit[j]<< " ";
    cout<<endl;
    block;
    int q;
    cin>>q;
    while(q--)
    {
        int ty;
        cin>>ty;
        if(ty==1)
        {
            int ind;
            cin>>ind;
            cout<<sum(ind)<<endl;
        }
        else
        {
            int l,r,val;
            cin>>l>>r>>val;
            update(l,r,val,n);
        }
    }
    return 0;
}
