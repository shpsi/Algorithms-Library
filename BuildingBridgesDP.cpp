#include<bits/stdc++.h>
using namespace std;
void LIS(int a[],int n)
{
    int i,j;
    int dp[n];
    for(i=0;i<n;i++)
        dp[i]=1;
    int tr[n];
    for(i=0;i<n;i++)
        tr[i]=i;
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(a[j]<a[i])
            {
                dp[i]=max(dp[i],dp[j]+1);
                if(dp[i]==dp[j+1])
                  tr[i]=j;
            }
        }
    }
    int maxi=-1,ind;
    for(i=0;i<n;i++)
    {
        if(dp[i]>maxi)
            ind=i,maxi=dp[i];
    }
    while(tr[ind]!=ind)
    {
        cout<<ind<<" ";
        ind=tr[ind];
    }
    cout<<ind<<" ";
    cout<<endl<<maxi<<endl;
}
int main()
{
    vector <pair<int ,int > > bg;
    int i=0;
    bg.push_back(make_pair(4,3));
    bg.push_back(make_pair(6,5));
    bg.push_back(make_pair(1,10));
    sort(bg.begin(),bg.end());
    reverse(bg.begin(),bg.end());
    for(i=0;i<3;i++)
    cout<<bg[i].first<<" "<<bg[i].second<<endl;
    int arr[10000],ai=0;
    for(i=0;i<3;i++)
    {
        arr[ai]=bg[i].second;
        ai++;
    }
    LIS(arr,ai);
}
