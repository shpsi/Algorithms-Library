#include<bits/stdc++.h>
using namespace std;
int main()
{
    array<int,5> my={4,5,6,3,2};
    for(auto it=my.begin();it!=my.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    for(auto it=my.rbegin();it!=my.rend();it++)
        cout<<*it<<" ";
    cout<<endl;
    for(auto it=my.cbegin();it!=my.cend();it++)
        cout<<*it<<" ";
    cout<<endl;
    for(auto it=my.crbegin();it!=my.crend();it++)
        cout<<*it<<" ";
    cout<<endl;
    array<int,5>f;
    array<int,0>s;
    cout<<f.empty()<<" "<<s.empty()<<endl;
    cout<<f.size()<<" "<<f.max_size()<<endl;  //fo array this always match
    my.at(1)=10;
    for(auto it=my.begin();it!=my.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    my[1]=5;
    for(auto it=my.begin();it!=my.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    cout<<my.front()<<endl;
    cout<<my.back()<<endl;
    char * str="abcd";
    array<char,5>mych;
    memcpy(mych.data(),str,5);
    cout<<mych.data()<<endl;
    my.fill(-23);
    for(auto it=my.begin();it!=my.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    for(auto it:my)
        cout<<it<<" ";
    cout<<endl;
    array<int,5>fi={11,22,33,44,55};
    fi.swap(my);
    for(auto it=my.begin();it!=my.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    for(auto it=fi.begin();it!=fi.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    return 0;
}
