#include<bits/stdc++.h>
using namespace std;
int n;
int ind=0;
struct node
{
    int val;
    struct node* left;
    struct node *right;
};
node * make(int a[])
{
    if(ind==n||a[ind]==-1)
    {
        ind++;
        return NULL;
    }
    node *root=new node();
    root->val=a[ind];
    ind++;
    root->left=make(a);
    root->right=make(a);
    return root;
}
int b[100],bi=0;
void pre(node*root)
{
    if(root)
    {
        b[bi]=root->val;
        bi++;
        pre(root->left);
        pre(root->right);
    }
    else
        b[bi]=-1,bi++;
}
int main()
{
    node*root;
    int a[]={7,2,1,-1,-1,-1,5,3,-1,-1,8,-1,-1};
    n=sizeof(a)/sizeof(a[0]);
    root=make(a);
    pre(root);
    for(int i=0;i<bi;i++)
        cout<<b[i]<<" ";
    cout<<endl;
    return 0;
}
