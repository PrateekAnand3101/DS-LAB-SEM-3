#include <iostream>
using namespace std;
class node
{
    public:
    int info;
    node *lcl;
    node *rcl;

};
class stk
{
    node *s[100];
    int top,size;
    public:
    stk(int size)
    {
        this->size=size;
        top=-1;

    }
    void push(node *x)
    {
        if(top==size-1)
            cout<<"Stack overflow\n";
        else
            s[++top]=x;
    }
    node *pop()
    {
        node *x=NULL;
        if(top==-1)
            cout<<"Stack underflow\n";
        else
            x=s[top--];
        return x;
    }
    void display()
    {
        for(int i=top;i>=0;i--)
        {
            cout<<s[i]<<endl;
        }
        cout<<endl;
    }
    bool isEmpty()
    {
        return top==-1;
    }


};

class tree
{
    node *root;
    public:
    tree()
    {
        root=NULL;

    }
    void create()
    {
        node *p,*t;
        int x;
        stk s(100);
        cout<<"Enter root value:\n";
        cin>>x;
        root=new node;
        root->info=x;
        root->lcl=NULL;
        root->rcl=NULL;
        s.push(root);

        while(!s.isEmpty())
        {
            p=s.pop();
            cout<<"Enter left child of "<<p->info<<":";
            cin>>x;
            if(x!=-1)
            {
                t=new node;
                t->info=x;
                t->lcl=t->rcl=NULL;
                p->lcl=t;
                s.push(t);
            }
            cout<<"Enter right child of "<<p->info<<":";
            cin>>x;
            if(x!=-1)
            {
                t=new node;
                t->info=x;
                t->lcl=t->rcl=NULL;
                p->rcl=t;
                s.push(t);
            }
        }

    }
    void preorderIterative()
    {
        stk s(100);
        node *p=root;
        while(p || !s.isEmpty())
        {
            if(p)
            {
                cout<<p->info<<" ";
                s.push(p);
                p=p->lcl;

            }
            else
            {
                p=s.pop();
                p=p->rcl;

            }
            
        }
        cout<<endl;

    }
    void postorderIterative()
    {
        stk s(100);
        node *p=root;
        node *last=NULL;
        while(p|| !s.isEmpty())
        {
            if(p)
            {
                s.push(p);
                p=p->lcl;
            }
            else
            {
                p=s.pop();
                if(p->rcl && p->rcl!=last)
                {
                    s.push(p);
                    p=p->rcl;
                
                }
                else
                {
                    cout<<p->info<<" ";
                    last =p;
                    p=NULL;
                }
            }
        }
        cout<<endl;

    }
    void inorderIterative()
    {
        stk s(100);
        node *p=root; 
        while(p || !s.isEmpty())
        {
            if(p)
            {
                s.push(p);
                p=p->lcl;

            }
            else
            {
                p=s.pop();
                cout<<p->info<<" ";
                p=p->rcl;

            }
        }
        cout<<endl;
    }
    void parent(int key)
    {
        stk s(100);
        node *p=root;
        while(p || !s.isEmpty())
        {
            if(p)
            {
                if(p->info==key)
                {
                    cout<<"Parent of "<<key<<" is "<<s.pop()->info<<endl;
                    return;
                }
                s.push(p);
                p=p->lcl;
            }
            else
            {
                p=s.pop();
                p=p->rcl;
            }
        }
        cout<<"Element not found\n";
    }
    int depth(node *p)
    {
        int x=0,y=0;
        if(p==NULL)
        {
            return 0;
        }
        x=depth(p->lcl);
        y=depth(p->rcl);
        if(x>y)
        {
            return x+1;

        }
        else
            return y+1;
    }
    void depth()
    {
        cout<<"Depth of the tree is "<<depth(root)<<endl;
    }
    void ancestors(int key)
    {
        stk s(100);
        node *p=root;
        while(p || !s.isEmpty())
        {
            if(p)
            {
                if(p->info==key)
                {
                    cout<<"Ancestors of "<<key<<" are: ";
                    while(!s.isEmpty())
                    {
                        cout<<s.pop()->info<<" ";
                    }
                    cout<<endl;
                    return;
                }
                s.push(p);
                p=p->lcl;
            }
            
            else
            {
                p=s.pop();
                p=p->rcl;
            }
        }
        cout<<"Element not found"<<endl;
    }
    void leafNodes()
    {
        stk s(100); 
        node *p=root;
        while(p || !s.isEmpty())
        {
            if (p)
            {
                if(p->lcl==NULL &&p->rcl==NULL)
                {
                    cout<<p->info<<" ";

                }
                s.push(p);
                p=p->lcl;
            }
            else{
                p=s.pop();
                p=p->rcl;
            }
        }
        cout<<endl;
    }
    // node* copy(node* ptr)
    // {
    //     node* temp;
    //     if(ptr)
    //     {
    //         temp=new node;
    //         if(ptr->lcl)
    //             temp->lcl=copy(ptr->lcl);
    //         if(ptr->rcl)
    //             temp->rcl=copy(ptr->rcl);
    //         temp->info=ptr->info;
    //         return temp;
    //     }
    //     return NULL;
    // }
    // int max(int a, int b)
    // {
    //     int m=(a<b)?a:b;
    //     return m;
    // }
    // int height(node *r)
    // {
    //     if(root==NULL)
    //         return 0;
    //     return (max(height(r->lcl),height(r->rcl))+1);
    // }
    // tree *equal

};
int main(){
    tree t;
    t.create();
    t.preorderIterative();
    t.inorderIterative();
    t.postorderIterative();
    t.parent(5);
    t.depth();
    t.ancestors(5);
    t.leafNodes();
    // t.height();
    // t.copy();
    return 0;
}
