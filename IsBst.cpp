#include<bits/stdc++.h>
using namespace std;
#define ptr  struct node *
#define inf 10000
struct node
{
    struct node * left;
    struct node * right;
    int val;
};
void in(struct node * root)
{
    if(root!=NULL)
    {
        in(root->left);
        cout<<root->val<<" ";
        in(root->right);
    }
}
struct node * insert(struct node * root,int x)
{
    if(root==NULL)
    {
        root=(struct node * )malloc(sizeof(struct node));
        root->val=x;
        root->left=NULL;
        root->right=NULL;
        return root;
    }
    struct node *iroot=root,*baap;
   //  cout<<"v= "<<root->val<<endl;
    while(iroot!=NULL)
    {
   //     cout<<"v= "<<iroot->val<<endl;
        if(iroot->val>x)
          { baap=iroot;iroot=iroot->left;}
        else
           {baap=iroot,iroot=iroot->right;}
    }
    iroot=baap;
   // cout<<iroot->val<< " p\n";
    if(iroot->val>x)
    {
        iroot->left=(struct node *)malloc(sizeof(struct node));
        iroot->left->left=NULL;
        iroot->left->right=NULL;
        iroot->left->val=x;
    }
    else
    {
        iroot->right=(struct node *)malloc(sizeof(struct node));
        iroot->right->left=NULL;
        iroot->right->right=NULL;
        iroot->right->val=x;
    }
    return root;
}
int is(ptr root,int mi,int ma)
{
    if(root==NULL)
        return 1;
    if(root->val>=mi&& root->val<=ma)
        return is(root->left,mi,root->val) && is(root->right,root->val , ma);
    else
        return 0;
}
int main()
{
    struct node * root=NULL;
    root=insert(root,4);
    root=insert(root,1);
    root=insert(root,5);
    root=insert(root,2);
    root=insert(root,3);
    if(is(root,-inf,+inf))
        cout<<"yes";
    else
        cout<<"no";
    return 0;
}
