#include<bits/stdc++.h>
using namespace std;
class comp1
{
    bool operator()(int lhs,int rhs)
    {
        return lhs<rhs;
    }
};
int main()
{
    multimap<char,int> mp1;
    mp1.insert(make_pair('a',10));
    mp1.insert(make_pair('b',30));
    mp1.insert(mp1.begin(),make_pair('c',50));
    mp1.insert(mp1.begin(),make_pair('d',70));
    multimap<char,int>mp2(mp1.begin(),mp1.end());
    multimap<char,int>mp3(mp2);
    for(multimap<char,int>::iterator it1=mp1.begin();it1!=mp1.end();it1++)
        cout<<it1->first<<" "<<it1->second<<endl;
    for(multimap<char,int>::iterator it1=mp2.begin();it1!=mp2.end();it1++)
        cout<<it1->first<<" "<<it1->second<<endl;
    for(multimap<char,int>::iterator it1=mp3.begin();it1!=mp3.end();it1++)
        cout<<it1->first<<" "<<it1->second<<endl;
    multimap<char,int,comp1>mp4;
    swap(mp3,mp1);
    cout<<mp1.size()<<endl;
    mp1=multimap<char,int>();
    cout<<mp1.size()<<endl;
    if(!mp1.empty())
        cout<<"Not empty\n";
    else
        cout<<" Empty\n";
    mp1.swap(mp3);
    mp3.clear();
    cout<<mp3.size()<<endl;
    for(multimap<char,int>::reverse_iterator it1=mp1.rbegin();it1!=mp1.rend();it1++)
        cout<<it1->first<<" "<<it1->second<<endl;
    for(multimap<char,int>::const_iterator it1=mp1.cbegin();it1!=mp1.cend();it1++)
        cout<<it1->first<<" "<<it1->second<<endl;
    for(multimap<char,int>::const_reverse_iterator it1=mp1.crbegin();it1!=mp1.crend();it1++)
        cout<<it1->first<<" "<<it1->second<<endl;
    cout<<mp1.find('a')->second<<endl;
    cout<<mp1.find('f')->second<<endl;
    mp1.insert(make_pair('z',26));
    cout<<mp1.find('z')->second<<endl;
    multimap<char,int>::iterator it=mp1.find('c');
    mp1.insert(it,make_pair('g',7));
    cout<<mp1.find('g')->second<<endl;
    mp3.insert(mp1.begin(),mp1.find('g'));
    for(multimap<char,int>::iterator it1=mp3.begin();it1!=mp3.end();it1++)
        cout<<it1->first<<" "<<it1->second<<endl;
    it=mp1.find('g');
    mp1.erase(it);
    mp1.erase('z');
    cout<<mp1.size()<<endl;
    multimap<char,int>::iterator itt=mp1.end();
    itt--;
    mp1.erase(mp1.begin(),itt);
    cout<<mp1.size()<<endl;
    multimap<char,int> mymultimap;
    auto itj = mymultimap.end();
    itj = mymultimap.emplace_hint(itj,'b',10); //similarly emplace without it
    mymultimap.emplace_hint(itj,'a',12);
    mymultimap.emplace_hint(itj,'a',22);
    cout<<mymultimap.count('a')<<endl;
    mymultimap.emplace_hint(mymultimap.end(),'c',14);
    cout << "mymultimap contains:";
    for (auto& x: mymultimap)
         cout << " [" << x.first << ':' << x.second << ']';
    cout << '\n';
    pair<multimap<char,int>::iterator,multimap<char,int>::iterator> ret=mymultimap.equal_range('b');
    cout<<ret.first->first<<" "<<ret.second->first<<endl;
    cout<<mymultimap.upper_bound('b')->first<<" "<<mymultimap.lower_bound('c')->first<<endl; // >u_b and<=l_b
    multimap<char,int>myset;
    multimap<char,int>::value_compare mycomp = myset.value_comp();   // value<<=>>key
    for (int i=0; i<=5; i++) myset.insert(make_pair(char('a'+i),i));
    pair<char,int> highest=*myset.rbegin();
    multimap<char,int>::iterator itd=myset.begin();
    do
    {
       cout << ' ' << itd->first;
    } while ( mycomp(*(++itd),highest) );
    cout<<endl;
    multimap<char,int>s;
    pair<const char,int> * ptr=s.get_allocator().allocate(5);
    for(int i=0;i<4;i++)
        s.get_allocator().construct(&ptr[i],make_pair(char('a'+i),i+1));
    for(int i=0;i<4;i++)
        cout<<ptr[i].first<<"'"<<ptr[i].second<<" ";
    cout<<endl;
    return 0;
}
