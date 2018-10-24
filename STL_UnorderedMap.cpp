#include<bits/stdc++.h>
using namespace std;
#define umap unordered_map
typedef umap<string,string> stringmap;
template<class T>
T cmerge(T a,T b)
{
    T t(a);
    t.insert(b.begin(),b.end());
    return t;
}
int main()
{
    umap<string,double>myrecipe,mypantry = {{"milk",2.0},{"flour",1.5}};
    stringmap first;
    stringmap second ( {{"apple","red"},{"lemon","yellow"}} );
    stringmap third ( {{"orange","orange"},{"strawberry","red"}} );
    stringmap fourth (second);
    stringmap fifth (cmerge(third,fourth));        // move
    stringmap sixth (fifth.begin(),fifth.end());
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
    cout<<sixth["lemon"]<<endl;
    cout<<sixth.at("lemon")<<endl;
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
    umap<string,double>::iterator x=myrecipe.find("kkk");
    cout<<myrecipe.bucket(x->first)<<endl;  // bucket_size and max_bucket_size all are same too here.
    // load_factor and max_load_factor and rehash and reserve all are simple.
    cout<<myrecipe.hash_function()("kkk")<<endl;
    stringmap a = { {"AAPL","Apple"}, {"MSFT","Microsoft"}, {"GOOG","Google"} };
    stringmap b = { {"MSFT","Microsoft"}, {"GOOG","Google"}, {"AAPL","Apple"} };
    stringmap c = { {"MSFT","Microsoft Corp."}, {"GOOG","Google Inc."}, {"AAPL","Apple Inc."} };
    if (a==b) std::cout << "a and b are equal\n";
    if (b!=c) std::cout << "b and c are not equal\n";
    unordered_map<std::string,std::string> mymap;
    bool case_insensitive = mymap.key_eq()("test","TEST");
    std::cout << "mymap.key_eq() is ";
    std::cout << ( case_insensitive ? "case insensitive" : "case sensitive" );
    std::cout << std::endl;

    return 0;
}
