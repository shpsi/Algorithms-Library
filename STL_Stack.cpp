#include<bits/stdc++.h>
using namespace std;
int main()
{
    stack<string>s;
    s.push("june");
    s.push("july");
    s.push("april");
    stack<string>f;
    cout<<s.size()<<endl;
    swap(s,f);
    f.emplace("may");
    while(!f.empty())
    {
        cout<<f.top()<<" ";
        cout<<endl;
        f.pop();
    }
    return 0;
}
