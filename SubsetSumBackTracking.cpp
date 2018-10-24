#include<bits/stdc++.h>
using namespace std;
int n;
void print(vector<int > a)
{
    for(vector<int>::iterator it=a.begin();it!=a.end();it++)
        cout<<*it<<" ";
    cout<<endl;
}
void rec(int a[],int at,int sum,int curr,vector<int >res)
{
 //   cout<<"lol "<<n<<" "<<at<<" "<<sum<<" "<<curr<<" "<<endl;
    if(at==n)
        return ;
    if(curr+a[at]==sum)
    {
     //   cout<<"f\n";
        res.push_back(a[at]);
        print(res);
        return ;
    }
    if(curr+a[at]>sum)
        return ;
    //cout<<"s\n";
    res.push_back(a[at]);
    rec(a,at+1,sum,curr+a[at],res);
    res.erase(res.end()-1);
    rec(a,at+1,sum,curr,res);
}
int main()
{
    vector<int >res;
    int a[]={5,7,10,12,15,18,20};
    n=sizeof(a)/sizeof(a[0]);
    sort(a,a+n);
    int sum=35;
    rec(a,0,sum,0,res);
    return 0;
}
