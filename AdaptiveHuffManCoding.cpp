#include<bits/stdc++.h>
using namespace std;
#define blck cout<<"------------------\n";
#define nullptr NULL
#define ptr struct node *
struct node
{
    struct node * par;
    char myc;
    int wfq;
    int rnk;
    bool nyt;
    struct node * left;
    struct node * right;
};
int ispresent(char ch ,ptr tree)
{
    if(tree==nullptr)
    {
        return 0;
    }
    if(tree->myc==ch)
        return 1;
    if(tree->left)
    {
        if(ispresent(ch,tree->left))
            return 1;
    }
    if(ispresent(ch,tree->right))
            return 1;
    return 0;
}
ptr search(char ch ,ptr tree)
{
    if(tree==nullptr)
    {
        return NULL;
    }
    if(tree->myc==ch)
        return tree;
    if(tree->left!=nullptr)
    {
        if(search(ch,tree->left)!=nullptr)
            return search(ch,tree->left);
    }
    return search(ch,tree->right);
}
ptr search(ptr tree)
{
    if(tree==nullptr)
    {
        return NULL;
    }
    if(tree->nyt==true)
        return tree;
    if(tree->left)
    {
        if(search(tree->left)!=nullptr)
            return search(tree->left);
    }
    return search(tree->right);
}
int isleaf(ptr curr)
{
    if(curr->left==nullptr && curr->right==nullptr)
        return 1;
    return 0;
}
int isleft(ptr curr)
{
    if(curr->par->left->myc==curr->myc)
        return 1;
    return 0;
}
void swapp(ptr *a,ptr*b)
{
    ptr*t;
    t=a;
    a=b;
    b=t;
}
void update(ptr *curr,ptr *tree)
{
    if(isleaf(*curr))
       (*curr)=(*curr)->par;
    while((*curr)!=(*tree))
    {
        (*curr)->wfq=((*curr)->left->wfq)+((*curr)->right->wfq);
        if((*curr)->wfq>(*curr)->par->right->wfq)
        {
            if(isleft((*curr)))
            {
               ptr parent=(*curr)->par;
               int temp=(*curr)->rnk;
               (*curr)->rnk=(*curr)->par->right->rnk;
               (*curr)->par->right->rnk=temp;
               ptr te;
               ptr to;
               te=(parent->left);
               to=(parent->right);
               parent->right=te;
               parent->left=to;
            }
            else
            {
               ptr parent=(*curr)->par;
               int temp=(*curr)->rnk;
               (*curr)->rnk=(*curr)->par->left->rnk;
               (*curr)->par->left->rnk=temp;
               ptr te;
               ptr to;
               te=(parent->left);
               to=(parent->right);
               parent->right=te;
               parent->left=to;
            }
        }
        (*curr)=(*curr)->par;
    }
    (*curr)->wfq=((*curr)->left->wfq)+((*curr)->right->wfq);
}
void encode(char ch,ptr tree)
{
    ptr nytptr;
    if(ispresent(ch,tree))
    {
         nytptr=search(ch,tree);
         nytptr->wfq=nytptr->wfq+1;
    }
    else
    {
        nytptr=search(tree);
        nytptr->left=(ptr)malloc(sizeof(struct node));
        nytptr->right=(ptr)malloc(sizeof(struct node));
        nytptr->nyt=false;
        nytptr->left->nyt=true;
        nytptr->left->par=nytptr;
        nytptr->right->par=nytptr;
        nytptr->left->myc='$';
        nytptr->left->wfq=0;
        nytptr->left->rnk=(nytptr->rnk)-2;
        nytptr->left->left=nullptr;
        nytptr->left->right=nullptr;
        nytptr->right->nyt=false;
        nytptr->right->myc=ch;
        nytptr->right->wfq=1;
        nytptr->right->rnk=(nytptr->rnk)-1;
        nytptr->right->left=nullptr;
        nytptr->right->right=nullptr;
    }
    update(&nytptr,&tree);
}
void inorder(ptr tree)
{
    if(tree==nullptr)
        return ;
    inorder(tree->left);
    cout<< tree->myc<<" "<<tree->wfq<<" "<<tree->rnk<<endl;
    inorder(tree->right);
}
int main()
{
    ptr tree;
    tree=(struct node *)malloc(sizeof(struct node));
    tree->par=tree;
    tree->nyt=true;
    tree->wfq=0;
    tree->myc='$';
    tree->rnk=9;
    tree->left=nullptr;
    tree->right=nullptr;
    char s[10000];
    cin>>s;
    for(int i=0;i<strlen(s);i++)
    {
        encode(s[i],tree);

    }
    blck;
       inorder(tree);
    blck;
    return 0;
}
