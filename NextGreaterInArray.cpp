#include<bits/stdc++.h>
using namespace std;
vector<int> print(stack<int> a)
{
    vector<int> my;
    stack<int>b;
    while(!a.empty())
    {
        int x=a.top();
        b.push(x);
        a.pop();
    }
    while(!b.empty())
    {
        int x=b.top();
        my.push_back(x);
        a.push(x);
        b.pop();
    }
    return my;
}
int main()
{
    int a[]={98,23,54,12,20,7,27};
    int n=sizeof(a)/sizeof(a[0]);
    int i;
    stack   <int > st;
    int j=0;
    st.push(a[j]);
    j++;
    while(j<n)
    {
        int coming=a[j];
        if(coming>st.top())
        {
            int cnt=0,prev=-1;
            while(st.top()<coming)
            {
                if(prev==st.top())
                    break;
                prev=st.top();
                st.pop();
                cnt++;
            }
            for(int k=0;k<=cnt;k++)
                st.push(coming);
        }
        else
        {
            st.push(coming);
        }
        j++;
    }
    vector<int>my =print(st);
    for(i=0;i<n;i++)
    {
        if(my[i]==a[i])
            cout<<"null ";
        else
            cout<<my[i]<<" ";
    }
    cout<<endl;
    return 0;
}
