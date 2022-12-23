#include <iostream>
using namespace std;

class stk
{
    int top;
    public:
    int a[100];
    stk()
    {
        top=-1;
    }
    void push(int);
    int pop();
    int peek();
    void display();
    int isEmpty();


};

void stk::push(int x)
{
    if(top==99)
    {
        cout<<"Stack Overflow";

    }
    else
    {
        a[++top]=x;
        cout<<x<<" Pushed into the stack\n";
    }
}

int stk::pop()
{
    if(top==-1)
    {
        cout<<"Stack underflow";
        return 0;
    }
    else{
        int x=a[top--];
        return x;
    }
}

int stk::peek()
{
    if(top==-1)
    {
        cout<<"Stack is empty";

    }
    else{
        int x=a[top];
        return x;

    }

}

int stk::isEmpty()
{
    if(top==-1)
    {
        cout<<"Stack is empty";

    }
    
}

void stk::display()
{
    if(top>=0)
    {
        cout<<"Stack elements are:";
        for(int i =top;i>=0;i--)
        {
            cout<<a[i]<<" ";
            cout<<endl;
        }
    }
    else
    {
        cout<<"Stack is empty";

    }
}


int main(){
    stk s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout<<s.pop()<<"Popped from the stack\n";
    s.display();
    cout<<"The element at the top of the stack is: "<<s.peek();
    
    return 0;
}