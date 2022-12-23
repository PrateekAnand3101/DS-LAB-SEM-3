#include <iostream>
using namespace std;

class bst
{
    bst *lcl;
    bst *rcl;
    int info;
    public:
    bst(int ele=0)
    {
        lcl=rcl=NULL;
        info=ele;

    }
    void insert(int);
    void display(bst* );
    void search(int);
    bst* search2(bst*, int);
    void del(int);
    void searchKey(bst*&, int, bst*);
    void deleteNode(bst*&, int);
    bst* minKey(bst* );
};
bst *root=NULL;

void bst::insert(int ele)
{
    bst *temp=new bst(ele);
    if(root==NULL)
    {
        root=temp;
        return;
    }
    else
    {
        bst* cur=root;
        bst* prev=NULL;
        while(cur)
        {
            prev=cur;
            if(temp->info<cur->info)
            {
                cur=cur->lcl;
            }
            else if(temp->info>cur->info)
                cur=cur->rcl;
            else
                cout<<"Insertion not posssible\n";
                return;
        }
        if(temp->info>prev->info)
            prev->rcl=temp;
        else
            prev->lcl=temp;
    }
    return;
}

void bst::display(bst* ptr) //inorder
{
    if(ptr)
    {
        display(ptr->lcl);
        cout<<" "<<ptr->info;
        display(ptr->rcl);
    }
}

void bst::search(int ele)
{
    if(root==NULL)
    {
        cout<<"Tree is empty\n";
        return;
    }
    bst* cur=root;
    while(cur)
    {
        if(cur->info==ele)
        {
            cout<<"Element found\n";
            return;
        }
        else if(cur->info>ele)
        {
            cur=cur->lcl;

        }
        else    
            cur=cur->rcl;

    }
    cout<<"Element not found\n";
}

bst* bst::search2(bst* r,int key)
{
    if(!r)
    {
        return NULL;
    }
    if(key==r->info)
    {
        return r;
    }
    if(key<r->info)
    {
        return search2(r->lcl,key);
    }
    return search2(r->rcl,key);
}

bst* bst::minKey(bst* cur)
{
    while(cur->lcl!=NULL)
    {
        cur=cur->lcl;
    }
    return cur;
}

void bst::searchKey(bst*& cur,int key, bst* par)
{
    while(cur!=NULL && cur->info!=key)
    {
        par=cur;
        if(key<cur->info)
        {
            cur=cur->lcl;
        }
        else
            cur=cur->rcl;
    }
}

void bst::deleteNode(bst*& root,int key)
{
    bst* par=NULL;
    bst* cur=root;
    searchKey(cur,key,par);
    if(cur==NULL)
        return;
    if(cur->lcl==NULL && cur->rcl==NULL)
    {
        if(cur!=root)
        {
            if(par->lcl==cur)
            {
                par->lcl=NULL;
            }
            else
                par->rcl=NULL;
        }
        else
            root=NULL;
        delete(cur);
    }
    else if(cur->lcl && cur->rcl)
    {
        bst* succ=minKey(cur->rcl);
        int val=succ->info;
        deleteNode(root,succ->info);
        cur->info=val;
    }
    else
    {
        bst* child= (cur->lcl)?cur->lcl:cur->rcl;
        if(cur!=root)
        {
            if(cur==par->lcl)
            {
                par->lcl=child;
            }
            else
                par->rcl=child;
        }
        else
            root=child;
            delete(cur);
    }
}


int main(){
    bst* tree=NULL;
    
    tree->insert(10);
    tree->insert(20);
    tree->insert(30);
    tree->insert(40);
    tree->insert(50);
    tree->insert(60);
    tree->deleteNode(root,10);
    tree->deleteNode(root,30);
    tree->display(tree);
    
    return 0;
}