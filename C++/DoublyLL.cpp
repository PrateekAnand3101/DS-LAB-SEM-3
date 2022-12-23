#include <iostream>
using namespace std;
class dll
{
    int info;
    dll *next;
    dll *prev;
    dll *t;
    public:
    dll*ins_end(dll *start)
    {
        dll *temp=new dll;
        cin>>temp->info;
        temp->next=NULL;
        temp->prev=NULL;
        if(start==NULL){
            start=temp;
            return start;
        }
        else{
            t=start;
            while(t->next!=NULL)
            {
                t=t->next;
                t->next=temp;
                temp->prev=t;

            }
            return start;
        }


    }
    dll *ins_beg(dll* start)
    {
        dll *temp=new dll;
        cin>>temp->info;
        temp->next=NULL;
        temp->prev=NULL;
        if(start==NULL){
            start=temp;
        }
        else
        {
            temp->next=start;
            start->prev=temp;
            start=temp;

        }
        return start;
    }
};


int main(){
    dll *start=NULL;
    int s;
    while(true)
    {
        cout<<"Inputs possible:\n";
        cout<<"Enter 0 for ending program\n";
        cout<<"1 for Insert in beginning \n";
        cout<<"2 for Inserting in end\n";
        cin>>s;
        switch(s)
        {
            case 0: return 0;
                    break;
            case 1: start= start->ins_beg(start);
                    break;
            case 2: start= start->ins_end(start);
                    break;
            default:
                    cout<<"Invalid choice\n";
                    break;
        }
    }
    
    return 0;
}