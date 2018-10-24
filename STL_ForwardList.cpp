#include<bits/stdc++.h>
using namespace std;
#define fl forward_list
int comp1(double a,double b)
{
    return int(a)==int(b);
}
int comp2(double a,double b)
{
    return fabs(a-b)<5.0;
}
int comp3(double a)
{
    return int(a)==4;
}
int main()
{
    fl<int> first;
    fl<int> second(3,100);
    fl<int> third(second.begin(),second.end());
    fl<int> forth(third);
    fl<int> fifth(move(forth));
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
    for(int&it:fifth)
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
    forth.insert_after(forth.before_begin(),111);
    for(int&it:forth)
        cout<<it<<" ";
    cout<<endl;
    for(fl<int>::iterator it=forth.begin();it!=forth.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    forth.insert_after(forth.cbefore_begin(),000);
    for(fl<int>::const_iterator it=forth.cbegin();it!=forth.cend();it++)
        cout<<*it<<" ";
    cout<<endl;
    string sss;
    cout<<(forth.empty()?sss="is empty":sss="is not empty")<<endl;
    forth.front()=12;
    for(int&it:forth)
        cout<<it<<" ";
    cout<<endl;
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
    forth.emplace_after(forth.begin(),888);
    for(int&it:forth)
        cout<<it<<" ";
    cout<<endl;
    forth.insert_after(forth.begin(),77);
    for(int&it:forth)
        cout<<it<<" ";
    cout<<endl;
    third.clear();
    third.swap(forth);
    for(int&it:third)
        cout<<it<<" ";
    cout<<endl;
    swap(third,forth);
    fl<int>::iterator it=forth.begin();
    it++;it++;
    forth.erase_after(it);
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
    forth.sort(greater<int>());
    for(int&it:forth)
        cout<<it<<" ";
    cout<<endl;
    fl<double>myfl={ 15.2, 73.0, 3.14, 15.85, 69.5,73.0, 3.99, 15.2, 69.2,  18.5 };
    for(double&it:myfl)
        cout<<it<<" ";
    cout<<endl;
    myfl.sort();
    for(double&it:myfl)
        cout<<it<<" ";
    cout<<endl;
    myfl.unique();
    for(double&it:myfl)
        cout<<it<<" ";
    cout<<endl;
    myfl.unique(comp1);
    for(double&it:myfl)
        cout<<it<<" ";
    cout<<endl;
    myfl.unique(comp2);
    for(double&it:myfl)
        cout<<it<<" ";
    cout<<endl;
    fl<double> mfirst = {4.2, 2.9, 3.1};
    fl<double> msecond = {1.4, 7.7, 3.1};
    mfirst.sort(greater<double>()); // any comp fn for resulr and first and second by comp too
    msecond.sort(greater<double>());
    mfirst.merge(msecond,greater<double>());
    for(double&it:mfirst)
        cout<<it<<" ";
    cout<<endl;
    mfirst.resize(3);
    for(double&it:mfirst)
        cout<<it<<" ";
    cout<<endl;
    mfirst.resize(6);
    for(double&it:mfirst)
        cout<<it<<" ";
    cout<<endl;
    mfirst.remove(0);
    for(double&it:mfirst)
        cout<<it<<" ";
    cout<<endl;
    mfirst.insert_after(mfirst.begin(),1.3);
    mfirst.insert_after(mfirst.begin(),4.1);
    mfirst.insert_after(mfirst.begin(),7.1);
    mfirst.remove_if(comp3);
    for(double&it:mfirst)
        cout<<it<<" ";
    cout<<endl;
    fl<int>ff={1,2,3};
    fl<int>ss={10,20,30};
    auto itr = ff.begin();
    for(int&it:ff)cout<<it<<" ";cout<<endl;
    for(int&it:ss)cout<<it<<" ";cout<<endl;
    ff.splice_after(ff.before_begin(),ss);
    for(int&it:ff)cout<<it<<" ";cout<<endl;
    for(int&it:ss)cout<<it<<" ";cout<<endl;
    ss.splice_after(ss.before_begin(),ff,ff.begin(),itr);
    for(int&it:ff)cout<<it<<" ";cout<<endl;
    for(int&it:ss)cout<<it<<" ";cout<<endl;
    ff.splice_after(ff.before_begin(),ss,ss.begin());
    for(int&it:ff)cout<<it<<" ";cout<<endl;
    for(int&it:ss)cout<<it<<" ";cout<<endl;
    return 0;
}
