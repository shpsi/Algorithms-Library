#include<bits/stdc++.h>
using namespace std;
#define ptr struct node *
#define nullptr NULL
struct node
{
    int value;
    ptr left;
    ptr right;
    int h;
};
int height(ptr root)
{
    if(root==nullptr)
        return 0;
    return root->h;
}
ptr newnode(int x)
{
    ptr temp=(ptr)malloc(sizeof(struct node));
    temp->value=x;
    temp->left=nullptr;
    temp->right=nullptr;
    temp->h=1;
    return temp;
}
void in(ptr root)
{
    if(root==nullptr)
        return ;
    cout<<root->value<<" ";
    in(root->left);
    in(root->right);
}
int getb(ptr root)
{
    if(root==nullptr)
        return 0;
    return height(root->left)-height(root->right);
}
ptr leftr(ptr x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->h = max(height(x->left), height(x->right))+1;
    y->h = max(height(y->left), height(y->right))+1;
    return y;
}
ptr rightr(ptr y)
{
    struct node *x = y->left;
    struct node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->h = max(height(y->left), height(y->right))+1;
    x->h = max(height(x->left), height(x->right))+1;
    return x;
}
ptr insert(ptr root,int x)
{
    if(root==nullptr)
        return newnode(x);
    else if(root->value>x)
        root->left=insert(root->left,x);
    else
        root->right=insert(root->right,x);
    root->h=max(height(root->left),height(root->right))+1;
    int balance=getb(root);
    if(balance>1 && x<root->left->value)
        return rightr(root);
    else if(balance<-1 && x > root->right->value)
        return leftr(root);
    else if(balance>1 && x> root->left->value)
    {
        root->left=leftr(root->left);
        return rightr(root);
    }
    else if(balance <-1 && x< root->right->value)
    {
        root->right=rightr(root->right);
        return leftr(root);
    }
    return root;
}
int main()
{
    ptr root=nullptr;
    root=  insert(root,10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);
    in(root);
    return 0;
}



