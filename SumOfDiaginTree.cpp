#include<bits/stdc++.h>
using namespace std;
list<int>*adj;
struct node
{
    int val;
    node *l;
    node*r;
};
node*get(int x)
{
    node*te;
    te=new node();
    te->val=x;
    te->l=NULL;
    te->r=NULL;
    return te;
}
void diag(node *root,int lev)
{
    if(root==NULL)
        return ;
    adj[lev].push_back(root->val);
    diag(root->l,lev+1);
    diag(root->r,lev);
}
int main()
{
    adj=new list<int>[3];
    node *root;
    root=get(1);
    root->l=get(2);
    root->r=get(3);
    root->l->l=get(4);
    root->l->r=get(5);
    root->l->r->l=get(8);
    root->r->r=get(6);
    root->r->r->l=get(7);
    diag(root,0);
    for(int i=0;i<3;i++)
    {
        for(list<int>::iterator it=adj[i].begin();it!=adj[i].end();it++)
        {
            cout<<*it<<" ";
        }
        cout<<endl;
    }
}
