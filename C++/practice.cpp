// #include<iostream>
// using namespace std;

// int main( )
// {
//     char str1[80], str2[80];
	
//     cout<<"Enter first string: ";
//     cin.getline(str1, 80);
	
//     cout<<"Enter second string: ";
//     cin.getline(str2, 80);

//     int l = 0; //Hold length of second string
    
//     //finding length of second string
//     for(l = 0; str2[l] != '\0'; l++);

//     int i, j;
    
//     for(i = 0, j = 0; str1[i] != '\0' && str2[j] != '\0'; i++)
//     {
//         if(str1[i] == str2[j])
//         {
//             j++;
//         }
//         else
//         {
//             j = 0;
//         }
//     }

//     if(j == l)
//         cout<<"Substring found at position "<< i - j + 1;
//     else
//         cout<<"Substring not found";
	
//     return 0;
// }

// #include <iostream>
// using namespace std;

// class node
// {
// public:
//     int data;
//     node *left;
//     node *right;
// };

// class stack
// {
// private:
//     node *s[100];
//     int top;
//     int size;

// public:

//     stack(int size)
//     {
//         this->size = size;
//         top = -1;
//     }

//     void push(node *x)
//     {
//         if (top == size - 1)
//             cout << "Stack Overflow" << endl;
//         else
//             s[++top] = x;
//     }

//     node *pop()
//     {
//         node *x = NULL;
//         if (top == -1)
//             cout << "Stack Underflow" << endl;
//         else
//             x = s[top--];
//         return x;
//     }

//     void display()
//     {
//         for (int i = top; i >= 0; i--)
//             cout << s[i] << " ";
//         cout << endl;
//     }

//     bool isEmpty()
//     {
//         return top == -1;
//     }
// };

// class tree
// {
// private:

//     node *root;

// public:

//     tree()
//     {
//         root = NULL;
//     }

//     void create()
//     {
//         node *p, *t;
//         int x;
//         stack stk(100);

//         cout << "Enter root value: ";
//         cin >> x;
//         root = new node;
//         root->data = x;
//         root->left = root->right = NULL;
//         stk.push(root);

//         while (!stk.isEmpty())
//         {
//             p = stk.pop();
//             cout << "Enter left child of " << p->data << ": ";
//             cin >> x;
//             if (x != -1)
//             {
//                 t = new node;
//                 t->data = x;
//                 t->left = t->right = NULL;
//                 p->left = t;
//                 stk.push(t);
//             }
//             cout << "Enter right child of " << p->data << ": ";
//             cin >> x;
//             if (x != -1)
//             {
//                 t = new node;
//                 t->data = x;
//                 t->left = t->right = NULL;
//                 p->right = t;
//                 stk.push(t);
//             }
//         }
//     }

//     void preorderIterative()
//     {
//         stack stk(100);
//         node *p = root;

//         while (p || !stk.isEmpty())
//         {
//             if (p)
//             {
//                 cout << p->data << " ";
//                 stk.push(p);
//                 p = p->left;
//             }
//             else
//             {
//                 p = stk.pop();
//                 p = p->right;
//             }
//         }
//         cout << endl;
//     }

//     void inorderIterative()
//     {
//         stack stk(100);
//         node *p = root;

//         while (p || !stk.isEmpty())
//         {
//             if (p)
//             {
//                 stk.push(p);
//                 p = p->left;
//             }
//             else
//             {
//                 p = stk.pop();
//                 cout << p->data << " ";
//                 p = p->right;
//             }
//         }
//         cout << endl;
//     }

//     void postorderIterative()
//     {
//         stack stk(100);
//         node *p = root;
//         node *last = NULL;

//         while (p || !stk.isEmpty())
//         {
//             if (p)
//             {
//                 stk.push(p);
//                 p = p->left;
//             }
//             else
//             {
//                 p = stk.pop();
//                 if (p->right && p->right != last)
//                 {
//                     stk.push(p);
//                     p = p->right;
//                 }
//                 else
//                 {
//                     cout << p->data << " ";
//                     last = p;
//                     p = NULL;
//                 }
//             }
//         }
//         cout << endl;
//     }

//     void parent(int key)
//     {
//         stack stk(100);
//         node *p = root;

//         while (p || !stk.isEmpty())
//         {
//             if (p)
//             {
//                 if (p->data == key)
//                 {
//                     cout << "Parent of " << key << " is " << stk.pop()->data << endl;
//                     return;
//                 }
//                 stk.push(p);
//                 p = p->left;
//             }
//             else
//             {
//                 p = stk.pop();
//                 p = p->right;
//             }
//         }
//         cout << "Element not found" << endl;
//     }

//     int depth(node *p)
//     {
//         int x = 0, y = 0;
//         if (p == NULL)
//             return 0;
//         x = depth(p->left);
//         y = depth(p->right);
//         if (x > y)
//             return x + 1;
//         else
//             return y + 1;
//     }

//     void depth()
//     {
//         cout << "Depth of the tree is " << depth(root) << endl;
//     }

//     void ancestors(int key)
//     {
//         stack stk(100);
//         node *p = root;

//         while (p || !stk.isEmpty())
//         {
//             if (p)
//             {
//                 if (p->data == key)
//                 {
//                     cout << "Ancestors of " << key << " are: ";
//                     while (!stk.isEmpty())
//                         cout << stk.pop()->data << " ";
//                     cout << endl;
//                     return;
//                 }
//                 stk.push(p);
//                 p = p->left;
//             }
//             else
//             {
//                 p = stk.pop();
//                 p = p->right;
//             }
//         }
//         cout << "Element not found" << endl;
//     }

//     void leafNodes()
//     {
//         stack stk(100);
//         node *p = root;

//         while (p || !stk.isEmpty())
//         {
//             if (p)
//             {
//                 if (p->left == NULL && p->right == NULL)
//                     cout << p->data << " ";
//                 stk.push(p);
//                 p = p->left;
//             }
//             else
//             {
//                 p = stk.pop();
//                 p = p->right;
//             }
//         }
//         cout << endl;
//     }

// };

// int main()
// {
//     tree t;
//     t.create();
//     t.preorderIterative();
//     t.inorderIterative();
//     t.postorderIterative();
//     t.parent(5);
//     t.depth();
//     t.ancestors(5);
//     t.leafNodes();
//     return 0;
// }

// #include <iostream>
// using namespace std;

// class node{
//     public:
//     int data;
//     node *next;
// };

// class LinkedList{
//     private:
//     node *head;
//     public:

//     LinkedList(){
//         head=NULL;
//     }

//     void append(int elem){
//         node *temp= new node;
//         temp->data=elem;
//         temp->next=head;
//         head=temp;
//     }

//     void inser()
//     {
//         cout<< "Enter the element ";
//         node *temp=new node;
//         cin>>temp->data;
//         temp->next=NULL;
//         if(head==NULL)
//         {
//             head=temp;

//         }
//         node *t=head;
//         while(t->next!=NULL)
//             t=t->next;
//         t->next=temp;

//     }

//     void insert_after(int elem, int value){
//         // elem= element to insert
//         // value= element after which insertion is to be done
//         // NO EDGE CASES EXIST.*
//         node *temp=new node;
//         temp->data=elem;
//         node *trav=head;
//         bool found=false;
//         while(trav!=NULL){
//             if(trav->data==value){
//                 temp->next=trav->next;
//                 trav->next=temp;
//                 found=true;
//                 break;
//             }
//             trav=trav->next;
//         }
//         if(!found){
//             cout<<"Element not found!"<<endl;
//         }
//     }
// /*insert_before() and remove() are implemented using look ahead technique,
// and hence edges cases are always at head because it has no element which can look ahead to head*/
//     void insert_before(int elem, int value){
//         node *temp= new node;
//         temp->data=elem;
//         node *trav=head;
//         bool found=false;
//         //EDGE CASE:Element is at head
//         if(trav->data==value){
//             head=temp;
//             temp->next=trav;
//             return;
//         }
//         while(trav->next!=NULL){
//             if(trav->next->data==value){
//                 temp->next=trav->next;
//                 trav->next=temp;
//                 found=true;
//                 break;
//             }
//             trav=trav->next;
//         }
//         if(!found){
//             cout<<"Element not found"<<endl;
//         }
//     }

//     void remove(int elem){
//         node *trav=head;
//         bool found=false;

//         // EDGE CASE:ELement at head
//         if(trav->data==elem){
//             head=trav->next;
//             return;
//         }

//         while(trav->next!=NULL){
//             if(trav->next->data==elem){
//                 trav->next=trav->next->next;
//                 found=true;
//                 break;
//             }
//             trav=trav->next;
//         }
//         // Element at Tail
//         if(trav->next==NULL){
//             delete trav->next;
//             trav->next=NULL;
//             found=true;
//         }

//         if(!found){
//             cout<<"Element not found in the list"<<endl;
//         }
//     }

//     void traverse(){
//         node *trav= new node;
//         trav=head;
//         while(trav!=NULL){
//             cout<<trav->data<<' ';
//             trav=trav->next;
//         }
//         cout<<endl;
//     }

//     void reverse(){
//         node *prev=NULL, *next=NULL, *curr=head;
//         while(curr!=NULL){
//             next=curr->next;
//             curr->next=prev;
//             prev=curr;
//             curr=next;
//         }
//         head=prev;
//     }

//     void sort(bool rev=false){
//         // By selection sort
//         node *t=head, *t2, *min;
//         int temp;
//         while(t){
//             min=t;
//             t2=t->next;
//             while(t2){
//                 if(t2->data<min->data)
//                     min=t2;
//                 t2=t2->next;
//             }
//             if(min!=t)
//                 swap(min->data,t->data);
//             t=t->next;
//         }
//     if(rev)
//         reverse();
//     }

//     void delete_alternate(){
//         node *temp=head;
//         node *temp2=temp->next;
//         while(temp && temp2){
//             temp->next=temp2->next;
//             delete temp2;
//             temp=temp->next;
//             if(temp)
//                 temp2=temp->next;
//         }

//     }

//     void insert_sort(int elem){
//         node *temp=new node;
//         node *trav=head;
//         temp->data=elem;
//         //EDGE CASE:List Empty
//         if(head==NULL){
//             append(elem);
//             return;
//         }

//         // Insertion by look ahead technique

//         // EDGE CASE:Element at head
//         if(trav->data>elem){
//             temp->next=head;
//             head=temp;
//             return;
//         }
//         while(trav->next!=NULL){
//             if(trav->next->data>elem){
//                 temp->next=trav->next;
//                 trav->next=temp;
//                 break;
//             }
//             trav=trav->next;
//         }
//         // EDGE CASE: Element at tail
//         if(trav->next==NULL){
//             trav->next=temp;
//             temp->next=NULL;
//         }
//     }
// };
// int main(){
//     LinkedList L;
//     //MENU DRIVEN PROGRAM TO IMPLEMENT THE OPERATIONS
//     int choice;
//     int loc,elem;
//     L.append(100);
//     L.append(2100);
//     L.append(10);
//     L.append(1420);
//     cout<<"THE FOLLOWING OPERATIONS CAN BE PERFORMED ON THE LINKED LIST:"<<endl;
//     cout<<"1.Insert before another element"<<endl;
//     cout<<"2.Insert after another element"<<endl;
//     cout<<"3.Delete an element"<<endl;
//     cout<<"4.Traverse the list"<<endl;
//     cout<<"5.Reverse the list"<<endl;
//     cout<<"6.Sort the list"<<endl;
//     cout<<"7.Delete alternate elements"<<endl;
//     cout<<"8.Insert in an order"<<endl;
//     cout<< "9. Insert element"<<endl;
//     cout<<"10.Exit"<<endl;
//     while(true){
//         cout<<">";
//         cin>>choice;
//         switch(choice){
//             case 1:{
//                 cout<<"Enter the element to insert before:";
//                 cin>>loc;
//                 cout<<"Enter the element to insert:";
//                 cin>>elem;
//                 L.insert_before(elem, loc);
//                 break;
//             }
//             case 2:{
//                 cout<<"Enter the element to insert after:";
//                 cin>>loc;
//                 cout<<"Enter the element to insert:";
//                 cin>>elem;
//                 L.insert_after(elem, loc);
//                 break;
//             }
//             case 3:{
//                 cout<<"Enter the element to delete:";
//                 cin>>elem;
//                 L.remove(elem);
//                 break;
//             }
//             case 4:{
//                 L.traverse();
//                 break;
//             }
//             case 5:{
//                 L.reverse();
//                 break;
//             }
//             case 6:{
//                 cout<<"0 for Ascending\n1 for Descending";
//                 cin>>elem;
//                 L.sort(elem);
//                 break;
//             }
//             case 7:{
//                 L.delete_alternate();
//                 break;
//             }
//             case 8:{
//                 cout<<"Enter the element to insert:";
//                 cin>>elem;
//                 L.insert_sort(elem);
//                 break;
//             }
//             case 9:{
//                 L.inser();
//                 break;
//             }


//             case 10:
//                 return 0;
//             default:
//                 cout<<"Invalid Choice!"<<endl;
//         }
//     }
// }

// #include <iostream>
// using namespace std;

// class Node{
//     public:
//     int data;
//     Node *next, *prev;
// };

// class Doubly{
//     private:
//     Node *head, *tail;
//     public:
//     Doubly(){
//         head=NULL;
//         tail=NULL;
//     }

//     void append(int elem){
//         Node *temp= new Node;
//         temp->data=elem;
//         temp->next=NULL;
//         if(head==NULL){
//             // list is empty
//             temp->prev=NULL;
//             head=temp;
//         }
//         else{
//             temp->prev=tail;
//             tail->next=temp;
//         }
//         tail=temp;
//     }

//     void delete_end(){
//         Node *temp= tail;
//         if(temp->prev==NULL){
//             head=tail=NULL;
//             delete temp;
//             return;
//         }
//         temp->prev->next=NULL;
//         tail=temp->prev;
//         delete temp;
//         return;
//     }

//     void insert_pos(int elem, int loc){
//         Node *temp= new Node;
//         Node *trav= new Node;
//         temp->data=elem;
//         trav=head;
//         int count=0;
//         while(trav!=NULL){
//             if(count==loc){
//                 break;
//             }
//             count++;
//             trav=trav->next;
//         }
//         if(trav==NULL){
//             append(elem);
//             return;
//         }
//         trav->prev->next=temp;
//         temp->prev=trav->prev;
//         temp->next=trav;
//         trav->prev=temp;
//     }

//     void delete_pos(int loc){
//         Node *trav;
//         trav=head;
//         if(loc==0){
//             head=trav->next;
//             delete trav;
//             return;
//         }
//         int count=0;
//         while(trav!=NULL){
//             if(count==loc){
//                 break;
//             }
//             count++;
//             trav=trav->next;
//         }
//         if(trav==NULL){
//             delete_end();
//         }
//         trav->prev->next=trav->next;
//         trav->next->prev=trav->prev;
//     }
// // Both of the functions have no edge cases until element found
//     void insert_after(int elem, int val){
//         Node *temp= new Node;
//         Node *trav= new Node;
//         temp->data=elem;
//         trav=head;
//         bool found=false;
//         while(trav!=NULL){
//             if(val==trav->data){
//                 found=true;
//                 if(trav->next!=NULL)
//                     trav->next->prev=temp;
//                 else
//                     tail=temp;
//                 temp->next=trav->next;
//                 trav->next=temp;
//                 temp->prev=trav;
//                 break;
//             }
//             trav=trav->next;
//         }
//         if(!found){
//             cout<<"Element not found"<<endl;
//         }
//     }

//     void insert_before(int elem, int val){
//         Node *temp= new Node;
//         Node *trav= new Node;
//         temp->data=elem;
//         trav=tail;
//         bool found=false;
//         while(trav!=NULL){
//             if(val==trav->data){
//                 found=true;
//                 if(trav->prev!=NULL)
//                     trav->prev->next=temp;
//                 else
//                     head=temp;
//                 temp->prev=trav->prev;
//                 trav->prev=temp;
//                 temp->next=trav;
//                 break;
//             }
//             trav=trav->prev;
//         }
//         if(!found){
//             cout<<"Element not found"<<endl;
//         }
//     }

//     void display(){
//         Node *trav= new Node;
//         trav= head;
//         while(trav!=NULL){
//             cout<<trav->data<<' ';
//             trav=trav->next;
//         }
//         cout<<endl;
//     }

//     void reverse(){
//         Node *trav=head;
//         while(trav!=NULL){
//             swap(trav->next,trav->prev);
//             trav=trav->prev;
//         }
//         swap(head,tail);
//     }
// };

// int main(){
//     Doubly D;
//                         //MENU DRIVEN PROGRAM TO IMPLEMENT THE OPERATIONS
//     int choice;
//     int loc,elem;
//     D.append(100);
//     D.append(2100);
//     D.append(10);
//     D.append(1420);
//     cout<<"THE FOLLOWING OPERATIONS CAN BE PERFORMED ON THE DOUBLY LINKED LIST:"<<endl;
//     cout<<"1.Insert at end"<<endl;
//     cout<<"2.Delete from end"<<endl;
//     cout<<"3.Insert at Position"<<endl;
//     cout<<"4.Delete from Position"<<endl;
//     cout<<"5.Insert after another element"<<endl;
//     cout<<"6.Insert before another element"<<endl;
//     cout<<"7.Traverse the list"<<endl;
//     cout<<"8.Reverse the list"<<endl;
//     cout<<"9.Exit"<<endl;

//     while(true){
//         cout<<">";
//         cin>>choice;
//         int k;
//         switch(choice){
//             case 1:
//                 cout<<"Enter the element to insert:";
//                 cin>>elem;
//                 D.append(elem);
//                 break;
//             case 2:
//                 D.delete_end();
//                 break;
//             case 3:
//                 cout<<"Enter the location:";
//                 cin>>loc;
//                 cout<<"Enter the element to insert:";
//                 cin>>elem;
//                 D.insert_pos(elem, loc);
//                 break;
//             case 4:
//                 cout<<"Enter the location:";
//                 cin>>loc;
//                 D.delete_pos(loc);
//                 break;
//             case 5:
//                 cout<<"Enter the element to insert after:";
//                 cin>>loc;
//                 cout<<"Enter the element to insert:";
//                 cin>>elem;
//                 D.insert_after(elem, loc);
//                 break;
//             case 6:
//                 cout<<"Enter the element to insert before:";
//                 cin>>loc;
//                 cout<<"Enter the element to insert:";
//                 cin>>elem;
//                 D.insert_before(elem, loc);
//                 break;
//             case 7:
//                 D.display();
//                 break;
//             case 8:
//                 D.reverse();
//                 break;
//             case 9:
//                 return 0;

//             default:
//                 cout<<"Invalid Choice!"<<endl;
//         }
//     }
// }

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next, *prev;
};

class Doubly{
    public:
    Node *head, *tail;
    Doubly(){
        head=NULL;
        tail=NULL;
    }

    void append(int elem){
        Node *temp= new Node;
        temp->data=elem;
        temp->next=NULL;
        if(head==NULL){
            // list is empty
            head=temp;
            temp->prev=NULL;
        }
        else{
            temp->prev=tail;
            temp->prev->next=temp;
        }
        tail=temp;
    }

    void display(){
        Node *trav= new Node;
        trav= head;
    while(trav!=NULL){
        cout<<trav->data<<' ';
        trav=trav->next;
    }
        cout<<endl;
    }

    void concatenate(Doubly d2){
        tail->next=d2.head;
        d2.head->prev=tail;
    }
};

int main(){
    Doubly d1, d2;
    cout<<"Enter list 1(-1 to break):"<<endl;
    int c;
    while (true){
        cin>>c;
        if(c==-1){
            break;
        }
            d1.append(c);
    }
    cout<<"Enter list 2(-1 to break):"<<endl;
    while (true){
        cin>>c;
        if(c==-1){
            break;
        }
            d2.append(c);
    }
    d1.display();
    d2.display();
    d1.concatenate(d2);
    d1.display();
}
