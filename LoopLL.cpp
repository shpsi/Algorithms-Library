#include<bits/stdc++.h>
using namespace std;
struct node
{
    int val;
    struct node *next;
};
struct node * insert(struct node * head,int x)
{
    struct node * t;
    t=(struct node *)malloc(sizeof(struct node));
    t->val=x;
    struct node * m=head;
    t->next=m;
    head=t;
    return head;
};
int main()
{
    struct node * head;
    head=(struct node *)malloc(sizeof(struct node));
    head->val=5;
    head->next=NULL;
    head=insert(head,4);
    head=insert(head,3);
    head=insert(head,2);
    head=insert(head,1);
    head=insert(head,0);
    struct node *te,*pa;
    te=head;
    while(te!=NULL)
    {
      //  cout<<te->val<<" ";
        pa=te;
        te=te->next;
    }
    te=head;
    for(int i=0;i<2;i++)
        te=te->next;
    pa->next=te;
    struct node *f,*s;
    f=head->next->next;
    s=head->next;
    while(f!=s)
    {
        f=f->next;
        f=f->next;
        s=s->next;
       // cout<<s->val<<" ";
    }
    s=head;
    while(f!=s)
    {
        f=f->next;
        s=s->next;
    }
    cout<<"start of loop="<<f->val<<endl;
    return 0;
}
