#include<bits/stdc++.h>
using namespace std;
int bit[10000];
#define block cout<<"----------------------\n"<<endl;
void update(int i,int val,int n)
{
    i+=1;
    while(i<=n)
    {
        bit[i]+=val;
        i+=(i&(-i));
    }
}
int sum(int i)
{
    int res=0;
    i+=1;
    while(i>0)
    {
        res+=bit[i];
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
        update(i,arr[i],n);
    }
    int q;
    cin>>q;
    while(q--)
    {
        int ty;
        cin>>ty;
        if(ty==1)
        {
            int ind,val;
            cin>>ind>>val;
            update(ind,val-arr[ind],n);
        }
        else
        {
            int l,r;
            cin>>l>>r;
            cout<<sum(r)-sum(l); // calculates sum from exclusive l and inclusive r
        }
    }
    return 0;
}
