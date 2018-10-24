#include<bits/stdc++.h>
using namespace std;
#define umultimap unordered_multimap
typedef umultimap<string,string> stringmultimap;
template<class T>
T cmerge(T a,T b)
{
    T t(a);
    t.insert(b.begin(),b.end());
    return t;
}
int main()
{
    umultimap<string,double>myrecipe,mypantry = {{"milk",2.0},{"flour",1.5}};
    stringmultimap first;
    stringmultimap second ( {{"apple","red"},{"lemon","yellow"}} );
    stringmultimap third ( {{"orange","orange"},{"strawberry","red"}} );
    stringmultimap fourth (second);
    stringmultimap fifth (cmerge(third,fourth));        // move
    stringmultimap sixth (fifth.begin(),fifth.end());
    for(const pair<string,string>&x:sixth)
        cout<<x.first<<"'"<<x.second<<" ";
    cout<<endl;
    second=sixth;
    cout<<first.size()<< " "<<second.size()<<endl;  //clear and empty and swap are same.
    for ( int i = 0; i < second.bucket_count(); ++i)
    {
       cout << "bucket #" << i << " contains:";
     for ( auto local_it = second.begin(i); local_it!= second.end(i); ++local_it )
       cout << " " << local_it->first << ":" << local_it->second;
     cout << std::endl;
    }
    cout<<sixth.find("lemon")->first<<" "<<sixth.find("lemon")->second<<endl;
    // emplace and emplace_hint works same way.
    sixth.insert(make_pair("aaa","bbb"));
    myrecipe.insert(mypantry.begin(),mypantry.end());
    for(auto x:myrecipe)
        cout<<x.first<<"'"<<x.second<<" ";
    cout<<endl;
    myrecipe.insert(myrecipe.begin(),make_pair("xyz",3.14));
    for(auto x:myrecipe)
        cout<<x.first<<"'"<<x.second<<" ";
    cout<<endl;
    myrecipe.erase(myrecipe.begin());
    myrecipe.erase("milk");
    for(auto x:myrecipe)
        cout<<x.first<<"'"<<x.second<<" ";
    cout<<endl;
    myrecipe.insert({"kkk",9.99});
    myrecipe.insert({"vvv",1.19});
    myrecipe.insert({"yyy",2.99});
    myrecipe.insert({"mmm",6.49});
    myrecipe.insert({"nnn",7.99});
    for(auto x:myrecipe)
        cout<<x.first<<"'"<<x.second<<" ";
    cout<<endl;
    myrecipe.erase(myrecipe.find("nnn"),myrecipe.find("kkk"));
    for(auto x:myrecipe)
        cout<<x.first<<"'"<<x.second<<" ";
    cout<<endl;
    umultimap<string,double>::iterator x=myrecipe.find("kkk");
    cout<<myrecipe.bucket(x->first)<<endl;  // bucket_size and max_bucket_size all are same too here.
    // load_factor and max_load_factor and rehash and reserve all are simple.
    cout<<myrecipe.hash_function()("kkk")<<endl;
    stringmultimap a = { {"AAPL","Apple"}, {"MSFT","Microsoft"}, {"GOOG","Google"} };
    stringmultimap b = { {"MSFT","Microsoft"}, {"GOOG","Google"}, {"AAPL","Apple"} };
    stringmultimap c = { {"MSFT","Microsoft Corp."}, {"GOOG","Google Inc."}, {"AAPL","Apple Inc."} };
    if (a==b) std::cout << "a and b are equal\n";
    if (b!=c) std::cout << "b and c are not equal\n";
    unordered_multimap<std::string,std::string> mymultimap;
    bool case_insensitive = mymultimap.key_eq()("test","TEST");
    std::cout << "mymultimap.key_eq() is ";
    std::cout << ( case_insensitive ? "case insensitive" : "case sensitive" );
    std::cout << std::endl;

    return 0;
}
