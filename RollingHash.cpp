#include<bits/stdc++.h>
using namespace std;
map<int,bool>mp;
int main()
{
    string s;
    cin>>s;
    int hashv=0;
    int power[11];
    int pow=1;
    power[0]=1;
    int i;
    for(i=1;i<11;i++)
        power[i]=power[i-1]*2;
    for(i=0;i<10;i++)
        hashv+=power[i]*(s[i]-'A'+1);
    mp[hashv]=true;
   // cout<<hashv<<endl;
    for(i=10;i<s.length();i++)
    {
        hashv=hashv-(s[i-10]-'A'+1);
        hashv/=2;
        hashv+=power[9]*(s[i]-'A'+1);
       // cout<<hashv<<endl;
        if(mp.find(hashv)!=mp.end())
        {
            int k=i-9;
            while(k<=i)
            {
                cout<<s[k];
                k++;
            }
            cout<<endl;
        }
        else
            mp[hashv]=true;
    }
    return 0;
}
