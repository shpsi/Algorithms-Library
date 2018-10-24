#include<bits/stdc++.h>
using namespace std;
#define ptr struct node *
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
void ino(ptr root)
{
    stack<ptr>st;
    ptr indicator=root;
    while(1)
    {
        if(indicator!=NULL)
        {
            st.push(indicator);
            indicator=indicator->left;
        }
        else
        {
            if(st.empty())
               break;
            ptr m=st.top();
            cout<<m->val<<" ";
            st.pop();
            indicator=m->right;
        }
    }
    cout<<endl;
}
int main()
{
    struct node * root=NULL;
    root=insert(root,4);
    root=insert(root,1);
  //  cout<<"viii= "<<root->val<<endl;
    root=insert(root,5);
    root=insert(root,2);
    root=insert(root,3);
    ino(root);
    return 0;
}
