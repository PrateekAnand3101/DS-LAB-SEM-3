// Stack using two queues




#include <iostream>
using namespace std;
class queue
{
    int q[50], rear, front, maxsize;
public:
    queue()
    {
        maxsize=10;
        front=rear=-1;
    }
    void enq(int ele)
    {
        if(rear==(maxsize-1))
            cout<<"Queue is full";
        else
            q[++rear]=ele;
    }
    int deq()
    {
        if(front==rear)
            cout<<"Queue is empty";
        else
            return q[++front];
    }
    void display()
    {
        int i;
        if(front==rear)
            cout<<"Queue is empty";
        else
        {
            for(i=(front+1); i<=rear; i++)
                cout<<q[i]<<"\n";
        }
    }
    bool isEmpty()
    {
        if(front==rear)
        {
            return true;
        }
        return false;
    }
};
class stack
{
    queue q1, q2, temp;
    public:
    void push(int n)
    {
        q1.enq(n);
        while(!q2.isEmpty())
        {
            q1.enq(q2.deq());
        }
        temp=q1;
        q1=q2;
        q2=temp;
    }
    int pop()
    {
        return q2.deq();
    }
    void display()
    {
        q2.display();
    }
};
int main() 
{
    stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    cout<<s.pop()<<endl;
    s.display();
    return 0;
}