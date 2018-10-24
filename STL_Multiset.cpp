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
    multiset<int>first;
    multiset<int>second(a,a+4);
    multiset<int>third(second);
    multiset<int>forth(second.begin(),second.end());
    multiset<int,comp1> fifth(a,a+n),fff;
    for (multiset<int>::iterator it=fifth.begin(); it!=fifth.end(); ++it)
          cout << ' ' << *it;
    cout<<endl;
    multiset<int>sixth;
    sixth=second;
    second=multiset<int>();
    cout<<sixth.size()<<" "<<second.size()<<endl;
    for (multiset<int>::iterator it=sixth.begin(); it!=sixth.end(); ++it)
          cout << ' ' << *it;
    cout<<endl;
    for (multiset<int>::const_iterator it=sixth.cbegin(); it!=sixth.cend(); ++it)
          cout << ' ' << *it;
    cout<<endl;
    for (multiset<int>::reverse_iterator it=sixth.rbegin(); it!=sixth.rend(); ++it)
          cout << ' ' << *it;
    cout<<endl;
    for (multiset<int>::const_reverse_iterator it=sixth.crbegin(); it!=sixth.crend(); ++it)
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
    multiset<int>::iterator it1,it2,it3;
    it1=fifth.begin();
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
    multiset<int>mymultiset;
    multiset<int>::value_compare mycomp = mymultiset.value_comp();   // value<<=>>key
    for (int i=0; i<=5; i++) mymultiset.insert(i);
    int highest=*mymultiset.rbegin();
    multiset<int>::iterator itd=mymultiset.begin();
    do
    {
       cout << ' ' << *itd;
    } while ( mycomp(*(++itd),highest) );
    cout<<endl;
    multiset<int>::iterator itt=mymultiset.find(2);
    mymultiset.erase(itt);
    for(itt=mymultiset.begin();itt!=mymultiset.end();itt++)
        cout<<*itt<<" ";
    cout<<endl;
    mymultiset.insert(2);
    mymultiset.insert(2);
    pair<multiset<int>::const_iterator,multiset<int>::const_iterator > pr=mymultiset.equal_range(2);
    cout<<*pr.first<<" "<<*pr.second<<endl;
    multiset<int>s;
    int * ptr=s.get_allocator().allocate(5);
    for(int i=0;i<4;i++)
        s.get_allocator().construct(&ptr[i],i+1);
    for(int i=0;i<4;i++)
        cout<<ptr[i]<<" ";
    cout<<endl;
    for(int i=0;i<4;i++)
        s.get_allocator().destroy(&ptr[i]);
    s.get_allocator().deallocate(ptr,5);
    for(auto it=fifth.begin();it!=fifth.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    fifth.erase(fifth.lower_bound(50));
    for(auto it=fifth.begin();it!=fifth.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    fifth.erase(fifth.upper_bound(50));
    for(auto it=fifth.begin();it!=fifth.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    fifth.insert(10);
    for(auto it=fifth.begin();it!=fifth.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    int aa[]={2,2,2,2,3,3};
    multiset<int>mtp(aa,aa+6);
    cout<<mtp.count(2)<<" "<<mtp.count(3)<<endl;
    return 0;
}

