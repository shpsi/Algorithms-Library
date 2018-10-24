#include<bits/stdc++.h>
using namespace std;
#define ptr struct node *
struct node
{
    struct node * left;
    struct node * right;
    int val;
};
void po(struct node * root)
{
    if(root!=NULL)
    {
        po(root->left);
        po(root->right);
        cout<<root->val<<" ";
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
    while(iroot!=NULL)
    {
        if(iroot->val>x)
          { baap=iroot;iroot=iroot->left;}
        else
           {baap=iroot,iroot=iroot->right;}
    }
    iroot=baap;
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
void post(ptr root)
{
    stack< struct node*> st1,st2;
    st1.push(root);
    while(!st1.empty())
    {
        struct node *x=st1.top();
        st1.pop();
        st2.push(x);
        if(x->left!=NULL)
            st1.push(x->left);
        if(x->right!=NULL)
            st1.push(x->right);
    }
    while(!st2.empty())
    {
        struct node *x=st2.top();
        st2.pop();
        cout<<x->val<<" ";
    }
    cout<<endl;
}
int main()
{
    struct node * root=NULL;
    root=insert(root,4);
    root=insert(root,1);
    root=insert(root,5);
    root=insert(root,2);
    root=insert(root,3);
    po(root);
    cout<<endl;
    post(root);
    return 0;
}
