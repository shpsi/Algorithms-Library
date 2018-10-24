#include<bits/stdc++.h>
using namespace std;
#define uset unordered_set
template<class T>
T cmerge(T a,T b)
{
    T t(a);
    t.insert(b.begin(),b.end());
    return t;
}
int main()
{
    uset<string>first;
    uset<string>second({"app","blue","red"});
    uset<string>third(second);
    uset<string>forth({"orange","pink","yellow"});
    uset<string>fifth(cmerge(third,forth));
    uset<string>sixth(fifth.begin(),fifth.end());
    for(uset<string>::iterator it=sixth.begin();it!=sixth.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    forth=second;
    for(uset<string>::iterator it=forth.begin();it!=forth.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    cout<<forth.size()<<" "<<sixth.size()<<endl;
    forth.clear();   // forth=uset<string>();
    cout<<forth.size()<<" "<<sixth.size()<<endl;
    for ( int i = 0; i < sixth.bucket_count(); ++i)
    {
       cout << "bucket #" << i << " contains:";
       for ( auto local_it = sixth.begin(i); local_it!= sixth.end(i); ++local_it )
             cout << " " << *local_it;
       cout << std::endl;
    }
    for(uset<string>::const_iterator it=forth.cbegin();it!=forth.cend();it++)
        cout<<*it<<" ";
    cout<<endl;
    for ( int i = 0; i < sixth.bucket_count(); ++i)
    {
       cout << "bucket #" << i << "has size "<< sixth.bucket_size(i)<<" contains:";
       for ( auto local_it = sixth.cbegin(i); local_it!= sixth.cend(i); ++local_it )
             cout << " " << *local_it;
       cout << std::endl;
    }
    sixth.insert({"hurr","ram"});
    string a[]={"red","green"};
    sixth.insert(a,a+2);
    for(uset<string>::const_iterator it=sixth.cbegin();it!=sixth.cend();it++)
        cout<<*it<<" ";
    cout<<endl;
    sixth.erase("red");
    sixth.erase(sixth.find("hurr"));
    sixth.erase(sixth.find("green"),sixth.find("pink"));
    for(uset<string>::const_iterator it=sixth.cbegin();it!=sixth.cend();it++)
        cout<<sixth.bucket(*it)<<" "<<*it<<endl;
    cout<<endl;
    sixth.emplace("orange");
    cout<<sixth.count("orange")<<endl;
    cout<<sixth.max_load_factor()<<endl;
    cout<<sixth.max_bucket_count()<<endl;
    uset<string>aa = {"AAPL","MSFT","GOOG"},bb = {"MSFT","GOOG","AAPL"},cc = {"MSFT","GOOG","AAPL","ORCL"};
    if (aa==bb)
        cout << "a and b are equal\n";
    if (bb!=cc)
        cout << "b and c are not equal\n";
    uset<string>axa;
    bool ab=axa.key_eq()("check","CHECK");
    if(ab)
        cout<<"case inses";
    else
        cout<<"case sensi";
    cout<<endl;
    cout<<axa.hash_function()("cheeee")<<endl;
    axa.reserve(15); //changes bcnt
    axa.rehash(62);  //new hashing is done with changed bcnt
    cout<<axa.bucket_count()<<endl;
    float z = axa.max_load_factor();
    axa.max_load_factor ( z / 2.0 );
    cout << "[max_load_factor halved]" << std::endl;
    cout << "load_factor = " << axa.load_factor() << std::endl;
    return 0;
}
