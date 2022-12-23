#include <iostream>
#include<string.h>
using namespace std;
class node
{
    public:
    int info;
    node *rcl;
    node *lcl;
    node* createbt(node *root)
    {
        node *temp,*prev,*cur;
        char d[10];
        int i,item;
        temp=new node;
        cout<<"\n Element\n";
        cin>>temp->info;
        temp->lcl=NULL;
        temp->rcl=NULL;
        if(root==NULL)
            return temp;
        cout<<"\nDirection\n";
        cin>>d;
        prev=NULL;
        cur=root;
        for(int i=0;i<strlen(d);i++)
        {
            if(cur==NULL)
                break;
            prev=cur;
            if(d[i]=='L')
                cur=cur->lcl;
            else
                cur=cur->rcl;    
        }
        if(cur!=NULL || i!=strlen(d))
        {
            cout<<"Impossible\n";
            delete temp;
            return root;
        }
        if(d[i-1]=='L')
            prev->lcl=temp;
        else    
            prev->rcl=temp;
            return root;
    }
    void display(node *root,int level)
    {
        int i;
        if(root==NULL)
            return;
        display(root->rcl,level+1);
        for(i=0;i<level;i++)
        {
            cout<<"\t";
        }
        cout<<root->info<<endl;
        display(root->lcl,level+1);
    }
    void inorder(node *root)
    {
        if(root==NULL)
            return;
        inorder(root->lcl);
        cout<<root->info;
        inorder(root->rcl);
    }
    void preorder(node *root)
    {
        if(root==NULL)
            return;
        cout<<root->info;
        preorder(root->lcl);
        preorder(root->rcl);
    }
    void postorder(node *root)
    {
        if(root==NULL)
            return;
        preorder(root->lcl);
        preorder(root->rcl);
        cout<<root->info;
    }
};

int main(){
    
    // node* tree = createbt(root);
    // root->lcl = CreateNode(11);
    // root->lcl->lcl = CreateNode(7);
    // root->rcl = CreateNode(9);
    // root->rcl->lcl = CreateNode(15);
    // root->rcl->rcl = CreateNode(8);
 
    // cout << "Inorder traversal before insertion: ";
    // inorder(root);
    // cout << endl;
    // return 0;
// }
