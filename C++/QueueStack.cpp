// Queues using two stacks
#include <iostream>
using namespace std;
const int MAX=100;
class stk
{
    int a[MAX],top;
    public:
    stk()
    {
        top=-1;
    }
    bool isEmpty()
    {
        if(top==-1)
            return true;
        return false;

    }
    bool isFull()
    {
        if(top==MAX-1)
            return true;
        return false;
    }

    void push(int x)
    {
        if(isFull())
        {
            cout<<"Stack overflow\n";
        }
        else
        a[++top]=x;
    }
    int pop()
    {
        if(isEmpty())
        {
            cout<<"Stack underflow\n";
        }
        else
            return a[top--];
    }
    void display()
    {
        if(isEmpty())
        {
            cout<<"Stack underflow\n";
        }
        else
            for(int i=top;i>0;i--)
            {
                cout<<a[i];
            }
    }
};

class que
{
    stk s1,s2;
    public:
    void enq(int x)
    {
        s1.push(x);
    }
    int deq()
    {
        int x,y;
        while(!s1.isEmpty())
        {
            x=s1.pop();
            s2.push(x);
        }
        y=s2.pop();

        while(!s2.isEmpty())
        {
            x=s2.pop();
            s1.push(x);
        }

        return y;
    }
};
int main(){
    
    que q;
    int opt,ele;
    q.enq(10);
    q.enq(100);
    q.enq(220);
    cout<<"Removing element from queue:\n"<<q.deq()<<endl;
    cout<<q.deq()<<endl;
    cout<<q.deq()<<endl;
    
    return 0;
}