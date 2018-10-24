#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>first;
    vector<int>second(5,100);
    vector<int>third(second.begin(),second.end());
    vector<int>forth(third);
    int a[]={4,5,6,7};
    vector<int>fifth(a,a+4);
    for(vector<int>::iterator it=first.begin();it!=first.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    for(vector<int>::iterator it=second.begin();it!=second.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    for(vector<int>::iterator it=third.begin();it!=third.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    for(vector<int>::iterator it=forth.begin();it!=forth.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    for(vector<int>::iterator it=fifth.begin();it!=fifth.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    vector<int>sizth={2344,4,5,7,9};
    for(vector<int>::iterator it=sizth.begin();it!=sizth.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    vector<int>foo(3,5);
    vector<int>bar(2,6);
    foo=bar;
    bar=vector<int>();
    first.push_back(1);
    first.push_back(2);
    first.push_back(3);
    first.push_back(4);
    first.push_back(5);
    first.push_back(6);
    cout<<foo.size()<<" "<<bar.size()<<endl;
    vector<int>doo(5);
    for(vector<int>::iterator it=doo.begin();it!=doo.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    for(vector<int>::const_reverse_iterator it=first.crbegin();it!=first.crend();it++)
        cout<<*it<<" ";
    cout<<endl;
    for(vector<int>::const_iterator it=first.cbegin();it!=first.cend();it++)
        cout<<*it<<" ";
    cout<<endl;
    for(vector<int>::reverse_iterator it=first.rbegin();it!=first.rend();it++)
        cout<<*it<<" ";
    cout<<endl;
    first.insert(first.end(),3,1200);
    cout<<first.size()<<endl;
    cout<<first.max_size()<<endl;
    vector<pair<int,int> >ss;
    cout<<ss.max_size()*2<<endl;
    for(vector<int>::const_iterator it=first.cbegin();it!=first.cend();it++)
        cout<<*it<<" ";
    cout<<endl;
    first.resize(5);
    cout<<"resize "<<first.size()<<endl;
    for(vector<int>::const_iterator it=first.cbegin();it!=first.cend();it++)
        cout<<*it<<" ";
    cout<<endl;
    first.resize(7,45);
    cout<<"resize "<<first.size()<<endl;
    for(vector<int>::const_iterator it=first.cbegin();it!=first.cend();it++)
        cout<<*it<<" ";
    cout<<endl;
    first.resize(11);
    cout<<"resize "<<first.size()<<endl;
    for(vector<int>::const_iterator it=first.cbegin();it!=first.cend();it++)
        cout<<*it<<" ";
    cout<<endl;
    vector<int>x(10);
    x.push_back(1);
    cout<<x.size()<<" "<<x.capacity()<<endl;
    x.push_back(2);
    x.push_back(8);
    int sum(0);
    while(!x.empty())
    {
        sum+=x.back();
        x.pop_back();
    }
    cout<<sum<<endl;
    vector<int> y;
    int sz=y.capacity();
    cout<<">"<<sz<<endl;
    for(int i=0;i<100;i++)
    {
        y.push_back(i);
        if(sz!=y.capacity())
        {
            sz=y.capacity();
            cout<<">"<<sz<<endl;
        }
    }
    vector<int> yi;
    yi.reserve(100);
    int szi=yi.capacity();
    cout<<">>"<<szi<<endl;
    for(int i=0;i<100;i++)
    {
        yi.push_back(i);
        if(szi!=yi.capacity())
        {
            szi=yi.capacity();
            cout<<">>"<<szi<<endl;
        }
    }
    cout<<yi.capacity()<<endl;
    yi.resize(1);
    cout<<yi.capacity()<<endl;
    yi.shrink_to_fit();
    cout<<yi.capacity()<<endl;
    yi[0]=333;
    cout<<yi[0]<<endl;
    cout<<yi.at(0)<<endl;
    cout<<yi.front()<<endl;
    yi.push_back(11);
    cout<<yi.back()<<endl;
    int*p=yi.data();
    cout<<*(p+1)<<endl;
    vector<int>si(5,100);
    vector<int>ti;
    ti.assign(si.begin(),si.end());
    for(vector<int>::const_iterator it=si.cbegin();it!=si.cend();it++)
        cout<<*it<<" ";
    cout<<endl;
    for(vector<int>::const_iterator it=ti.cbegin();it!=ti.cend();it++)
        cout<<*it<<" ";
    cout<<endl;
    yi.insert(yi.end()-1,22);
    for(vector<int>::const_iterator it=yi.cbegin();it!=yi.cend();it++)
        cout<<*it<<" ";
    cout<<endl;
    yi.insert(yi.begin(),yi.begin()+1,yi.end());
    for(vector<int>::const_iterator it=yi.cbegin();it!=yi.cend();it++)
        cout<<*it<<" ";
    cout<<endl;
    yi.erase(yi.begin()+2);
    for(vector<int>::const_iterator it=yi.cbegin();it!=yi.cend();it++)
        cout<<*it<<" ";
    cout<<endl;
    yi.erase(yi.begin()+1,yi.begin()+3);
    for(vector<int>::const_iterator it=yi.cbegin();it!=yi.cend();it++)
        cout<<*it<<" ";
    cout<<endl;
    for(vector<int>::const_iterator it=si.cbegin();it!=si.cend();it++)
        cout<<*it<<" ";
    cout<<endl;
    si.swap(yi);
    for(vector<int>::const_iterator it=yi.cbegin();it!=yi.cend();it++)
        cout<<*it<<" ";
    cout<<endl;
    for(vector<int>::const_iterator it=si.cbegin();it!=si.cend();it++)
        cout<<*it<<" ";
    cout<<endl;
    si.clear();
    cout<<si.size()<<endl;
    yi.emplace(yi.begin()+1,23);
    for(auto&it:yi)
        cout<<it<<" ";
    cout<<endl;
    yi.emplace_back(45);
    for(auto&it:yi)
        cout<<it<<" ";
    cout<<endl;
    swap(yi,si);
    for(auto&it:yi)
        cout<<it<<" ";
    cout<<endl;
    for(auto&it:si)
        cout<<it<<" ";
    cout<<endl;
    vector<bool>xg;
    bool zz=false;
    xg.push_back(zz);
    for(vector<bool>::iterator it=xg.begin();it!=xg.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    vector<int>s;
    int * ptr=s.get_allocator().allocate(5);
    for(int i=0;i<4;i++)
        s.get_allocator().construct(&ptr[i],i+1);
    for(int i=0;i<4;i++)
        cout<<ptr[i]<<" ";
    cout<<endl;
    for(int i=0;i<4;i++)
        s.get_allocator().destroy(&ptr[i]);
    s.get_allocator().deallocate(ptr,5);
    return 0;
}
