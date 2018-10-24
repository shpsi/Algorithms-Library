#include<bits/stdc++.h>
using namespace std;
struct comp1
{
  bool operator() (int lhs, int rhs)
      {return lhs<rhs;}
};
int main()
{
    int a[]={30,40,50,60};
    int n=4;
    set<int>first;
    set<int>second(a,a+4);
    set<int>third(second);
    set<int>forth(second.begin(),second.end());
    set<int,comp1> fifth(a,a+n),fff;
    for (set<int>::iterator it=fifth.begin(); it!=fifth.end(); ++it)
          cout << ' ' << *it;
    cout<<endl;
    set<int>sixth;
    sixth=second;
    second=set<int>();
    cout<<sixth.size()<<" "<<second.size()<<endl;
    for (set<int>::iterator it=sixth.begin(); it!=sixth.end(); ++it)
          cout << ' ' << *it;
    cout<<endl;
    for (set<int>::const_iterator it=sixth.cbegin(); it!=sixth.cend(); ++it)
          cout << ' ' << *it;
    cout<<endl;
    for (set<int>::reverse_iterator it=sixth.rbegin(); it!=sixth.rend(); ++it)
          cout << ' ' << *it;
    cout<<endl;
    for (set<int>::const_reverse_iterator it=sixth.crbegin(); it!=sixth.crend(); ++it)
          cout << ' ' << *it;
    cout<<endl;
    while(!fifth.empty())
    {
        cout<<*fifth.begin()<<" ";
        fifth.erase(fifth.begin());
    }
    cout<<endl;
    cout<<fifth.size()<<endl;
    cout<<fifth.max_size()<<endl;
    fifth.insert(10);
    fifth.insert(20);
    fifth.insert(30);
    set<int>::iterator it1,it2,it3;
    it1=fifth.begin();
    pair<set<int>::iterator,bool>re=fifth.insert(30);
    if(re.second==false)
        cout<<"already\n";
    it2=re.first;
    fifth.insert(it2,40);
    for(auto it=fifth.begin();it!=fifth.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    fifth.insert(a,a+n);
    for(auto it=fifth.begin();it!=fifth.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    it1=fifth.begin();
    it1++;
    fifth.erase(it1);
    fifth.erase(60);
    for(auto it=fifth.begin();it!=fifth.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    it1=fifth.begin();
    it1++;
    it2=fifth.begin();
    it2++;it2++;it2++;
    fifth.erase(it1,it2);
    for(auto it=fifth.begin();it!=fifth.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    fff.swap(fifth);
    cout<<fifth.size()<<endl;
    swap(fff,fifth);
    fff=fifth;
    for(auto it=fifth.begin();it!=fifth.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    cout<<fff.size()<<endl;
    fff.clear();
    cout<<fff.size()<<endl;
    fifth.emplace(70);
    for(auto it=fifth.begin();it!=fifth.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    fifth.emplace_hint(fifth.end(),60);
    cout<<fifth.size()<<endl;
    set<int>myset;
    set<int>::value_compare mycomp = myset.value_comp();   // value<<=>>key
    for (int i=0; i<=5; i++) myset.insert(i);
    int highest=*myset.rbegin();
    set<int>::iterator itd=myset.begin();
    do
    {
       cout << ' ' << *itd;
    } while ( mycomp(*(++itd),highest) );
    cout<<endl;
    set<int>::iterator itt=myset.find(2);
    myset.erase(itt);
    for(itt=myset.begin();itt!=myset.end();itt++)
        cout<<*itt<<" ";
    cout<<endl;
    myset.insert(2);
    myset.insert(2);
    pair<set<int>::const_iterator,set<int>::const_iterator > pr=myset.equal_range(2);
    cout<<*pr.first<<" "<<*pr.second<<endl;
    set<int>s;
    int * ptr=s.get_allocator().allocate(5);
    for(int i=0;i<4;i++)
        s.get_allocator().construct(&ptr[i],i+1);
    for(int i=0;i<4;i++)
        cout<<ptr[i]<<" ";
    cout<<endl;
    for(int i=0;i<4;i++)
        s.get_allocator().destroy(&ptr[i]);
    s.get_allocator().deallocate(ptr,5);
    fifth.erase(fifth.lower_bound(50));
    for(auto it=fifth.begin();it!=fifth.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    fifth.erase(fifth.upper_bound(50));
    for(auto it=fifth.begin();it!=fifth.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    return 0;
}

