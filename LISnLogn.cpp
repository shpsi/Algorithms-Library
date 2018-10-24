#include<bits/stdc++.h>
using namespace std;
void LIS(int a[],int n)
{
    int sub[n];
    int par[n];
    for(int i=0;i<n;i++)
        par[i]=-1;
    int len=0;
    for(int i=0;i<n;i++)
    {
        int x=a[i];
        if(len==0)
        {
            sub[len]=i;
            len++;
            continue;
        }
        int low=0;
        int high=len;
        while(low<high)
        {
            int mid=(low+high)/2;
            if(a[sub[mid]]<x)
                low=mid+1;
            else
                high=mid;
        }
        int pos=low;
        if(pos>=len)
        {
            sub[len]=i;
            len++;
        }
        else
        {
            sub[pos]=i;
            len=pos+1;
        }
        if(pos!=0)
          par[i]=sub[pos-1];
    }
    int li=sub[len-1];
    while(li!=-1)
    {
        cout<<a[li]<<" ";
        li=par[li];
    }
    cout<<endl;
}
int main()
{
    int a[]={3,1,5,2,6,4,9};
    int n=sizeof(a)/sizeof(a[0]);
    LIS(a,n);
    return 0;
}
