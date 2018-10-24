#include<bits/stdc++.h>
using namespace std;
struct zbox
{
    int l;
    int r;
};
void comp_z_arr(string s,int a[])
{
    a[0]=0;zbox * zb;
    zb=(struct zbox *)malloc(sizeof(zbox));
    zb->l=-1;zb->r=-1;
    int i,j,k;
    i=1;
    j=0;
    k=0;
    while(s[i]==s[j])
    {
        i++;
        j++;
        k++;
    }
    a[1]=k;
    for(i=2;i<s.length();i++)
    {
        if(s[i]!=s[0])
        {
            a[i]=0;
            continue;
        }
        j=i;
        k=0;
        int cnt=0;
        while(s[j]==s[k])
        {
            j++;
            k++;
            cnt++;
        }
        a[i]=cnt;
        if(cnt==1)
        {
            continue;
        }
        zb->l=i;
        zb->r=i+cnt-1;
        i++;
        j=1;
        for(;i<=zb->r;i++)
        {
            if(i+a[j]<=zb->r)
            {
                a[i]=a[j];
                j++;
            }
            else
                break;
        }
        if(i>zb->r)
        {
            i--;
            continue;
        }
        zb->l=i;
        cnt=a[j];
        int mm=cnt;
        k=zb->r+1;
        while(k<s.length() && s[k]==s[mm])
        {
            k++;
            mm++;
            cnt++;
        }
        a[i]=cnt;
        zb->r=zb->r+cnt-1;
    }
}
int main()
{
    string text,pattern;
    cin>>text>>pattern;
    string comb_str=pattern+"$"+text;
    int *z;
    z=new int[comb_str.length()];
    comp_z_arr(comb_str,z);
    for(int i=pattern.length()+1;i<comb_str.length();i++)
    {
        if(z[i]==pattern.length())
            cout<<"present at "<<i-pattern.length()-1<<endl;
    }
    return 0;
}
