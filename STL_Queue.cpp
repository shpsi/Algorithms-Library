#include<bits/stdc++.h>
using namespace std;
int main()
{
    queue<string>s;
    s.push("june");
    s.push("july");
    s.push("april");
    queue<string>f;
    cout<<s.size()<<endl;
    swap(s,f); // you can use s.swap(f);
    //deque<int> mydeck (3,100);
    queue<string>ss(f);
    f.emplace("may");
    while(!f.empty())
    {
        cout<<f.front()<<" "<<f.back();
        cout<<endl;
        f.pop();
    }
    cout<<ss.size()<<endl;
    while(!ss.empty())
    {
        cout<<ss.front()<<" "<<ss.back();
        cout<<endl;
        ss.pop();
    }
    return 0;
}
