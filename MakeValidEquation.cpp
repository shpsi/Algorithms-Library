#include<bits/stdc++.h>
using namespace std;
vector<int> res;
int fit(int a[],int result,int in,int n)
{
    if(in==n && result!=0)
    return 0;
    if(in==n&&result==0)
        return 1;
    if(fit(a,result-a[in],in+1,n))
    {
        res.push_back(+a[in]);
        return 1;
    }
     if(fit(a,result+a[in],in+1,n))
     {
         res.push_back(-a[in]);
         return 1;
     }
    return 0;
}
int main()
{
    int a[]={2,3,5,1};
    int result=1;
    if(fit(a,result,0,4))
    {
        vector<int>::iterator it;
        for(it=res.begin();it!=res.end();it++)
        {
            cout<<*it<<" ";
        }
        cout<<endl;
    }
    else
        cout<<"nothing";
    return 0;
}
