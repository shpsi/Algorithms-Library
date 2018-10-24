#include<bits/stdc++.h>
using namespace std;
class comp
{
protected:
    bool rev;
public:
  comp(bool revparam=false)
    {rev=revparam;}
  bool operator() (int lhs,int rhs)
  {
    if (rev) return (lhs>rhs);
    else return (lhs<rhs);
  }
};
void f(int x=1)
{
    if(x!=1)
        cout<<"not 1\n";
    else
        cout<<"yes 1\n";
}
int main()
{
    priority_queue<int>pq;
    int a[]={1,2,3,4,5};
    int n=5;
    int i,j,k;
    for(i=0;i<5;i++)
        pq.push(a[i]);
    cout<<pq.size()<<endl;
    priority_queue<int>pq2(pq);
    priority_queue<int>pq1(a,a+n);
    cout<<pq1.size()<<endl;
    cout<<pq2.size()<<endl;
    priority_queue<int,vector<int>,greater<int> >pq3(a,a+n);
    while(!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
    while(!pq1.empty())
    {
        cout<<pq1.top()<<" ";
        pq1.pop();
    }
    cout<<endl;
    while(!pq2.empty())
    {
        cout<<pq2.top()<<" ";
        pq2.pop();
    }
    cout<<endl;
    while(!pq3.empty())
    {
        cout<<pq3.top()<<" ";
        pq3.pop();
    }
    cout<<endl;
    priority_queue<int,vector<int>,comp >pq4(comp(false));
    priority_queue<int,vector<int>,comp >pq5(comp(true));
    f();
    f(3);
    return 0;
}
