#include <iostream>
using namespace std;

class twostk
{
    int a[200];
    int top1,top2;
    public:
    
    twostk()
    {
        top1=-1;
        top2=200;
    }

    void push1(int x)
    {
        if(top1<top2-1)
        {
            a[++top1]=x;
        }
        else
        {
            cout<<"Stack overflow";
        }
    }

    void push2(int x)
    {
        if(top1<top2-1)
        {
            a[++top2]=x;

        }
        else
        {
            cout<<"Stack overflow";
        }

    }

    int pop1()
    {
        if(top1>=0)
        {
            int x=a[top1--];
            cout<<"Popped element is"<<x;
        }
        else
        {
            cout<<"Stack underflow";

        }

    }

    int pop2()
    {
        if(top2<200)
        {
            int x=a[top2++];
            cout<<"popped element is"<<x;
        }
        else{
            cout<<"Stack underflow";
        }

    }
};
 
int main()
{
    twostk s;
    s.push1(5);
    s.push2(10);
    s.push2(15);
    s.push1(11);
    s.push2(7);
    cout<<"Popped element from stack 1 is: ";
    cout<<s.pop1();
    s.push2(40);
    cout<<"\n popped element from stack 2 is: "<<s.pop2();
    return 0;

}

