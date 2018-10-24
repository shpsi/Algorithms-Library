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
    map<char,int> mp1;
    mp1['a']=10;
    mp1['b']=30;
    mp1['c']=50;
    mp1['d']=70;
    map<char,int>mp2(mp1.begin(),mp1.end());
    map<char,int>mp3(mp2);
    for(map<char,int>::iterator it1=mp1.begin();it1!=mp1.end();it1++)
        cout<<it1->first<<" "<<it1->second<<endl;
    for(map<char,int>::iterator it1=mp2.begin();it1!=mp2.end();it1++)
        cout<<it1->first<<" "<<it1->second<<endl;
    for(map<char,int>::iterator it1=mp3.begin();it1!=mp3.end();it1++)
        cout<<it1->first<<" "<<it1->second<<endl;
    map<char,int,comp1>mp4;
    swap(mp3,mp1);
    cout<<mp1.size()<<endl;
    mp1=map<char,int>();
    cout<<mp1.size()<<endl;
    if(!mp1.empty())
        cout<<"Not empty\n";
    else
        cout<<" Empty\n";
    mp1.swap(mp3);
    mp3.clear();
    cout<<mp3.size()<<endl;
    for(map<char,int>::reverse_iterator it1=mp1.rbegin();it1!=mp1.rend();it1++)
        cout<<it1->first<<" "<<it1->second<<endl;
    for(map<char,int>::const_iterator it1=mp1.cbegin();it1!=mp1.cend();it1++)
        cout<<it1->first<<" "<<it1->second<<endl;
    for(map<char,int>::const_reverse_iterator it1=mp1.crbegin();it1!=mp1.crend();it1++)
        cout<<it1->first<<" "<<it1->second<<endl;
    cout<<mp1['a']<<endl;
    cout<<mp1['f']<<endl;
    mp1.insert(make_pair('z',26));
    cout<<mp1['z']<<endl;
    map<char,int>::iterator it=mp1.find('c');
    mp1.insert(it,make_pair('g',7));
    cout<<mp1['g'];
    mp3.insert(mp1.begin(),mp1.find('g'));
    for(map<char,int>::iterator it1=mp3.begin();it1!=mp3.end();it1++)
        cout<<it1->first<<" "<<it1->second<<endl;
    it=mp1.find('g');
    mp1.erase(it);
    mp1.erase('z');
    cout<<mp1.size()<<endl;
    map<char,int>::iterator itt=mp1.end();
    itt--;
    mp1.erase(mp1.begin(),itt);
    cout<<mp1.size()<<endl;
    map<char,int> mymap;
    auto itj = mymap.end();
    itj = mymap.emplace_hint(itj,'b',10); //similarly emplace without it
    mymap.emplace_hint(itj,'a',12);
    mymap.emplace_hint(mymap.end(),'c',14);
    cout << "mymap contains:";
    for (auto& x: mymap)
         cout << " [" << x.first << ':' << x.second << ']';
    cout << '\n';
    pair<map<char,int>::iterator,map<char,int>::iterator> ret=mymap.equal_range('b');
    cout<<ret.first->first<<" "<<ret.second->first<<endl;
    cout<<mymap.upper_bound('b')->first<<" "<<mymap.lower_bound('c')->first<<endl; // >u_b and<=l_b
    map<char,int>myset;
    map<char,int>::value_compare mycomp = myset.value_comp();   // value<<=>>key
    for (int i=0; i<=5; i++) myset.insert(make_pair(char('a'+i),i));
    pair<char,int> highest=*myset.rbegin();
    map<char,int>::iterator itd=myset.begin();
    do
    {
       cout << ' ' << itd->first;
    } while ( mycomp(*(++itd),highest) );
    cout<<endl;
    map<char,int>s;
    pair<const char,int> * ptr=s.get_allocator().allocate(5);
    for(int i=0;i<4;i++)
        s.get_allocator().construct(&ptr[i],make_pair(char('a'+i),i+1));
    for(int i=0;i<4;i++)
        cout<<ptr[i].first<<"'"<<ptr[i].second<<" ";
    cout<<endl;
    return 0;
}
