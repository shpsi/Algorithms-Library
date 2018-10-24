#include<bits/stdc++.h>
using namespace std;
#define ptr struct node *
#define dtype pair<bool,pair< int,pair<int,int> > >
int ans=-1;
struct node
{
    struct node *left;
    struct node *right;
    int val;
};
ptr get(int x)
{
    ptr root;
    root=(ptr)malloc(sizeof(struct node ));
    root->val=x;
    root->left=NULL;
    root->right=NULL;
    return root;
}
dtype fun(ptr root)
{
    if(root==NULL)
    {
        return make_pair(true,make_pair(0,make_pair(INT_MAX,INT_MIN)));
    }
    if(root->left==NULL && root->right==NULL)
    {
        return make_pair(true,make_pair(1,make_pair(root->val,root->val)));
    }
    dtype a=fun(root->left);
    dtype b=fun(root->right);
    int sz;
    bool is;
    sz=a.second.first+b.second.first+1;
    if(a.first!=true||b.first!=true)
    {
        return make_pair(false,make_pair(0,make_pair(0,0))); // doesn't matter
    }
    if(root->val> a.second.second.second && root->val <b.second.second.first)
    {
        ans=max(ans,sz);
        return make_pair(true,make_pair(sz,make_pair(a.second.second.first,b.second.second.second)));
    }
    return make_pair(false,make_pair(0,make_pair(0,0))); // doesn't matter
}
void post(ptr root)
{
    if(root)
    {
        post(root->left);
        post(root->right);
        cout<<root->val<<" ";
    }
}
int main()
{
    ptr root;
    root=(ptr)malloc(sizeof(struct node ));
    root->val=25;
    root->left=get(18);
    root->right=get(50);
    root->left->left=get(19);
    root->left->right=get(20);
    root->left->left->left=NULL;
    root->left->left->right=get(15);
    root->left->right->left=get(18);
    root->left->right->right=get(25);
    root->right->left=get(35);
    root->right->right=get(60);
    root->right->right->left=get(55);
    root->right->right->right=get(70);
    root->right->left->left=get(20);
    root->right->left->right=get(40);
    root->right->left->left->left=NULL;
    root->right->left->left->right=get(25);
    dtype res=fun(root);
    cout<<endl<<ans<<endl;
    return 0;
}
