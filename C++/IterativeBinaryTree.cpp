#include <iostream>
#include<string.h>
using namespace std;
class treenode
{
    int info;
    treenode *lcl, *rcl;
    public:
    treenode(int ele=0)
    {
        info=ele;
        lcl=NULL;
        rcl=NULL;
    }
    treenode *createbt();
    treenode *insert(int, treenode*);
    void iterPreorder(treenode*);
    void iterInorder(treenode*);
    void iterPostorder(treenode*);
    void Levelorder(treenode* ptr);
    treenode* copy(treenode *ptr);
    int ancestors(treenode *root, int target);
    treenode *parent(treenode*, int ele);
    int depth(treenode *ptr);

};
treenode *ptr=NULL;
treenode *treenode::createbt()
{
    treenode *p=new treenode;
    int x;
    cout<<"Enter data(-1 for no data):\n";
    cin>>x;

    if(x==-1)
    {
        return NULL;
    }
    p->info=x;
    cout<<"Enter left child of "<<x<<":";
    p->lcl=createbt();
    cout<<"Enter right child of "<<x<<":";
    p->rcl=createbt();
    return p;
}

treenode* treenode::insert(int item, treenode* root)
{
    treenode *temp=new treenode(item);
    if(root==NULL)
    {
        root=temp;
        return root;
    }
    char d[20];
    cout<<"Enter direction in Uppercase:\n";
    cin>>d;
    treenode *cur;
    treenode *prev;
    prev=NULL;
    cur=root;
    int i;
    for(i=0;i<strlen(d) && cur!=NULL;i++)
    {
        prev=cur;
        if(d[i]=='L')
            cur=cur->lcl;
        else
            cur=cur->rcl;
    }
    if(cur!=NULL || i!=strlen(d))
    {
        cout<<"Insertion not possible";
        delete temp;
        return root;
    }
    if(d[i-1]=='L')
        prev->lcl=temp;
    else
        prev->rcl=temp;
    return root;
}

void treenode::iterPreorder(treenode *root)
{
    if(root==NULL)
        return;
    treenode *cur=root;
    
}
int main(){
    
    return 0;
}