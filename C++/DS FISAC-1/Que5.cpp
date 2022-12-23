// #include <iostream>
// using namespace std;
// const int MAX=100;

// class que
// {
//     int front,rear,a[MAX];
//     public:
//     que()
//     {
//         front=rear=0;
        
//     }
//     bool isFull()
//     {
//         if((rear+1)%MAX==front)
//             return true;
//         return false;
//     }
//     bool isEmpty()
//     {
//         if(rear==front)
//             return true;
//         return false;
//     }
//     void enq(int x)
//     {
//         if(isFull())
//             cout<<"Queue is Full\n";
//         else
//             rear=(rear+1)%MAX;
//             a[rear]=x;
//     }
//     int deq()
//     {
//         if(isEmpty())
//         {
//             cout<<"Empty queue \n";
//             return 0;
//         }
//         else
//             front=(front+1)%MAX;
//             return a[front];
//     }
//     void display()
//     {
//         if(isEmpty())
//         {
//             cout<<"Queue empty\n";
//         }
//         else
//             for(int i=(front+1)%MAX;i!=(rear+1)%MAX;i=(i+1)%MAX)
//             {
//                 cout<<a[i]<<endl;
//             }
//     }
// };

// class stk
// {
//     que q1,q2;
//     public:
//     void push(int x)
//     {
//         q1.enq(x);
//     }
//     int pop()
//     {
//         int a,b;
//         while(!q1.isEmpty())
//         {
//             a=q1.deq();
//             q2.enq(a);
//         }
//         b=q2.deq();

//         while(!q2.isEmpty())
//         {
//             a=q2.deq();
//             q1.enq(a);
//         }

//         return b;
//     }
// };
// int main(){
//     stk s;
//     s.push(10);
//     s.push(20);
//     s.push(30);
//     s.push(40);
//     cout<<"Removing element from stack:\n";
//     cout<<s.pop()<<endl;
//     cout<<s.pop()<<endl;
//     cout<<s.pop()<<endl;
//     cout<<s.pop()<<endl;

//     return 0;
// }

#include <iostream>
using namespace std;
const int n=100;

class que{
    private:
    int arr[n];
    int fornt,rear;
    public:
    que(){
        front=rear=0;}

    bool isEmpty(){
        return (top==-1);}

    bool isFull(){
        return (top+1==n);}

    void push(int elem){
        if(!isFull()){
            arr[++top]=elem;}
        }

    int pop(){
        if(!isEmpty()){
            return arr[top--];
        }
    }

    int peek(){
        if(!isEmpty()){
            return arr[top];
        }
    }

    void display(){
        for(int i=top;i>=0;i--){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

class Queue{
    private:
    Stack s1,s2;
    public:
    void enqueue(int elem){
        if(s1.isEmpty()){
            s1.push(elem);
        }
        else{
            while(!s1.isEmpty()){
                s2.push(s1.pop());
            }
            s1.push(elem);
            while(!s2.isEmpty()){
                s1.push(s2.pop());
            }
        }
    }
    int dequeue(){
        return s1.pop();
    }

    void display(){
        s1.display();
    }
};

int main(){
    Queue q;
    q.enqueue(100);
    q.enqueue(200);
    q.enqueue(300);
    q.display();
    q.dequeue();
    q.display();
}