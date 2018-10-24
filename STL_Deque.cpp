#include<bits/stdc++.h>
using namespace std;
int main()
{
    deque<int>first;
    deque<int>second(5,100);
    deque<int>third(second.begin(),second.end());
    deque<int>forth(third);
    int a[]={4,5,6,7};
    deque<int>fifth(a,a+4);
    for(deque<int>::iterator it=first.begin();it!=first.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    for(deque<int>::iterator it=second.begin();it!=second.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    for(deque<int>::iterator it=third.begin();it!=third.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    for(deque<int>::iterator it=forth.begin();it!=forth.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    for(deque<int>::iterator it=fifth.begin();it!=fifth.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    deque<int>sizth={2344,4,5,7,9};
    for(deque<int>::iterator it=sizth.begin();it!=sizth.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    deque<int>foo(3,5);
    deque<int>bar(2,6);
    foo=bar;
    bar=deque<int>();
    first.push_back(1);
    first.push_back(2);
    first.push_back(3);
    first.push_back(4);
    first.push_back(5);
    first.push_back(6);
    cout<<foo.size()<<" "<<bar.size()<<endl;
    deque<int>doo(5);
    for(deque<int>::iterator it=doo.begin();it!=doo.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    for(deque<int>::const_reverse_iterator it=first.crbegin();it!=first.crend();it++)
        cout<<*it<<" ";
    cout<<endl;
    for(deque<int>::const_iterator it=first.cbegin();it!=first.cend();it++)
        cout<<*it<<" ";
    cout<<endl;
    for(deque<int>::reverse_iterator it=first.rbegin();it!=first.rend();it++)
        cout<<*it<<" ";
    cout<<endl;
    first.insert(first.end(),3,1200);
    cout<<first.size()<<endl;
    cout<<first.max_size()<<endl;
    deque<pair<int,int> >ss;
    cout<<ss.max_size()*2<<endl;
    for(deque<int>::const_iterator it=first.cbegin();it!=first.cend();it++)
        cout<<*it<<" ";
    cout<<endl;
    first.resize(5);
    cout<<"resize "<<first.size()<<endl;
    for(deque<int>::const_iterator it=first.cbegin();it!=first.cend();it++)
        cout<<*it<<" ";
    cout<<endl;
    first.resize(7,45);
    cout<<"resize "<<first.size()<<endl;
    for(deque<int>::const_iterator it=first.cbegin();it!=first.cend();it++)
        cout<<*it<<" ";
    cout<<endl;
    first.resize(11);
    cout<<"resize "<<first.size()<<endl;
    for(deque<int>::const_iterator it=first.cbegin();it!=first.cend();it++)
        cout<<*it<<" ";
    cout<<endl;
    deque<int>x(10);
    x.push_back(1);
    x.push_back(2);
    x.push_back(8);
    int sum(0);
    while(!x.empty())
    {
        sum+=x.back();
        x.pop_back();
    }
    cout<<sum<<endl;
    deque<int>yi;
    yi.push_back(1);
    yi.push_back(2);
    yi.push_back(3);
    yi.push_back(4);
    yi.push_back(5);
    yi.resize(1);
    yi.shrink_to_fit();
    yi[0]=333;
    cout<<yi[0]<<endl;
    cout<<yi.at(0)<<endl;
    cout<<yi.front()<<endl;
    yi.push_back(11);
    cout<<yi.back()<<endl;
    for(auto&it:yi)
        cout<<it<<" ";
    cout<<endl;
    yi.pop_front();
    for(auto&it:yi)
        cout<<it<<" ";
    cout<<endl;
    yi.push_front(33);
    for(auto&it:yi)
        cout<<it<<" ";
    cout<<endl;
    deque<int>s;
    int * ptr=s.get_allocator().allocate(5);
    for(int i=0;i<4;i++)
        s.get_allocator().construct(&ptr[i],i+1);
    for(int i=0;i<4;i++)
        cout<<ptr[i]<<" ";
    cout<<endl;
    for(int i=0;i<4;i++)
        s.get_allocator().destroy(&ptr[i]);
    s.get_allocator().deallocate(ptr,5);
    foo.assign(3,100);
    bar.assign(5,200);
    swap(foo,bar);
    for (deque<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
       cout << ' ' << *it;
    cout << '\n';
    for (deque<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
       cout << ' ' << *it;
    cout << '\n';
    yi.insert(yi.end()-1,22);
    for(deque<int>::const_iterator it=yi.cbegin();it!=yi.cend();it++)
        cout<<*it<<" ";
    cout<<endl;
    yi.insert(yi.begin(),yi.begin()+1,yi.end());
    for(deque<int>::const_iterator it=yi.cbegin();it!=yi.cend();it++)
        cout<<*it<<" ";
    cout<<endl;
    yi.erase(yi.begin()+2);
    for(deque<int>::const_iterator it=yi.cbegin();it!=yi.cend();it++)
        cout<<*it<<" ";
    cout<<endl;
    yi.erase(yi.begin()+1,yi.begin()+3);
    for(deque<int>::const_iterator it=yi.cbegin();it!=yi.cend();it++)
        cout<<*it<<" ";
    cout<<endl;
    deque<int> si(4,556);
    si.swap(yi);
    for(deque<int>::const_iterator it=si.cbegin();it!=si.cend();it++)
        cout<<*it<<" ";
    cout<<endl;
    for(deque<int>::const_iterator it=yi.cbegin();it!=yi.cend();it++)
        cout<<*it<<" ";
    cout<<endl;
   swap(si,yi);
    for(deque<int>::const_iterator it=si.cbegin();it!=si.cend();it++)
        cout<<*it<<" ";
    cout<<endl;
    for(deque<int>::const_iterator it=yi.cbegin();it!=yi.cend();it++)
        cout<<*it<<" ";
    cout<<endl;
    yi.clear();
    cout<<yi.size()<<endl;
    yi.push_back(111);
    yi.emplace(yi.begin()+1,23);
    for(auto&it:yi)
        cout<<it<<" ";
    cout<<endl;
    yi.emplace_back(45);
    for(auto&it:yi)
        cout<<it<<" ";
    cout<<endl;
    yi.emplace_front(987);
    for(auto&it:yi)
        cout<<it<<" ";
    cout<<endl;
    return 0;
}

