#include<bits/stdc++.h>
using namespace std;
#define fl list
int comp(int a) //true if first goes before second
{
    return a%2!=1;
}
int comp2(int a,int b)
{
    return a==b;
}
class comp1
{
public:
  bool operator() (int first, int second)
  { return first*5==second; }
};
int comp3(double a,double b)
{
    return int(a)<int(b);
}
int main()
{
    fl<int> first;
    fl<int> second(3,100);
    fl<int> third(second.begin(),second.end());
    fl<int> forth(third);
    for(int&it:first)
        cout<<it<<" ";
    cout<<endl;
    for(int&it:second)
        cout<<it<<" ";
    cout<<endl;
    for(int&it:third)
        cout<<it<<" ";
    cout<<endl;
    for(int&it:forth)
        cout<<it<<" ";
    cout<<endl;
    third.assign(4,100);
    forth=third;
    for(int&it:third)
        cout<<it<<" ";
    cout<<endl;
    for(int&it:forth)
        cout<<it<<" ";
    cout<<endl;
    string sss;
    cout<<(forth.empty()?sss="is empty":sss="is not empty")<<endl;
    forth.front()=12;
    for(int&it:forth)
        cout<<it<<" ";
    cout<<endl;
    cout<<forth.size()<<endl;
    cout<<forth.max_size()<<endl;
    forth.assign({1,2,3,4,5,6});
    for(int&it:forth)
        cout<<it<<" ";
    cout<<endl;
    forth.emplace_front(999);
    for(int&it:forth)
        cout<<it<<" ";
    cout<<endl;
    forth.pop_front();
    for(int&it:forth)
        cout<<it<<" ";
    cout<<endl;
    forth.push_front(999);
    for(int&it:forth)
        cout<<it<<" ";
    cout<<endl;
    forth.emplace_back(444);
    for(int&it:forth)
        cout<<it<<" ";
    cout<<endl;
    forth.pop_back();
    for(int&it:forth)
        cout<<it<<" ";
    cout<<endl;
    third.clear();
    third.swap(forth);
    for(int&it:third)
        cout<<it<<" ";
    cout<<endl;
    swap(third,forth);
    for(int&it:forth)cout<<it<<" ";cout<<endl;
    forth.resize(3);
    for(int&it:forth)
        cout<<it<<" ";
    cout<<endl;
    forth.resize(6);
    for(int&it:forth)
        cout<<it<<" ";
    cout<<endl;
    forth.erase(forth.begin());
    for(int&it:forth)
        cout<<it<<" ";
    cout<<endl;
    list<int>::iterator itr,it2;
    itr=forth.begin();
    it2=forth.begin();
    itr++;it2++;it2++;it2++;
    forth.erase(itr,it2);
    for(int&it:forth)
        cout<<it<<" ";
    cout<<endl;
    itr=forth.begin();
    forth.insert(itr,234);
    for(int&it:forth)
        cout<<it<<" ";
    cout<<endl;
    itr++;
    forth.insert(itr,2,555);
    for(int&it:forth)
        cout<<it<<" ";
    cout<<endl;
    itr++;
    list<int>trial(2,111);
    forth.insert(itr,trial.begin(),trial.end());
    for(int&it:forth)
        cout<<it<<" ";
    cout<<endl;
    itr=forth.begin();
    itr++;
    forth.emplace(itr,531);
    for(int&it:forth)
        cout<<it<<" ";
    cout<<endl;
    forth.reverse();
    for(int&it:forth)
        cout<<it<<" ";
    cout<<endl;
    forth.sort();
    for(int&it:forth)
        cout<<it<<" ";
    cout<<endl;
    forth.remove(0);
    for(int&it:forth)
        cout<<it<<" ";
    cout<<endl;
    forth.remove_if(comp);
    for(int&it:forth)
        cout<<it<<" ";
    cout<<endl;
    list<int>s;
    int * ptr=s.get_allocator().allocate(5);
    for(int i=0;i<4;i++)
        s.get_allocator().construct(&ptr[i],i+1);
    for(int i=0;i<4;i++)
        cout<<ptr[i]<<" ";
    cout<<endl;
    for(int i=0;i<4;i++)
        s.get_allocator().destroy(&ptr[i]);
    s.get_allocator().deallocate(ptr,5);
    forth.unique(comp2);
    for(int&it:forth)
        cout<<it<<" ";
    cout<<endl;
    forth.insert(forth.end(),111);
    forth.insert(forth.end(),555);
    for(int&it:forth)
        cout<<it<<" ";
    cout<<endl;
    forth.unique(comp1());
    for(int&it:forth)
        cout<<it<<" ";
    cout<<endl;
    list<double> fir, sec;
    fir.push_back(3.1);
    fir.push_back(2.2);
    fir.push_back(2.9);
    sec.push_back(3.7);
    sec.push_back(7.1);
    sec.push_back(1.4);
    fir.sort();
    sec.sort();
    fir.merge(sec); // (second is now empty)
    for (double&it:fir)
       cout <<it<<" ";
    cout << '\n';
    sec.push_back (2.1);
    fir.merge(sec,comp3);
    for (double&it:fir)
       cout <<it<<" ";
    cout << '\n';
    fl<int>ff={1,2,3};
    fl<int>ss={10,20,30};
    itr = ff.begin();
    for(int&it:ff)cout<<it<<" ";cout<<endl;
    for(int&it:ss)cout<<it<<" ";cout<<endl;
    ff.splice(ff.begin(),ss);
    for(int&it:ff)cout<<it<<" ";cout<<endl;
    for(int&it:ss)cout<<it<<" ";cout<<endl;
    ss.splice(ss.begin(),ff,ff.begin(),itr);
    for(int&it:ff)cout<<it<<" ";cout<<endl;
    for(int&it:ss)cout<<it<<" ";cout<<endl;
    ff.splice(ff.begin(),ss,ss.begin());
    for(int&it:ff)cout<<it<<" ";cout<<endl;
    for(int&it:ss)cout<<it<<" ";cout<<endl;
    return 0;
}
