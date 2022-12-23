#include <iostream>
using namespace std;
class cnode
{
    int info;
    cnode* next;
    public:
    cnode* insert(cnode *);
    cnode* insfrnt(cnode *);
    cnode* insfrl(cnode *);
    cnode* inslas(cnode *);
    cnode* rem_dup(cnode *);
    cnode* delle(cnode *);
    cnode* dellb(cnode *);
    cnode* delfe(cnode *);
    void print(cnode *);
    void printl(cnode *);
    //Insert in beginning using last pointer
    cnode* insfrl(cnode *last)
    {
        cnode *temp=new cnode;
        cout<<"Enter the element";
        cin>>temp->info;
        if(last==NULL)
        {
            last=temp;
            return last;
        }
        else
        {
            temp->next=last->next;
            last->next=temp;

        }
        return last;
    }
    //Inserting in end using last pointer
    cnode* inslas(cnode *last)
    {
        cnode *temp=new cnode;
        cout<<"Enter the element";
        cin>>temp->info;
        if(last==NULL)
        {
            last=temp;
            temp->next=last;
        }
        else
        {
            temp->next=last->next;
            last->next=temp;
            last=temp;
        }
        return last;
    }
    //Inserting in end using first pointer
    cnode* insert(cnode *head)
    {
        cnode *temp= new cnode;
        cnode *cur;
        cout<<"Enter the value to be inserted:\n";
        cin>>temp->info;
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
            temp->next=head;
        }
        else
        {
            cur=head;
            while(cur->next!=head)
            {
                cur=cur->next;

            }
            cur->next=temp;
            temp->next=head;
        }
        return head;

    }
    //Insert in beginning using first pointer
    cnode* insfrnt(cnode *head)
    {
        cnode *temp= new cnode;
        cnode *cur=head;
        cout<<"Enter value to be inserted:\n";
        cin>>temp->info;
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
            temp->next=head;
        }
        else
        {
            temp->next=head;
            while(cur->next!=head)
            {
                cur=cur->next;
            }
            cur->next=temp;
            head=temp;
        }
        return head;
    }
    //Print using first pointer
    void print(cnode *head)
    {
        cnode *h=head;
        cout<<h->info<<"->";
        h=h->next;
        while(h!=head)
        {
            cout<<h->info<<"->";
            h=h->next;
        }
    }
    //Print using last pointer
    void printl(cnode *last)
    {
        cnode* h=last->next;
        while(h!=last)
        {
            cout<<h->info<<"->";
            h=h->next;

        }
        cout<<h->info;
    }
    //Deleting an element from end using first pointer
    cnode* delfe(cnode *head)
    {
        cnode *cur;
        if(head==NULL)
        {
            cout<<"No records to delete\n";
            return NULL;
        }
        if(head->next==head)
        {
            cout<<"Deleted element"<<head->info;
            delete head;
            return NULL;
        }
        cur=head;
        while((cur->next)->next!=head)
        {
            cur=cur->next;
        }
        cnode *t=cur->next;
        cur->next=head;
        cout<<"Item deleted: "<<t->info;
        delete t;
        return head;

    }
    //Delete an element from end using a last pointer
    cnode* delle(cnode *last)
    {
        if(last==NULL)
        {
            cout<<"No element to delete ";
            return NULL;
        }
        if(last->next==last)
        {
            cout<<"Deleted element is: "<<last->info;
            delete last;
            return NULL;
        }
        cnode *cur=last->next;
        while(cur->next!=last)
        {
            cur=cur->next;
        }
        cur->next=last->next;
        cout<<"Item deleted is: "<<last->info;
        delete last;
        last=cur;
        return last;
    }
    //Delete an element from beginning using last pointer
    cnode* dellb(cnode *last)
    {
        cnode *cur;
        if(last==NULL)
        {
            cout<<"No nodes to delete";
            return NULL;
        }
        if(last->next==last)
        {
            cout<<"Element deleted is "<<last->info;
            delete(last->next);
            return NULL;
        }
        cur=last->next;
        last->next=cur->next;
        cout<<"Item deleted "<<cur->info;
        delete cur;
        return last;

    }
};
int main(){
    cnode* start = NULL;
    
    int s;
    while(true)
    {
        cout<<"Inputs possible:\n";
        cout<<"Enter 0 for ending program\n";
        cout<<"1 for Insert in beginning using last pointer\n";
        cout<<"2 for Inserting in end using last pointer\n";
        cout<<"3 for Inserting in end using first pointer\n";
        cout<<"4 for Insert in beginning using first pointer\n";
        cout<<"5 for Print using first pointer\n";
        cout<<"6 for Print using last pointer\n";
        cout<<"7 for Deleting an element from end using first pointer\n";
        cout<<"8 for Delete an element from end using a last pointer\n";
        cout<<"9 for Delete an element from beginning using last pointer\n";
        cin>>s;
        switch(s)
        {
            case (1):
                last = last->insfrl(last);
                break;
            case (2):
                last = last->inslas(last);
                break;
            case (3):
                head = head->insert(head);
                break;
            case (4):
                head = head->insfrnt(head);
                break;
            case (5):
                head->print(head);
                break;
            case (6):
                last->printl(last);
                break;
            case (7):
                head= head->delfe(head);
                break;
            case (8):
                last= last->delle(last);
                break;
            case (9):
                last= last->dellb(last);
                break;
            case (0):
                return 0;
            default:
                cout<<"Invalid choice\n";
                break;
        }
    }
    return 0;
}