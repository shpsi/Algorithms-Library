#include<bits/stdc++.h>
using namespace std;
struct node
{
    char ch;
    int count;
    bool isend;
    map<char,struct node*>mp;
};
class trie
{
protected:
    node head;
    vector<node*> children;
public:
    trie();
    ~trie();
    void build_trie(string words[],int length);
    void ins(string word);
    void search(string word,bool &result);
    void print();
    void print_trie(map<char,node*>tree);
};
trie::trie()
{
    head.ch=-1;
}
trie::~trie()
{
    for(int i=0;i<children.size();i++)
        delete children[i];
}
void trie::build_trie(string words[],int length)
{
    for(int i=0;i<length;i++)
        ins(words[i]);
}
void trie::ins(string s)
{
    map<char, node*> *current_tree = &head.mp;
    map<char,node*>::iterator it;
    for(int i=0;i<s.length();i++)
    {
        char ch=s[i];
        if( (it=current_tree->find(ch) )!= current_tree->end() )
        {
            current_tree=&it->second->mp;
        }
        if(it==current_tree->end())
        {
            node * temp= new node();
            temp->ch=ch;
            (*current_tree)[ch]=temp;
            current_tree=&temp->mp;
            children.push_back(temp);
        }
    }
}
void trie::search(string s,bool &result)
{
    map<char, node*> *current_tree = &head.mp;
    map<char,node*>::iterator it;
    for(int i=0;i<s.length();i++)
    {
        char ch=s[i];
        if( (it=current_tree->find(ch) )== current_tree->end() )
        {
            result=false;
            return ;
        }
        else
            current_tree=&it->second->mp;
    }
    result=true;
    return ;
}
void trie::print_trie(map<char,node*> curr)
{
    if(curr.empty())
        return ;
    map<char,node*>::iterator it;
    for(it=curr.begin();it!=curr.end();it++)
    {
        cout<<it->first<<endl;
        print_trie(it->second->mp);
    }
}
void trie::print()
{
    map<char,node*> curr=head.mp;
    print_trie(curr);
}
void trie::del(trienode current,string word,int index)
{
    if(index==word.length())
    {
        if()
    }
}
void trie::triedel(string word)
{
    del(head,word,0);
}
int main()
{
  string words[] = {"foo", "bar", "baz", "barz"};
  trie trie;
  trie.build_trie(words, 4);
  cout << "All nodes..." << endl;
  trie.print();
  cout << "Searching..." << endl;
  bool in_trie = false;
  trie.search("foo", in_trie);
  cout << "foo " << in_trie << endl;
  trie.search("fooz", in_trie);
  cout << "fooz " << in_trie << endl;
  trie.search("bar", in_trie);
  cout << "bar " << in_trie << endl;
  trie.search("baz", in_trie);
  cout << "baz " << in_trie << endl;
  trie.search("barz", in_trie);
  cout << "barz " << in_trie << endl;;
  trie.search("bbb", in_trie);
  cout << "bbb " << in_trie << endl;;
  return 0;
}
