#include <iostream>
using namespace std;

class SLL{
    int info;
    SLL* next;
public:
    SLL* insertEnd(SLL* start){
        SLL* temp = new SLL;
        int ele;
        cin>>ele;
        temp->info=ele;

        temp->next=NULL;

        if (start==NULL){
            start=temp;
        }
        else{
            SLL* h=start;
            //cout<<"ho";
            while(h->next!=NULL){
                //cout<<h->info;
                h=h->next;
            }
            h->next=temp;
            return start;
        }
    }

    SLL* insertStart(SLL *start){
        SLL* temp = new SLL;
        cin>>temp->info;
        temp->next=NULL;
        if (start==NULL){
            start=temp;
        }
        temp->next = start;
        start = temp;
        return start;

    }
    void display(SLL* start){
        SLL* h=start;
        if (h==NULL){
             cout<<"empty head";
             return;
        }
        else{
            while (h->next!=NULL){
                cout<<h->info<<'\t';
                h=h->next;
            }
            cout<<h->info;
            cout<<endl;
        }
    }

    SLL* insertBefore(SLL *start){
        int elebe, ele, flag=0;

        cout<<"insert before: ";
        cin>>elebe;
        cout<<"element to be inserted: ";
        cin>>ele;
        SLL* temp = new SLL;
        temp->info=ele;
        temp->next=NULL;
        SLL* t = start;
        if (t->info==elebe){
            temp->next = start;
            start = temp;
            return start;
        }
        while(t->next!=NULL){
            //cout<<"hi";
            if (t->next->info==elebe){
                flag=1;
                break;
            }
            t=t->next;
        }
        if (flag == 1){
            temp->next = t->next;
            t->next=temp;
        }
        else{
            cout<<"element not found";
        }
        return start;

    }
    SLL* insertAfter(SLL *start){
        int eleaf, ele, flag=0;

        cout<<"insert after: ";
        cin>>eleaf;
        cout<<"element to be inserted: ";
        cin>>ele;
        SLL* temp = new SLL;
        temp->info=ele;
        temp->next=NULL;
        SLL* t = start;
        while(t!=NULL){
            //cout<<"hi";
            if (t->info==eleaf){
                flag=1;
                break;
            }
            t=t->next;
        }
        if (flag == 1){
            temp->next = t->next;
            t->next=temp;
        }
        else{
            cout<<"element not found";
        }
        return start;

    }
    SLL* deleteNode(SLL *start){
        int eleaf, ele, flag=0;
        cout<<"to be deleted: ";
        cin>>ele;
        SLL* t=start;
        if (t->info==ele){
            SLL* temp = t;
            start = t->next;
            delete(temp);
            return(start);
        }
        while(t->next!=NULL && flag==0){
            //cout<<"hi";
            if (t->next->info==ele){
                flag=1;
                break;
            }
            t=t->next;
        }

        if (flag == 1){
            SLL* temp = t->next;
            t->next = t->next->next;
            delete(temp);
        }
        else{
            cout<<"element not found";
        }
        return start;

    }
    SLL* revList(SLL* head){
        SLL* next = NULL;
        SLL* prev = NULL;
        SLL* curr = head;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev = curr;
            

        }
        

        
    }
};

int main(){
    SLL* head = NULL;
    cout<<"Inputs possible:\n";
    cout<<"Enter 0 for ending program\n";
    cout<<"1 for insert at end\n";
    cout<<"2 for display\n";
    cout<<"3 for insert start\n";
    cout<<"4 for insert before\n";
    cout<<"5 for insert after\n";
    cout<<"6 for delete\n";

    int s;
    cin>>s;
    while(1){
        switch(s){
        case (1):
            head = head->insertEnd(head);

            break;

        case (2):
            head->display(head);
            break;
        case (3):
            head = head->insertStart(head);
            break;
        case (4):
            head = head->insertBefore(head);
            break;
        case (5):
            head = head->insertAfter(head);
            break;
        case (6):
            head = head->deleteNode(head);
            break;
        case (0):
            return 0;
        }
        cin>>s;
    }
}