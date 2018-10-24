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
void level(ptr root)
{
    stack<ptr>s0,s1;
    int mark=0;
    s0.push(root);
    while(!s0.empty() || !s1.empty())
    {
        if(mark==0)
        {
            while(!s0.empty())
            {
                ptr x=s0.top();
                cout<<x->val<<" ";
                s0.pop();
                if(x->left)
                {
                    s1.push(x->left);
                }
                if(x->right)
                {
                    s1.push(x->right);
                }
            }
            mark=1-mark;
        }
        else
        {
            while(!s1.empty())
            {
                ptr x=s1.top();
                cout<<x->val<<" ";
                s1.pop();
                if(x->right)
                {
                    s0.push(x->right);
                }
                if(x->left)
                {
                    s0.push(x->left);
                }
            }
            mark=1-mark;
        }
    }
}
int main()
{
    struct node * root=NULL;
    root=insert(root,4);
    root=insert(root,1);
    root=insert(root,5);
    root=insert(root,2);
    root=insert(root,3);
    level(root);
    return 0;
}
