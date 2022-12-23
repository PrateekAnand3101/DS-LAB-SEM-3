#include <iostream>
#include<stdio.h>
using namespace std;
class SLL
{
    int info;
    SLL* next;
    SLL* t;
    public:
    SLL *ins_end(SLL *start)
    {
        SLL *temp=new SLL;
        cout<<"Enter the value:\n";
        cin>>temp->info;
        temp->next=NULL;
        if(start==NULL)
        {
            start=temp;
            return start;
        }
        else
        SLL* t=start;
        while(t->next!=NULL)
        {
            t=t->next;
            t->next=temp;
            return start;
        }

    }
    SLL *ins_beg(SLL *start)
    {
        SLL *temp=new SLL;
        cout<<"Enter the value:\n";
        cin>>temp->info;
        temp->next=NULL;
        if(start==NULL)
        {
            start=temp;
            return start;
        }
        else{
            temp->next=start;
            start=temp;

        }
        return start;
    }
    void display(SLL *start)
    {
        SLL *h=start;
        if(h==NULL)
        {
            cout<<"List is empty\n";
        }
        while(h!=NULL)
        {
            cout<<"->"<<h->info;
            h=h->next;
        }
        cout<<endl;
    }
    SLL *ins_pos(SLL *start)
    {
        int pos;
        SLL *temp=new SLL;
        SLL *t,*t1;
        cout<<"Enter the value:\n";
        cin>>temp->info;
        temp->next=NULL;
        cout<<"Enter position:\n";
        cin>>pos;
        if(start==NULL)
        {
            start=temp;
            return start;
        }
        else
        {
            t=start;
            for(int i=1;i<pos-1;i++)
            {
                t=t->next;
                t1=t->next;
                t->next=temp;
                temp->next=t1;
            }
            
        }
        return start;
    }
    SLL *del_beg(SLL *start)
    {
        SLL *temp;
        temp=start;
        start=start->next;
        cout<<"Deleted element is:\n"<<temp->info;
        delete(temp);
        return start;
    }
    SLL *del_item(SLL*start)
    {
        SLL *cur,*prev;
        int data;
        if(start==NULL)
        {
            cout<<"No item to delete\n";
        }
        else{
            cout<<"Enter data to be deleted;\n";
            cin>>data;
            cur=start;
            while((cur!=NULL)&&(cur->info!=data))
            {
                prev=cur;
                cur=cur->next;
            }
            if(cur==start)
            {
                start=start->next;
                cout<<"Data deleted:\n"<<data<<endl;
            }
            if(cur==NULL)
            {
                cout<<"Record not found\n"<<endl;
                return start;
            }
            else{
                prev->next=cur->next;
                cout<<"Data deleted is:\n"<<data<<endl;
            }
            delete(cur);

        }
        return start;
    }
    SLL *ins_after(SLL *start)
    {
        int eleaf;
        int ele;
        int flag=0;
        cout<<"insert after: ";
        cin>>eleaf;
        cout<<"element to be inserted: ";
        cin>>ele;
        SLL *temp=new SLL;
        temp->info=ele;
        temp->next=NULL;
        SLL *t=start;
         while(t!=NULL){
            
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
    SLL* ins_Before(SLL *start){
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
    // void reverse(SLL *start){
    //     SLL *prev=NULL, *next=NULL, *cur=start;
    //     while(cur!=NULL){
    //         next=cur->next;
    //         cur->next=prev;
    //         prev=cur;
    //         cur=next;
            
    //     }
    //     start=prev;
        
    // } 
    // void sort(SLL *start){
    //     // By selection sort
    //     bool rev=false;
    //     SLL *t=start, *t2, *min;
    //     int temp;
    //     while(t){
    //         min=t;
    //         t2=t->next;
    //         while(t2){
    //             if(t2->info < min->info)
    //                 min=t2;
    //             t2=t2->next;
    //         }
    //         if(min!=t)
    //             swap(min->info,t->info);
    //         t=t->next;
    //     }
    // if(rev)
    //     reverse(start);
    // }

    // void delete_alternate(SLL *start){
    //     SLL *temp=start;
    //     SLL *temp2=temp->next;
    //     while(temp && temp2){
    //         temp->next=temp2->next;
    //         delete(temp2);
    //         temp=temp->next;
    //         if(temp)
    //             temp2=temp->next;
    //     }
        
    // }

    // void insert_sort( SLL *start){
    //     int ele;
    //     cin>>ele;
    //     SLL *temp=new SLL;
    //     SLL *t=start;
    //     temp->info=ele;
    //     //EDGE CASE:List Empty
    //     if(start==NULL){
    //         SLL *temp= new SLL;
    //         temp->info=ele;
    //         temp->next=start;
    //         start=temp;
    //         return;
    //     }

        
    //     if(t->info > ele){
    //         temp->next=start;
    //         start=temp;
    //         return;
    //     }
    //     while(t->next!=NULL){
    //         if(t->next->info>ele){
    //             temp->next=t->next;
    //             t->next=temp;
    //             break;
    //         }
    //         t=t->next;
    //     }
    //     // EDGE CASE: Element at tail
    //     if(t->next==NULL){
    //         t->next=temp;
    //         temp->next=NULL;
    //     }
    // }

};

int main(){
    SLL* start = NULL;
    int s;
    while(true){
        cout<<"Inputs possible:\n";
        cout<<"Enter 0 for ending program\n";
        cout<<"1 for insert at end\n";
        cout<<"2 for display\n";
        cout<<"3 for insert at beginning\n";
        cout<<"4 for insert at position\n";
        cout<<"5 for delete at beginning\n";
        cout<<"6 for delete an item\n";
        cout<<"7 for insert after an element\n";
        cout<<"8 for insert before an element\n";
        // cout<<"8 for reverse the list\n";
        
        // cout<<"9.Sort the list"<<endl;
        // cout<<"10.Delete alternate elements"<<endl;
        // cout<<"11.Insert in an order"<<endl;
        
        cin>>s;
        switch(s)
        {
            case (1):
                start = start->ins_end(start);

                break;

            case (2):
                start->display(start);
                break;
            case (3):
                start = start->ins_beg(start);
                break;
            case (4):
                start = start->ins_pos(start);
                break;
            case (5):
                start = start->del_beg(start);
                break;
            case (6):
                start = start->del_item(start);
                break;
            case (7):
                start= start->ins_after(start);
                break;
            case (8):
                start= start->ins_Before(start);
                break;
            // case (7):
            //     start->reverse(start);
            //     break;
            
            // case (9):
            //     start->sort(start);
            //     break;
            // case (10):
            //     start->delete_alternate(start);
            //     break;
            // case (11):
            //     start->insert_sort(start);
            //     break;
            case (0):
                return 0;
            default:
                cout<<"Invalid choice\n";
                break;
        }
    }
    
    
    return 0;
}