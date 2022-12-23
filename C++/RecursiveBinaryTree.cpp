#include <iostream>
using namespace std;

class treenode
{
    int info;
    treenode *lcl, *rcl;
    public:
    treenode *createbt();
    void inorder(treenode *);
    void preorder(treenode *);
    void postorder(treenode *);
    treenode *copy(treenode *);
    int equal(treenode*, treenode*);
    int height(treenode*);
};
treenode *root=NULL;

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

void treenode::inorder(treenode *ptr)
{
    if(ptr)
    {
        inorder(ptr->lcl);
        cout<<ptr->info<<" ";
        inorder(ptr->rcl);
    }
}

void treenode::preorder(treenode *ptr)
{
    if(ptr)
    {
        cout<<ptr->info<<" ";
        preorder(ptr->lcl);
        preorder(ptr->rcl);
    }
}
void treenode::postorder(treenode *ptr)
{
    if(ptr)
    {
        postorder(ptr->lcl);
        postorder(ptr->rcl);
        cout<<ptr->info<<" ";
    }
}

treenode* treenode::copy(treenode* ptr)
{
    treenode* temp;
    if(ptr)
    {
        temp=new treenode;
        if(ptr->lcl)
            temp->lcl=copy(ptr->lcl);
        if(ptr->rcl)
            temp->rcl=copy(ptr->rcl);
        temp->info=ptr->info;
        return temp;
    }
    return NULL;
}

int treenode::height(treenode *r)
{
    int h;
    if(root==NULL)
        return 0;
    h=max(height(r->lcl),height(r->rcl))+1;
    return h;
}

int treenode::equal(treenode *first, treenode *second)
{
    return
    (
        (!first && !second) ||((first && second &&first->info==second->info) && equal(first->lcl,second->lcl) && equal(first->rcl,second->rcl))
    );
        
    
}
int main(){
    treenode *tree=NULL;
    treenode *t1=NULL;
    tree=tree->createbt();
    tree->inorder(tree);
    cout<<endl;
    tree->preorder(tree);
    cout<<endl;
    tree->postorder(tree);
    cout<<endl;
    cout<<tree->height(tree);
    cout<<endl;
    t1=tree->copy(tree);
    cout<<t1;
    cout<<endl;
    return 0;
}